#include <sys/time.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "ite/itp.h"
#include "capture_s/ite_capture.h"
#include "isp/mmp_isp.h"   //for ISP
#include "ite/itv.h"       //for VideoInit()
#include "ite/ith_video.h" //for VideoInit()
#include "capture_s/capture_types.h"
#include "jpg/ite_jpg.h"
#include "ite_avienc.h"
#include "i2s/i2s.h"
#include <assert.h>
#include "user_function.h"
#include "iic/mmp_iic.h"

extern PR2000_INPUT_MODE input_mode;

static bool  do_once = true;
static pthread_t tid;
static pthread_t isp_tid;
static pthread_t jpeg_enc_tid;
static pthread_t sw_yuv_tid;
static pthread_t audio_tid;
static pthread_t avi_tid;
static bool     b_RECORDING = false;
static bool     b_RECORDING_START = false;
static bool     REC_FIRST_FRAME = false;
static bool     b_SNAPSHOT = false;
static bool     b_SNAPSHOT_START = false;
static bool     b_MOTION = false;
static bool     b_MOTION_START = true;
static bool     b_MOTION_PASS_ONCE = false;
static bool     b_MOTION_RECING = false;
static bool     record_720p_bypass = true; //wo scaling mode
static bool     record_stop = false;
static bool     record_stop_over = true;
static bool     avi_start_flag = false;
static bool     snap_stop = false;
static bool     audio_init = false;
static bool     audio_stop = false;
static char filename[50];

bool get_avi_start_flag()
{
	return avi_start_flag;
}

static int		CapSavingCount = false;
static bool	CapIsSaving = false;

uint8_t	update_rec_time = 0;	//snap_rec_show_icon
//static pthread_mutex_t  recording_mutex = PTHREAD_MUTEX_INITIALIZER;

bool stopTest;

#define CaptureDevName CFG_CAPTURE_MODULE_NAME
#define SecondCaptureDevName CFG_SECOND_CAPTURE_MODULE_NAME
#define Motion_Detection 1
#define CAP_420MODE  3
#define ERROR_DROP_COUNT 10

#define JPEG_BUF_LENGTH (256 << 10)

//ISP
#define SHORT_WAIT_UNTIL(expr)    while (!(expr)) { usleep(1000);  }
static ISP_DEVICE      gIspDev;

//REC
#define REC_FILE_NAME   "e:/rec.avi"
#define REC_FILE_WIDTH  720//800
#define REC_FILE_HEIGHT 576//480
int rec_file_range[3][2] = {{720,576},{720,488},{1280,720}};
#define REC_FILE_FPS    25
#define FRAME_TO_ENCODE 2250
#define FRAME_TO_ENCODE_MD 250


//Audio
#define SUPPORT_REC_AUDIO 1
bool SUPPORT_REC_AUDIO_S = true;

#define ADC_BUFFER_SIZE (32*1024)
static STRC_I2S_SPEC spec_adI = {0};
static uint8_t *adc_buf = NULL;


#if Motion_Detection
static uint8_t *ref_outY = NULL;
static bool     firstY = true;
static uint8_t  cnt = 0;
static bool     motion_detected = false;
static bool     motion_satrt = false;

static int drop_cnt = 0;

typedef struct MOTION_DETECTION_TAG
{
	uint32_t motion_sensitivity;
	uint8_t  motion_threshold;
	uint32_t motion_start_x;
	uint32_t motion_end_x;
	uint32_t motion_start_y;
	uint32_t motion_end_y;
	bool     motion_mask_enable;
	uint32_t motion_mask_start_x;
	uint32_t motion_mask_end_x;
	uint32_t motion_mask_start_y;
	uint32_t motion_mask_end_y;
} MOTION_DETECTION;
#endif
/*
typedef enum SEND_STATE_TAG
{
    SEND_BEGIN,
    SEND_START,
    SEND_STOP,
    SEND_TERMINATE,
} SEND_STATE;
*/
typedef void (*pfPktReleaseCb) (void *pkt);

typedef struct YUVInputPkt
{
	uint8_t  *ya;       /// address of Y decoded video buffer
	uint8_t  *ua;       /// address of U decoded video buffer
	uint8_t  *va;       /// address of V decoded video buffer
	uint32_t src_w;     /// width of decoded video buffer
	uint32_t src_h;     /// height of decoded video buffer
	uint32_t pitch_y;   /// pitch of Y
	uint32_t pitch_uv;  /// pitch of UV
	uint32_t format;    /// YUV format. see MMP_ISP_INFORMAT.
} YUVInputPkt;

typedef struct DetYUVInputPkt
{
	uint32_t	framePitchY;
	uint32_t	framePitchUV;
	uint32_t	frameWidth;
	uint32_t	frameHeight;
	uint8_t     *pYUVBuffer;
	uint32_t    YUVBufferSize;
} DetYUVInputPkt;

typedef struct SWYUVInputPkt
{
	uint32_t	frameWidth;
	uint32_t	frameHeight;
	uint8_t     *pRGBBuffer;
} SWYUVInputPkt;

typedef struct JpegInputPkt
{
	uint8_t *pInputBuffer;
	uint32_t bufferSize;
} JpegInputPkt;

typedef struct AudioInputPkt
{
	uint8_t *pInputBuffer;
	uint32_t bufferSize;
} AudioInputPkt;

typedef struct QueuePktList
{
	void* pkt;
	struct QueuePktList *next;
} QueuePktList;

typedef struct PktQueue
{
	QueuePktList *firstPkt, *lastPkt;
	int numPackets;
	int maxPackets;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	pfPktReleaseCb pfPktRelease;
} PktQueue;

static PktQueue gYUVInputQueue = { 0 };
static PktQueue gDet_YUVInputQueue = { 0 };
static PktQueue gJpegInputQueue = { 0 };
static PktQueue gAudioInputQueue = { 0 };
static PktQueue gSW_YUVInputQueue = { 0 };

static pfPktReleaseCb
_yuvInputPktRelease(
    void* pkt)
{
	YUVInputPkt *ptYUVInputPkt = (YUVInputPkt*)pkt;
	free(pkt);
}

static pfPktReleaseCb
_sw_yuvInputPktRelease(
    void* pkt)
{
	SWYUVInputPkt *ptSWYUVInputPkt = (SWYUVInputPkt*)pkt;
	if (ptSWYUVInputPkt && ptSWYUVInputPkt->pRGBBuffer)
	{
		free(ptSWYUVInputPkt->pRGBBuffer);
	}
	free(pkt);
}

static pfPktReleaseCb
_detYuvInputPktRelease(
    void* pkt)
{
	DetYUVInputPkt *ptDetYUVInputPkt = (DetYUVInputPkt*)pkt;
	if (ptDetYUVInputPkt && ptDetYUVInputPkt->pYUVBuffer && ptDetYUVInputPkt->YUVBufferSize)
	{
		free(ptDetYUVInputPkt->pYUVBuffer);
	}
	free(pkt);
}

static pfPktReleaseCb
_jpegInputPktRelease(
    void* pkt)
{
	JpegInputPkt *ptJpegInputPkt = (JpegInputPkt*)pkt;
	if (ptJpegInputPkt && ptJpegInputPkt->pInputBuffer && ptJpegInputPkt->bufferSize)
	{
		free(ptJpegInputPkt->pInputBuffer);
	}
	free(pkt);
}

static pfPktReleaseCb
_audioInputPktRelease(
    void* pkt)
{
	AudioInputPkt *ptAudioInputPkt = (AudioInputPkt*)pkt;
	if (ptAudioInputPkt && ptAudioInputPkt->pInputBuffer && ptAudioInputPkt->bufferSize)
	{
		free(ptAudioInputPkt->pInputBuffer);
	}
	free(pkt);
}


static int
_packetQueuePut(
    PktQueue *q,
    void *pkt)
{
	QueuePktList *pkt1;

	/* duplicate the packet */
	if (q->mutex)
	{
		while(q->numPackets > q->maxPackets)
		{
			printf("queue is full: cur: %u, max: %u\n", q->numPackets, q->maxPackets);
			usleep(1000*100);
		}
		pkt1 = malloc(sizeof(QueuePktList));
		if (!pkt1) return -1;
		pkt1->pkt =  pkt;
		pkt1->next = NULL;

		pthread_mutex_lock(&q->mutex);

		if (!q->lastPkt)
			q->firstPkt = pkt1;
		else
			q->lastPkt->next = pkt1;
		q->lastPkt = pkt1;
		q->numPackets++;

		/* XXX: should duplicate packet data in DV case */
		pthread_cond_signal(&q->cond);
		pthread_mutex_unlock(&q->mutex);
		return 0;
	}
	else
	{
		return -1;
	}
}

/* packet queue handling */
static void
_packetQueueInit(
    PktQueue *q,
    void* pfPktRelease,
    int maxPackets)
{
	memset(q, 0, sizeof(PktQueue));
	pthread_mutex_init(&q->mutex, NULL);
	pthread_cond_init(&q->cond, NULL);
	q->lastPkt = NULL;
	q->firstPkt = NULL;
	q->numPackets = 0;
	q->maxPackets = maxPackets;
	q->pfPktRelease = pfPktRelease;
}

static void
_packetQueueFlush(
    PktQueue *q)
{
	QueuePktList *pkt, *pkt1;
	if (q->mutex)
	{
		pthread_mutex_lock(&q->mutex);
		for (pkt = q->firstPkt; pkt != NULL; pkt = pkt1)
		{
			pkt1 = pkt->next;
			if (q->pfPktRelease)
			{
				q->pfPktRelease(pkt->pkt);
			}
			free(pkt);
		}
		q->lastPkt = NULL;
		q->firstPkt = NULL;
		q->numPackets = 0;
		pthread_mutex_unlock(&q->mutex);
	}
}

static void
_packetQueueEnd(
    PktQueue *q)
{
	if (q->mutex)
	{
		_packetQueueFlush(q);
		pthread_mutex_destroy(&q->mutex);
		pthread_cond_destroy(&q->cond);
		memset(q, 0, sizeof(PktQueue));
	}
}

static int
_packetQueueGet(
    PktQueue *q,
    void **pkt,
    int block)
{
	QueuePktList *pkt1;
	int ret;
	if (q->mutex)
	{
		pthread_mutex_lock(&q->mutex);

		for (;;)
		{
			pkt1 = q->firstPkt;
			if (pkt1)
			{
				q->firstPkt = pkt1->next;
				if (!q->firstPkt)
					q->lastPkt = NULL;
				q->numPackets--;
				*pkt = pkt1->pkt;
				free(pkt1);
				ret = 1;
				break;
			}
			else if (!block)
			{
				ret = 0;
				break;
			}
			else
			{
				pthread_cond_wait(&q->cond, &q->mutex);
			}
		}
		pthread_mutex_unlock(&q->mutex);
		return ret;
	}
	else
	{
		return -1;
	}
}

static void
VideoInit(
    void)
{
	ithVideoInit(NULL);
	itv_init();
}

static void
VideoExit(
    void)
{
	/* release dbuf & itv */
	itv_flush_dbuf();
	itv_deinit();

	/* release decoder stuff */
	printf("%s(%d)\n", __FUNCTION__, __LINE__);
	ithVideoExit();
	printf("%s(%d)\n", __FUNCTION__, __LINE__);
}

#if 0
void argb8888toyuv420(char *yuv_dst, char *argb_src, int width, int height)
{
	int line, i = 0;
	int u_pos = width * height;
	int v_pos = u_pos + u_pos/4;
	int pixel_count = 0;

	for(line = 0; line < height; line++)
	{
		if(line % 2 == 0)
		{
			for(i = 0; i < width; i+=2)
			{
				char r, g, b;
				b = argb_src[4 * pixel_count + 0];
				g = argb_src[4 * pixel_count + 1];
				r = argb_src[4 * pixel_count + 2];

				yuv_dst[pixel_count++] = ((66*r + 129*g + 25*b) >> 8) + 16;
				yuv_dst[u_pos++] = ((-38*r + -74*g + 112*b) >> 8) + 128;
				yuv_dst[v_pos++] = ((112*r + -94*g + -18*b) >> 8) + 128;

				b = argb_src[4 * pixel_count + 0];
				g = argb_src[4 * pixel_count + 1];
				r = argb_src[4 * pixel_count + 2];

				yuv_dst[pixel_count++] = ((66*r + 129*g + 25*b) >> 8) + 16;
			}
		}
		else
		{
			for(i = 0; i < width; i++)
			{
				char r, g, b;
				b = argb_src[4 * pixel_count + 0];
				g = argb_src[4 * pixel_count + 1];
				r = argb_src[4 * pixel_count + 2];

				yuv_dst[pixel_count++] = ((66*r + 129*g + 25*b) >> 8) + 16;
			}
		}
	}
}
#endif

#if 0
static void ayuv444toyuv420_c(char *yuv420_dst, char *ayuv444_src, int width, int height)
{
	int line, i = 0;
	int u_pos = width * height;
	int v_pos = u_pos + u_pos/4;
	int pixel_count = 0;

	//ithEnterCritical();
	for(line = 0; line < height; line++)
	{
		if(line % 2 == 0)
		{
			for(i = 0; i < width; i+=2)
			{
				char y, u, v;
				v = ayuv444_src[4 * pixel_count];
				u = ayuv444_src[4 * pixel_count + 1];
				y = ayuv444_src[4 * pixel_count + 2];

				yuv420_dst[pixel_count++] = y;
				yuv420_dst[u_pos++] = u;
				yuv420_dst[v_pos++] = v;

				y = ayuv444_src[4 * pixel_count + 2];

				yuv420_dst[pixel_count++] = y;
			}
		}
		else
		{
			for(i = 0; i < width; i++)
			{
				char y;
				y = ayuv444_src[4 * pixel_count + 2];
				yuv420_dst[pixel_count++] = y;
			}
		}
	}
}
#else
static void ayuv444toyuv420_c(char *yuv420_dst, char *ayuv444_src, int width, int height)
{
	uint32_t line, i = 0;
	uint32_t u_pos = width * height;
	uint32_t v_pos = u_pos + u_pos/4;
	uint32_t pixel_count = 0;
	uint32_t *src_buf, *dst_ybuf;
	uint16_t *dst_ubuf, *dst_vbuf;

	src_buf = (uint32_t *) ayuv444_src;
	dst_ybuf = (uint32_t *) yuv420_dst;
	dst_ubuf = (uint16_t *) ( yuv420_dst + u_pos);
	dst_vbuf = (uint16_t *) (yuv420_dst + v_pos);

	for(line = 0; line < height; line++)
	{
		if(line % 2 == 0)
		{
			for(i = 0; i < width; i+=4)
			{
				uint32_t y0;
				uint16_t u, v;
				uint32_t data;

				data = *(src_buf++);
				v = data & 0xFF;
				u = (data & 0xFF00) >> 8;
				//y0 = (data & 0xFF0000) >> 16;
				y0 = data >> 16;

				data = *(src_buf++);
				y0 = y0 | ((data & 0xFF0000) >> 8);

				data = *(src_buf++);
				v = v | ((data & 0xFF) << 8);
				u = u | (data & 0xFF00);
				y0 = y0 | (data & 0xFF0000);

				data = *(src_buf++);
				y0 = y0 | ((data & 0xFF0000) << 8);

				*(dst_ybuf++) = y0;
				*(dst_ubuf++) = u;
				*(dst_vbuf++) = v;
			}
		}
		else
		{
			for(i = 0; i < width; i+=4)
			{
				uint32_t y0;
				uint32_t data;

				data = *(src_buf++);
				//y0 = (data & 0xFF0000) >> 16;
				y0 = data >> 16;

				data = *(src_buf++);
				y0 = y0 | ((data & 0xFF0000) >> 8);

				data = *(src_buf++);
				y0 = y0 | (data & 0xFF0000);

				data = *(src_buf++);
				y0 = y0 | ((data & 0xFF0000) << 8);

				*(dst_ybuf++) = y0;
			}
		}
	}
}

#endif
static void *sw_yuv(void)
{
	uint32_t tick1, tick2;
	unsigned char *YUV_Buffer;

	while(b_RECORDING ||b_SNAPSHOT)
	{
		SWYUVInputPkt *SW_YUVPkt = NULL;
		if(_packetQueueGet(&gSW_YUVInputQueue, (void**) &SW_YUVPkt, 0) > 0)
		{
			YUV_Buffer = (char*) malloc (SW_YUVPkt->frameWidth * SW_YUVPkt->frameHeight * 3/2);
			//tick1 = SDL_GetTicks();
			ayuv444toyuv420(YUV_Buffer, SW_YUVPkt->pRGBBuffer, SW_YUVPkt->frameWidth, SW_YUVPkt->frameHeight);
			//tick2 = SDL_GetTicks();
			//printf("ISp=%d\n", tick2-tick1);
			{
				DetYUVInputPkt *Det_YUVPkt = (DetYUVInputPkt*) malloc(sizeof(DetYUVInputPkt));
				if (Det_YUVPkt)
				{
					Det_YUVPkt->frameWidth = SW_YUVPkt->frameWidth;
					Det_YUVPkt->frameHeight = SW_YUVPkt->frameHeight;
					Det_YUVPkt->framePitchY = SW_YUVPkt->frameWidth;
					Det_YUVPkt->framePitchUV = SW_YUVPkt->frameWidth/2;
					Det_YUVPkt->pYUVBuffer = YUV_Buffer;
					Det_YUVPkt->YUVBufferSize = SW_YUVPkt->frameWidth * SW_YUVPkt->frameHeight * 3/2;
					_packetQueuePut(&gDet_YUVInputQueue, Det_YUVPkt);
				}
			}
			_sw_yuvInputPktRelease(SW_YUVPkt);
		}
		else
			usleep(3000);
	}

	usleep(100*1000);

	//_packetQueueEnd(&gSW_YUVInputQueue);
	pthread_exit(NULL);
}

static void *Isp_process(void)
{
	//uint32_t tick1, tick2;
	//static bool do_once = true;
	YUVInputPkt *ptYUVPkt = NULL;
	unsigned char *RGB_Buffer, *YUV_Buffer;

	MMP_ISP_OUTPUT_INFO out_info  = {0};
	MMP_ISP_SHARE       isp_share = {0};

	mmpIspInitialize(&gIspDev);

	while(b_RECORDING ||b_SNAPSHOT)
	{
		if(_packetQueueGet(&gYUVInputQueue, (void**) &ptYUVPkt, 0) > 0)
		{
			//tick1 = SDL_GetTicks();
			isp_share.addrY   = (uint32_t)ptYUVPkt->ya;
			isp_share.addrU   = (uint32_t)ptYUVPkt->ua;
			isp_share.addrV   = (uint32_t)ptYUVPkt->va;
			isp_share.width   = ptYUVPkt->src_w;
			isp_share.height  = ptYUVPkt->src_h;
			isp_share.pitchY  = ptYUVPkt->pitch_y;
			isp_share.pitchUv = ptYUVPkt->pitch_uv;
			isp_share.format  = ptYUVPkt->format;

			RGB_Buffer = (char*) malloc (2*1024*1024);


			out_info.addrRGB = (uint32_t)RGB_Buffer;
#if 0
			out_info.width = REC_FILE_WIDTH;//ithLcdGetWidth();
			out_info.height = REC_FILE_HEIGHT;//ithLcdGetHeight();
			out_info.pitchRGB = REC_FILE_WIDTH * 4;//ithLcdGetPitch() * 2;
#else
			out_info.width = rec_file_range[input_mode][0];//ithLcdGetWidth();
			out_info.height = rec_file_range[input_mode][1];//ithLcdGetHeight();
			out_info.pitchRGB = rec_file_range[input_mode][0] * 4;//ithLcdGetPitch() * 2;
#endif
			out_info.format = MMP_ISP_OUT_RGB888;

			mmpIspEnable(gIspDev, MMP_ISP_DEINTERLACE);
			mmpIspSetMode(gIspDev, MMP_ISP_MODE_TRANSFORM);
			mmpIspEnable(gIspDev, MMP_ISP_DUMMY_CS);
			mmpIspSetOutputWindow(gIspDev, &out_info);
			mmpIspPlayImageProcess(gIspDev, &isp_share);
			//printf("YC: %s, %d\n", __FUNCTION__, __LINE__);
			SHORT_WAIT_UNTIL(mmpIspIsEngineIdle());
			//printf("YC: %s, %d, out_info.width = %d, out_info.height = %d\n", __FUNCTION__, __LINE__, out_info.width, out_info.height);
#if 0
			if(do_once)
			{
				do_once = false;
				FILE *fp;
				fp = fopen("A:/aaa.rgb", "wb");
				fwrite(RGB_Buffer, 1, out_info.width * out_info.height * 4, fp);
				fclose(fp);
			}
#endif
			{
				SWYUVInputPkt *SW_YUVPkt = (SWYUVInputPkt*) malloc(sizeof(SWYUVInputPkt));
				if (SW_YUVPkt)
				{
					SW_YUVPkt->frameWidth = out_info.width;
					SW_YUVPkt->frameHeight = out_info.height;
					SW_YUVPkt->pRGBBuffer = RGB_Buffer;
					_packetQueuePut(&gSW_YUVInputQueue, SW_YUVPkt);
				}
			}
			_yuvInputPktRelease(ptYUVPkt);
			//tick2 = SDL_GetTicks();
			//if(tick2 - tick1 > 20)
			//printf("ISP process waste %d ms\n", tick2 - tick1);
		}
		else
			usleep(3000);
	}

	usleep(100*1000);

	//_packetQueueEnd(&gYUVInputQueue);
	pthread_exit(NULL);
}

void set_montion_pass_once()
{
	b_MOTION_PASS_ONCE = true;
}

void clear_montion_start()
{
	b_MOTION_START = false;
}

void *user_snap(int mode)
{
	char* file_name = NULL;
//	if(storageCurrType != STORAGE_SD)
//		return;
	if(mode == 1 && !b_SNAPSHOT )
	{
		file_name = ImageMemoRecord();
		memset(filename,'\0',sizeof(filename));
		strcpy(filename,file_name);
		printf("Image-------->%s\n",filename);
		b_SNAPSHOT_START= true;
	}
	else if(mode == 2 && storageCurrType == STORAGE_SD)
	{
		if(!b_RECORDING)
		{
			if(record_stop_over)
			{
				record_stop_over = false;
				file_name = VideoMemoRecord();
				memset(filename,'\0',sizeof(filename));
				strcpy(filename,file_name);
				printf("Video-------->%s\n",filename);
				user_amp_on();
				b_RECORDING_START = true;
			}
		}
		else
		{
			printf("Video-------->stop\n");
			rec_start_time = 0;
		}
	}
	return ;
}



static void *Jpeg_Enc(void)
{
	//uint32_t tick1, tick2;
//	DetYUVInputPkt *ptYUVPkt = NULL;
	unsigned char *jpegStream;

	HJPG            *pHJpeg        = 0;
	JPG_INIT_PARAM  initParam      = {0};
	JPG_STREAM_INFO inStreamInfo   = {0};
	JPG_STREAM_INFO outStreamInfo  = {0};
	JPG_BUF_INFO    entropyBufInfo = {0};
	JPG_USER_INFO   jpgUserInfo    = {0};
	uint32_t        jpgEncSize     = 0;

	if(b_SNAPSHOT)
	{
		show_snap_rec_icon = sanp_display;
	}

	while(b_RECORDING || b_SNAPSHOT)
	{
		jpegStream = NULL;
		if(input_mode != PR2000_INPUT_YPBPR)
		{
			DetYUVInputPkt *ptYUVPkt = NULL;
			if(_packetQueueGet(&gDet_YUVInputQueue, (void**) &ptYUVPkt, 0) > 0)
			{
				unsigned char *pAddr_y = 0, *pAddr_u = 0, *pAddr_v = 0;

				pAddr_y = ptYUVPkt->pYUVBuffer;
				pAddr_u = ptYUVPkt->pYUVBuffer + (ptYUVPkt->framePitchY * ptYUVPkt->frameHeight);
				pAddr_v = pAddr_u + (ptYUVPkt->framePitchUV * ptYUVPkt->frameHeight/2);

				initParam.codecType = JPG_CODEC_ENC_JPG;
				initParam.outColorSpace = JPG_COLOR_SPACE_YUV420;
				initParam.width         = ptYUVPkt->frameWidth;
				initParam.height        = ptYUVPkt->frameHeight;
				initParam.encQuality    = 70;//85;
				iteJpg_CreateHandle(&pHJpeg, &initParam, 0);
				inStreamInfo.streamIOType         = JPG_STREAM_IO_READ;
				inStreamInfo.streamType           = JPG_STREAM_MEM;
				// Y
				inStreamInfo.jstream.mem[0].pAddr = (uint8_t *)pAddr_y; //YUV_Save;
				inStreamInfo.jstream.mem[0].pitch = ptYUVPkt->framePitchY;      // src_w_out;

				// U
				inStreamInfo.jstream.mem[1].pAddr = (uint8_t *)pAddr_u; //(inStreamInfo.jstream.mem[0].pAddr+H264_pitch_y*src_h_out);
				inStreamInfo.jstream.mem[1].pitch = ptYUVPkt->framePitchUV;     //src_w_out/2;

				// V
				inStreamInfo.jstream.mem[2].pAddr = (uint8_t *)pAddr_v; //(inStreamInfo.jstream.mem[1].pAddr+H264_pitch_y*src_h_out);
				inStreamInfo.jstream.mem[2].pitch = ptYUVPkt->framePitchUV;     //src_w_out/2;

				inStreamInfo.validCompCnt         = 3;


				outStreamInfo.streamIOType          = JPG_STREAM_IO_WRITE;
				outStreamInfo.streamType            = JPG_STREAM_MEM;

				if (b_SNAPSHOT )
				{
					outStreamInfo.streamType   = JPG_STREAM_FILE;
					outStreamInfo.jstream.path = (void *)filename;
					outStreamInfo.jpg_reset_stream_info = 0;
				}
				else
				{
					jpegStream = (char*) malloc (sizeof(char)*JPEG_BUF_LENGTH);
					outStreamInfo.jpg_reset_stream_info = 0;

					outStreamInfo.jstream.mem[0].pAddr  = jpegStream;
					outStreamInfo.jstream.mem[0].pitch  = ptYUVPkt->frameWidth;
					outStreamInfo.jstream.mem[0].length = JPEG_BUF_LENGTH;

					outStreamInfo.validCompCnt          = 1;
				}
				iteJpg_SetStreamInfo(pHJpeg, &inStreamInfo, &outStreamInfo, 0);
				iteJpg_GetStatus(pHJpeg, &jpgUserInfo, 0);

				iteJpg_Setup(pHJpeg, 0);

				iteJpg_Process(pHJpeg, &entropyBufInfo, &jpgEncSize, 0);

				iteJpg_GetStatus(pHJpeg, &jpgUserInfo, 0);
				//printf("\n\tresult = %d, encode size = %f KB\n", jpgUserInfo.status, (float)jpgEncSize / 1024);

				iteJpg_DestroyHandle(&pHJpeg, 0);
				//pthread_mutex_unlock(&recording_mutex);
				if(b_RECORDING)
				{
					JpegInputPkt *jpegPkt = (JpegInputPkt*) malloc(sizeof(JpegInputPkt));
					if (jpegPkt)
					{
						jpegPkt->pInputBuffer = jpegStream;
						jpegPkt->bufferSize = jpgEncSize + 4;
						_packetQueuePut(&gJpegInputQueue, jpegPkt);
					}
				}
				else
				{
					if(jpegStream)
						free(jpegStream);
				}

				_detYuvInputPktRelease(ptYUVPkt);
				if(b_SNAPSHOT)
				{
					ImageMemoRecEnd();
					b_SNAPSHOT = false;
					show_snap_rec_icon = icon_clear;
				}
			}
			else
				usleep(5000);
		}
		else
		{
			YUVInputPkt *ptYUVPkt = NULL;
			if(_packetQueueGet(&gDet_YUVInputQueue, (void**) &ptYUVPkt, 0) > 0)
			{
				unsigned char *pAddr_y = 0, *pAddr_u = 0, *pAddr_v = 0;

				pAddr_y = ptYUVPkt->ya;
				pAddr_u = ptYUVPkt->ua;
				pAddr_v = ptYUVPkt->va;

				initParam.codecType = JPG_CODEC_ENC_JPG;
				initParam.outColorSpace = JPG_COLOR_SPACE_YUV420;

				initParam.width         = ptYUVPkt->src_w;
				initParam.height        = ptYUVPkt->src_h;

				initParam.encQuality    = 70;//85;
				iteJpg_CreateHandle(&pHJpeg, &initParam, 0);
				inStreamInfo.streamIOType         = JPG_STREAM_IO_READ;
				inStreamInfo.streamType           = JPG_STREAM_MEM;
				// Y
				inStreamInfo.jstream.mem[0].pAddr = (uint8_t *)pAddr_y; //YUV_Save;
				inStreamInfo.jstream.mem[0].pitch = ptYUVPkt->pitch_y;// src_w_out;

				// U
				inStreamInfo.jstream.mem[1].pAddr = (uint8_t *)pAddr_u; //(inStreamInfo.jstream.mem[0].pAddr+H264_pitch_y*src_h_out);
				inStreamInfo.jstream.mem[1].pitch = ptYUVPkt->pitch_uv;     //src_w_out/2;

				// V
				inStreamInfo.jstream.mem[2].pAddr = (uint8_t *)pAddr_v; //(inStreamInfo.jstream.mem[1].pAddr+H264_pitch_y*src_h_out);
				inStreamInfo.jstream.mem[2].pitch = ptYUVPkt->pitch_uv;     //src_w_out/2;

				inStreamInfo.validCompCnt         = 3;


				outStreamInfo.streamIOType          = JPG_STREAM_IO_WRITE;
				outStreamInfo.streamType            = JPG_STREAM_MEM;

				if (b_SNAPSHOT||REC_FIRST_FRAME)
				{
					outStreamInfo.streamType   = JPG_STREAM_FILE;
					outStreamInfo.jstream.path = (void *)filename;
					outStreamInfo.jpg_reset_stream_info = 0;
				}
				else
				{
					jpegStream = (char*) malloc (sizeof(char)*JPEG_BUF_LENGTH);
					outStreamInfo.jpg_reset_stream_info = 0;

					outStreamInfo.jstream.mem[0].pAddr  = jpegStream;
					outStreamInfo.jstream.mem[0].pitch  = ptYUVPkt->src_w;
					outStreamInfo.jstream.mem[0].length = JPEG_BUF_LENGTH;

					outStreamInfo.validCompCnt          = 1;
				}
				iteJpg_SetStreamInfo(pHJpeg, &inStreamInfo, &outStreamInfo, 0);
				iteJpg_GetStatus(pHJpeg, &jpgUserInfo, 0);

				iteJpg_Setup(pHJpeg, 0);

				iteJpg_Process(pHJpeg, &entropyBufInfo, &jpgEncSize, 0);

				iteJpg_GetStatus(pHJpeg, &jpgUserInfo, 0);

				iteJpg_DestroyHandle(&pHJpeg, 0);
				if(b_RECORDING && (REC_FIRST_FRAME == false))
				{
					JpegInputPkt *jpegPkt = (JpegInputPkt*) malloc(sizeof(JpegInputPkt));
					if (jpegPkt)
					{
						jpegPkt->pInputBuffer = jpegStream;
						jpegPkt->bufferSize = jpgEncSize + 4;
						_packetQueuePut(&gJpegInputQueue, jpegPkt);
					}
				}
				else
				{
					if(jpegStream)
						free(jpegStream);
				}

				_yuvInputPktRelease(ptYUVPkt);
				REC_FIRST_FRAME = false;

				if(b_SNAPSHOT)
				{
					printf("b_SNAPSHOT............stop...................\n");
					//ioctl(ITP_DEVICE_NOR, ITP_IOCTL_FLUSH, NULL);
					CapSave();
					b_SNAPSHOT = false;
					snap_stop = true;
					//usleep(500*1000);
					photo_icon_start();
					AudioResumeKeySound();						//�ָ�������
					//jpeg_end();
					if(b_MOTION_RECING)
					{
						b_MOTION_RECING = false;
						montion_snap_start();
					}
				}
			}
			else
			{
				//printf("------------------->sleep\n");
				usleep(5000);
			}
		}
	}

	//usleep(100*1000);
	//_packetQueueEnd(&gDet_YUVInputQueue);
	pthread_exit(NULL);
}

static void initAD(void)
{
	/* init ADC */
	if(adc_buf==NULL) adc_buf = (uint8_t*)malloc(ADC_BUFFER_SIZE);
	memset((uint8_t*) adc_buf, 0, ADC_BUFFER_SIZE);
	memset((void*)&spec_adI, 0, sizeof(STRC_I2S_SPEC));
	spec_adI.channels                   = 1;
	spec_adI.sample_rate                = 8000;
	spec_adI.buffer_size                = ADC_BUFFER_SIZE;
	spec_adI.is_big_endian              = 0;
	spec_adI.base_i2s                   = (uint8_t*) adc_buf;
	spec_adI.sample_size                = 16;
	spec_adI.record_mode                = 1;
	spec_adI.from_LineIN                = 0;
	spec_adI.from_MIC_IN                = 1;
	i2s_init_ADC(&spec_adI);
	i2s_pause_ADC(1);
	audio_init = true;
}

static void deinitAD(void)
{
	i2s_deinit_ADC();
}

#if 1//(SUPPORT_REC_AUDIO)
static void *GetAudioRawDataFromADC(void *arg)
{
	if(audio_init == false)
	{
		initAD();
		i2s_ADC_set_direct_volstep(80);
	}
	i2s_pause_ADC(0);

	while(b_RECORDING)
	{
		int bsize = 0;
		int sizecount = 0;
		uint8_t* audio_data = NULL;
		audio_data = (uint8_t*)malloc(16000);

		usleep(980*1000);

		while(sizecount < 16000)
		{
			uint32_t AD_r = I2S_AD32_GET_RP();//9850
			uint32_t AD_w = I2S_AD32_GET_WP();//9850

			if (AD_r <= AD_w)
			{
				bsize = AD_w - AD_r;
				if (sizecount + bsize > 16000)
					bsize = 16000 - sizecount;

				if (bsize)
				{
					ithInvalidateDCacheRange(adc_buf + AD_r, bsize);
					memcpy(audio_data + sizecount, adc_buf + AD_r, bsize);
					AD_r += bsize;
					I2S_AD32_SET_RP(AD_r);
					sizecount += bsize;
				}
			}
			else
			{
				// AD_r > AD_w
				bsize = (ADC_BUFFER_SIZE - AD_r) + AD_w;
				if (sizecount + bsize > 16000)
					bsize = 16000 - sizecount;

				if (bsize)
				{
					//printf("AD_r %u, AD_w %u bsize %u \n", AD_r, AD_w, bsize );
					uint32_t szsec0, szsec1;
					szsec0 = ADC_BUFFER_SIZE - AD_r;
					if(bsize < szsec0)
						szsec0 = bsize;
					szsec1 = bsize - szsec0;

					ithInvalidateDCacheRange(adc_buf + AD_r, szsec0);
					memcpy(audio_data + sizecount, adc_buf + AD_r, szsec0);
					if(szsec1)
					{
						ithInvalidateDCacheRange(adc_buf, szsec1);
						memcpy(audio_data + sizecount + szsec0, adc_buf, szsec1);
					}

					if(szsec1)
						AD_r = szsec1;
					else
						AD_r += szsec0;
					I2S_AD32_SET_RP(AD_r);

					sizecount += bsize;
				}
			}
			usleep(10000);
		}

		//put into _packetqueue
		AudioInputPkt *audioPkt = (AudioInputPkt*) malloc(sizeof(AudioInputPkt));
		if (audioPkt)
		{
			audioPkt->pInputBuffer = audio_data;
			audioPkt->bufferSize = sizecount;
			_packetQueuePut(&gAudioInputQueue, audioPkt);
		}
		//usleep(600*1000);
	}
	printf("GetAudioRawDataFromADC--------------------over\n");
	i2s_pause_ADC(1);
	audio_stop = true;
	pthread_exit(NULL);

}
#endif

static void *PackageMjpegToAVI(void *arg)
{
	//uint32_t tick1, tick2 = 0;
	JpegInputPkt *ptJpegPkt = NULL;
	struct ite_avi_t *avi;
	int enc_count = 0;
	bool md_avi = false;

	AudioInputPkt *ptAudioPkt = NULL;
	struct ite_avi_audio_t auds;
	auds.bits = 16;
	auds.channels = 1;
	auds.samples_per_second = 8000;
	
	if(SUPPORT_REC_AUDIO_S)
		avi = ite_avi_open(filename, rec_file_range[input_mode][0],  rec_file_range[input_mode][1], "MJPG", REC_FILE_FPS, &auds);
	else
		avi = ite_avi_open(filename, rec_file_range[input_mode][0],  rec_file_range[input_mode][1], "MJPG", REC_FILE_FPS, NULL);

	//if(!avi)
	{
	//	b_RECORDING = false;
	//	motion_detected = false;
	}
	//else
	{
		printf("Encode to AVI Start.\n");
		avi_start_flag = true;
		if(b_MOTION_RECING)
			md_avi = true;
		show_snap_rec_icon = rec_display;
		rec_start_time = SDL_GetTicks();
		while(1)
		{
			if(_packetQueueGet(&gJpegInputQueue, (void**) &ptJpegPkt, 0) > 0)
			{
				ite_avi_add_frame(avi, ptJpegPkt->pInputBuffer, ptJpegPkt->bufferSize);
				_jpegInputPktRelease(ptJpegPkt);

				if(SUPPORT_REC_AUDIO_S)
				{
					if(enc_count && (enc_count+1)%REC_FILE_FPS == 0)
					{
						while(1)
						{
							if (_packetQueueGet(&gAudioInputQueue, (void**) &ptAudioPkt, 0) > 0)
							{
								ite_avi_add_audio(avi, ptAudioPkt->pInputBuffer, ptAudioPkt->bufferSize);
								_audioInputPktRelease(ptAudioPkt);
								break;
							}
							else
							{
							//	printf("wait 1 ms\n");
								usleep(1000);
							}
						}
					}
				}
				enc_count++;
				if(md_avi)
				{
					if(enc_count == FRAME_TO_ENCODE_MD || rec_start_time == 0)
					{
						printf("rec_start_time---------------->0\n");
						led_blink_1s_end();
						md_avi = false;
						b_RECORDING = false;
						break;
					}
				}
				else
				{
					if(enc_count == FRAME_TO_ENCODE || rec_start_time == 0)
					{
						printf("rec_start_time---------------->0\n");
						b_RECORDING = false;
						break;
					}
				}
			}
			else
			{
				usleep(1000);
			}
		}
		ite_avi_close(avi);
		printf("Encode to AVI Finish.\n");
		user_video_time_check();
		AudioResumeKeySound();						//�ָ�������
		show_snap_rec_icon = icon_clear;
	}
	usleep(100*1000);
	if(input_mode != PR2000_INPUT_YPBPR)
	{
		_packetQueueEnd(&gYUVInputQueue);
		_packetQueueEnd(&gSW_YUVInputQueue);
	}
	_packetQueueEnd(&gDet_YUVInputQueue);
	_packetQueueEnd(&gJpegInputQueue);
	record_stop = true;
	if(!cur_talk_ing)
		user_amp_off();
//	avi_end();
	if(b_MOTION_RECING)
	{
		b_MOTION_RECING = false;
		if(montion_enable)
			montion_snap_start();
	}
	pthread_exit(NULL);
}


#if Motion_Detection
static uint8_t*
Check_Motion_Init(
    void)
{
	return malloc(CFG_CAPTURE_HEIGHT*CFG_CAPTURE_WIDTH);
}

static void
Check_Motion_Terminate(
    uint8_t* y_data)
{
	free(y_data);
}

static bool
Check_Motion_Detection(
    MOTION_DETECTION   motion_info,
    uint8_t* ref_data,
    uint8_t* y_data)
{
	uint32_t i, j, k, pi_diff = 0, cell_diff = 0;
	if(firstY == false)
	{
		for(i = motion_info.motion_start_y; i < motion_info.motion_end_y; i+=8)
		{
			for(j = motion_info.motion_start_x; j < motion_info.motion_end_x; j++)
			{
				if(motion_info.motion_mask_enable && (j >= motion_info.motion_mask_start_x) && (j <= motion_info.motion_mask_end_x) && (i >= motion_info.motion_mask_start_y) && (i <= motion_info.motion_mask_end_y))
					continue;
				for(k = i; k < i+8; k++)
				{
					if(ref_data[CFG_CAPTURE_HEIGHT*k+j] - y_data[CFG_CAPTURE_HEIGHT*k+j] > motion_info.motion_threshold)
						pi_diff++;
				}
				if(!(j%8))
				{
					if(pi_diff > 8)
						cell_diff++;
					pi_diff = 0;
				}
			}
		}
		printf("y diff=%d\n", cell_diff);
	}
	memcpy(ref_data, y_data, CFG_CAPTURE_HEIGHT*CFG_CAPTURE_WIDTH);
	firstY = false;

	if(cell_diff > motion_info.motion_sensitivity)
		return true;
	else
		return false;
}
#endif

void montion_start_again()
{
	b_MOTION_START = true;
}
bool get_record_stop_over()
{
	return record_stop_over;
}
void set_motion_satrt()
{
	motion_satrt = true;
}
void jpeg_end()
{
	if(snap_stop)
	{
		snap_stop = false;
		printf("snap_stop!\r\n");
		_packetQueueEnd(&gDet_YUVInputQueue);
		if(jpeg_enc_tid)
		{
			pthread_join(jpeg_enc_tid, NULL);
			jpeg_enc_tid = 0;
			printf("pthread_join(jpeg_enc_tid, NULL)\r\n");
		}
	}
}

void avi_end()
{
	if(record_stop == true)
	{
		printf("record_stop!\r\n");
		record_stop = false;
		if(isp_tid)
		{
			pthread_join(isp_tid, NULL);
			isp_tid = 0;
			printf("pthread_join(isp_tid, NULL)\r\n");
		}
		if(sw_yuv_tid)
		{
			pthread_join(sw_yuv_tid, NULL);
			sw_yuv_tid = 0;
			printf("pthread_join(sw_yuv_tid, NULL)\r\n");
		}
		if(avi_tid)
		{
			pthread_join(avi_tid, NULL);
			avi_tid = 0;
			printf("pthread_join(avi_tid, NULL)\r\n");
		}
		if(jpeg_enc_tid)
		{
			pthread_join(jpeg_enc_tid, NULL);
			jpeg_enc_tid = 0;
			printf("pthread_join(jpeg_enc_tid, NULL)\r\n");
		}
		if(SUPPORT_REC_AUDIO_S)
		{
			if(audio_tid)
			{
				while(audio_stop == false)
					usleep(1000);
				_packetQueueEnd(&gAudioInputQueue);
				pthread_join(audio_tid, NULL);
				audio_tid = 0;
				audio_stop = false;
				printf("pthread_join(audio_tid, NULL)\r\n");
			}
		}
		if(!get_auto_start_ing())
			clear_mon_rec_ing();
		
		SUPPORT_REC_AUDIO_S = true;
		avi_start_flag = false;
		record_stop_over = true;
		deinitAD();
		audio_init = false;
	}
}
void SettingISPAnd_FilpLCD(
    void)
{
	static int         New_state   = 0;
	static int         Old_state   = 0;
	static int         state_count = 0;
	static int         cap_idx     = 0;
	uint8_t            *dbuf       = NULL;
	ITV_DBUF_PROPERTY  dbufprop    = {0};
	ITE_CAP_VIDEO_INFO outdata     = {0};
	unsigned char *YUVRawData;
	int YUVRawData_Size = 0;

	ithCaptureGetNewFrame(&outdata);
#if Motion_Detection
	if(++cnt > 3)
	{
		MOTION_DETECTION   motion_info;

		
		motion_info.motion_threshold = (theConfig.mdsensitive + 1)*20;		//�����ֵ  ����--���ƶ�
		motion_info.motion_sensitivity = 20;								//���ݷֿ�
		motion_info.motion_start_x = 0;									//�������
		motion_info.motion_end_x = 1280;
		motion_info.motion_start_y = 0;
		motion_info.motion_end_y = 720;
		motion_info.motion_mask_enable = false;							//���������
		motion_info.motion_mask_start_x = 320;
		motion_info.motion_mask_end_x =960;
		motion_info.motion_mask_start_y = 180;
		motion_info.motion_mask_end_y = 540;
		
		if(b_MOTION_START)
		{
			if(ref_outY && !b_RECORDING && !b_SNAPSHOT)
			{
				b_MOTION = Check_Motion_Detection(motion_info, ref_outY, outdata.DisplayAddrY);
				if(b_MOTION)
				{
					b_MOTION  = false;
					if(b_MOTION_PASS_ONCE)
						b_MOTION_PASS_ONCE = false;
					else
					{
						//backlight_on();
						b_MOTION_START = false;
						b_MOTION_RECING = true;
						if(StorageGetCurrType() == STORAGE_SD)
						{
							if(theConfig.mdsave)
								led_blink_1s_start();
							user_snap(theConfig.mdsave+1);
						}
						else
							user_snap(1);
					}
				}
			}
			else
				printf("motion check buffer invalid!\n");
		}
		cnt = 0;
	}
#endif
	dbuf = itv_get_dbuf_anchor();
	if (dbuf == NULL)
		return;

	if(outdata.IsInterlaced)
		itv_enable_isp_feature(MMP_ISP_DEINTERLACE);
	
	avi_end();
	jpeg_end();

	if(b_RECORDING_START)
	{
		if(cur_page == page_cctv)
			SUPPORT_REC_AUDIO_S = false;
		AudioPauseKeySound();		//�رհ�����
		//REC_FIRST_FRAME = true;
		b_RECORDING_START = false;
		b_RECORDING = true;

		if(input_mode != PR2000_INPUT_YPBPR)
		{
			_packetQueueInit(&gYUVInputQueue, _yuvInputPktRelease, 50);
			pthread_create(&isp_tid, NULL, Isp_process, NULL);
			_packetQueueInit(&gSW_YUVInputQueue, _sw_yuvInputPktRelease, 50);
			pthread_create(&sw_yuv_tid, NULL, sw_yuv, NULL);
		}
		_packetQueueInit(&gJpegInputQueue, _jpegInputPktRelease, 50);
		pthread_create(&avi_tid, NULL, PackageMjpegToAVI, NULL);

		if(input_mode != PR2000_INPUT_YPBPR)
			_packetQueueInit(&gDet_YUVInputQueue, _detYuvInputPktRelease, 50);
		else
			_packetQueueInit(&gDet_YUVInputQueue, _yuvInputPktRelease, 50);
		pthread_create(&jpeg_enc_tid, NULL, Jpeg_Enc, NULL);

		if(SUPPORT_REC_AUDIO_S)
		{
			_packetQueueInit(&gAudioInputQueue, _audioInputPktRelease, 50);
			pthread_create(&audio_tid, NULL, GetAudioRawDataFromADC, NULL);
		}
	}

	if(b_SNAPSHOT_START)
	{
		b_SNAPSHOT_START = false;
		b_SNAPSHOT = true;
		printf("init_snapshot.................................\n");

		if(0)//input_mode != PR2000_INPUT_YPBPR)
		{
			_packetQueueInit(&gYUVInputQueue, _yuvInputPktRelease, 50);
			pthread_create(&isp_tid, NULL, Isp_process, NULL);
		}
		_packetQueueInit(&gDet_YUVInputQueue, _yuvInputPktRelease, 50);
		pthread_create(&jpeg_enc_tid, NULL, Jpeg_Enc, NULL);
	}

	if(b_RECORDING||b_SNAPSHOT)
	{
		YUVInputPkt *InPkt = (YUVInputPkt*) malloc(sizeof(YUVInputPkt));
		if (InPkt)
		{
			InPkt->src_w    = outdata.OutWidth;
			InPkt->src_h    = outdata.OutHeight;
			InPkt->pitch_y  = outdata.PitchY;
			InPkt->pitch_uv = outdata.PitchUV;
			InPkt->format   = MMP_ISP_IN_YUV420;
			InPkt->ya       = outdata.DisplayAddrY;
			InPkt->ua       = outdata.DisplayAddrU;
			InPkt->va       = outdata.DisplayAddrV;

			if(input_mode != PR2000_INPUT_YPBPR)
				_packetQueuePut(&gYUVInputQueue, InPkt);
			else
				_packetQueuePut(&gDet_YUVInputQueue, InPkt);
		}
	}

	dbufprop.src_w    = outdata.OutWidth;
	dbufprop.src_h    = outdata.OutHeight;
	dbufprop.pitch_y  = outdata.PitchY;
	dbufprop.pitch_uv = outdata.PitchUV;
	dbufprop.format   = MMP_ISP_IN_YUV420;
	dbufprop.ya       = outdata.DisplayAddrY;
	dbufprop.ua       = outdata.DisplayAddrU;
	dbufprop.va       = outdata.DisplayAddrV;

	//printf("dbufprop.ya=0x%x,dbufprop.ua=0x%x,dbufprop.va=0x%x,dbufprop.src_w=%d,dbufprop.src_h=%d,dbufprop.pitch_y=%d,dbufprop.pitch_uv=%d\n",dbufprop.ya,dbufprop.ua,dbufprop.va,dbufprop.src_w,dbufprop.src_h,dbufprop.pitch_y,dbufprop.pitch_uv);
	itv_update_dbuf_anchor(&dbufprop);

	return;
}

#ifndef WIN32
static void* DrawVideoSurface(void* arg)
{
	ITUSurface* lcdSurf;
	lcdSurf = ituGetDisplaySurface();

	while(!stopTest)
	{
		ituDrawVideoSurface(lcdSurf, 0, 0, ithLcdGetWidth(), ithLcdGetHeight());
		ituFlip(lcdSurf);
		usleep(20000);
	}
	pthread_exit(NULL);
}
#endif

SEND_STATE          gState = SEND_IDLE;
bool Capture_state= false;
void *signal_control(void *arg)
{
	CaptureModuleDriver IrSensor;

	while(1)
	{
		if(Capture_state)
			usleep(10);
		else
			usleep(20*1000);
			
		if(sure_PR2000_lock())
		{
			switch (gState)
			{
			case SEND_BEGIN:
				printf("signal_control_begin...............................\n");
				Capture_state = true;
				if(ref_outY == NULL && montion_enable)
					ref_outY = Check_Motion_Init();
				itv_set_pb_mode(1);

				IrSensor = (CaptureModuleDriver)CaptureModuleDriver_GetDevice(CaptureDevName);
				ithCaptureSetModule(IrSensor);

				ithCapInitialize();
				ithCapSetMode(CAP_420MODE);

				//	IrSensor = (CaptureModuleDriver)CaptureModuleDriver_GetDevice(CaptureDevName);
				//	ithCaptureSetModule(IrSensor);

				printf("ith9850CaptureRun\n");
				ithCapFire();
				black_wind_start();
				gState = SEND_START;
				break;

			case SEND_START:
				//printf("signal_control_start...............................\n");
				if(Capture_state == false)
				{
					gState = SEND_BEGIN;
					break;
				}
				SettingISPAnd_FilpLCD();
				break;

			case SEND_STOP:
STOP:
				printf("signal_control_stop_start-----------------\n");
				test_tick = SDL_GetTicks();
				if(Capture_state)
				{
					ithCapTerminate();
					if(ref_outY)
					{
						Check_Motion_Terminate(ref_outY);
						ref_outY = NULL;
					}
					itv_stop_vidSurf_anchor();
					itv_flush_dbuf();
					itv_set_pb_mode(0);
				}
				gState = SEND_IDLE;
				Capture_state = false;
				//   deinitAD();
				//     audio_init = false;
				printf("signal_control_stop_over...............................%d\n",SDL_GetTicks()-test_tick);
				break;
			case SEND_IDLE:
				//printf("---------->=====================\n");
				break;
			}
		}
		else
		{
			if(rec_start_time)
			{
				rec_start_time = 0;
				//avi_end();
			}
			avi_end();
			if(Capture_state)
			{
				ithCapTerminate();
				if(ref_outY)
				{
					Check_Motion_Terminate(ref_outY);
					ref_outY = NULL;
				}
				itv_stop_vidSurf_anchor();
				itv_flush_dbuf();
				itv_set_pb_mode(0);
				Capture_state = false;
			}
			if(gState == SEND_START)
			{
				gState = SEND_BEGIN;
			}
		}

	}
	return NULL;
}

void user_signal_control_init()
{
	pthread_t signal_control_p;			//�߳�ID
	pthread_attr_t signal_control_pat;
	pthread_attr_init(&signal_control_p);
	pthread_attr_setdetachstate(&signal_control_pat, PTHREAD_CREATE_DETACHED);
	pthread_create(&signal_control_p,NULL, signal_control, NULL);
}

static void* CapSaveTask(void* arg)
{
	int savingCount;

	CapIsSaving = true;

	do
	{
		savingCount = CapSavingCount;
		ioctl(ITP_DEVICE_NOR, ITP_IOCTL_FLUSH, NULL);
	}
	while (savingCount != CapSavingCount);
	
	CapSavingCount = 0;
	CapIsSaving = false;

	return NULL;
}

void CapSave(void)
{
	pthread_t task;
	pthread_attr_t attr;

	CapSavingCount++;

	if (CapIsSaving)
		return;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&task, &attr, CapSaveTask, NULL);
}

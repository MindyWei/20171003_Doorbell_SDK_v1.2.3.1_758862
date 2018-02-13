#include <sys/time.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "test_capture.h"
#include "isp/mmp_isp.h"   //for ISP

#define SHORT_WAIT_UNTIL(expr)    while (!(expr)) { usleep(1000);  }
static ISP_DEVICE      gIspDev;

extern PktQueue gDet_YUVInputQueue;
extern PktQueue gYUVInputQueue;
extern bool b_RECORDING;
extern bool     b_SNAPSHOT;

extern pfPktReleaseCb _yuvInputPktRelease(void* pkt);

#if 0
static void ayuv444toyuv420_c(char *yuv420_dst, char *ayuv444_src, int width, int height)
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

#if(Motion_Detection)
void *Isp_process(void)
{
    uint32_t tick1, tick2;
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

			RGB_Buffer = (char*) malloc (4*1024*1024);

            out_info.addrRGB = (uint32_t)RGB_Buffer;
            out_info.width = REC_FILE_WIDTH;//ithLcdGetWidth();
            out_info.height = REC_FILE_HEIGHT;//ithLcdGetHeight();
            out_info.pitchRGB = REC_FILE_WIDTH * 4;//ithLcdGetPitch() * 2;
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

            YUV_Buffer = (char*) malloc (out_info.width * out_info.height * 3/2);
            tick1 = SDL_GetTicks();
            ayuv444toyuv420(YUV_Buffer, RGB_Buffer, out_info.width, out_info.height);
            tick2 = SDL_GetTicks();
            printf("ISp interval=%d\n", tick2-tick1);
            {
                DetYUVInputPkt *Det_YUVPkt = (DetYUVInputPkt*) malloc(sizeof(DetYUVInputPkt));
                if (Det_YUVPkt)
                {
                    Det_YUVPkt->frameWidth = out_info.width;
                    Det_YUVPkt->frameHeight = out_info.height;
                    Det_YUVPkt->framePitchY = out_info.width;
                    Det_YUVPkt->framePitchUV = out_info.width/2;
                    Det_YUVPkt->pYUVBuffer = YUV_Buffer;
                    Det_YUVPkt->YUVBufferSize = out_info.width * out_info.height * 3/2;
                    _packetQueuePut(&gDet_YUVInputQueue, Det_YUVPkt);
                }
            }            
            _yuvInputPktRelease(ptYUVPkt);
            free(RGB_Buffer);
            //tick2 = SDL_GetTicks();
            //if(tick2 - tick1 > 20)
                //printf("ISP process waste %d ms\n", tick2 - tick1);
        }
        else
            usleep(3000);
    }

    usleep(100*1000);
    
    _packetQueueEnd(&gYUVInputQueue);
    pthread_exit(NULL);
}
#endif


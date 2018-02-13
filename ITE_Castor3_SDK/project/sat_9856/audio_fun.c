#include "audio_fun.h"

	unsigned int total_time_voice = 0;
	char total_time_str[32];

// MPEG       layer		采样率
int  M_L_W[4][4][16] = {


	{	// MPEG2.5
		{0},
		{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,0},			// layer 3
		{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,0},			// layer 2
		{0,32,48,56,64,80,96,112,128,144,160,176,192,224,256,0},		// layer 1
	},
	{
		0	
	},

	{	// MPEG2
		{0},
		{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,0},			// layer 3
		{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,0},			// layer 2
		{0,32,48,56,64,80,96,112,128,144,160,176,192,224,256,0},		// layer 1
	},
	{	// MPEG1
		{0},
		{0,32,40,48,56,64,80,96,112,128,160,192,224,256,320,0},		// layer 3
		{0,32,48,56,64,80,96,112,128,160,192,224,256,320,384,0},		// layer 2
		{0,32,64,96,128,160,192,224,256,288,320,352,384,416,448,0},	// layer 1	
	},
};




void  user_get_voice_total_time(int nTagSize,uint32_t nFileSize,void *fp)
{

	unsigned char  file_head[4];
	unsigned char  xing_head[4];
	unsigned char  total_frame[4];
	unsigned char  cur_mpeg;	//版本
	unsigned char  cur_layer;		//层	
	unsigned char  cur_bit_hz;	//位率
	unsigned int  total_time;
	unsigned int  total_f;
	
	
	fseek(fp, nTagSize+10, SEEK_SET);
	fread(&file_head, 1, 4, fp);
	fseek(fp, 32, SEEK_CUR);
	fread(&xing_head, 1, 4, fp);
	if(xing_head[0] == 0x58&&xing_head[1] == 0x69&&xing_head[2] == 0x6E&&xing_head[3] == 0x67)
	{	//VBR	
		//printf("----%x-----%x-------%x--------%x--\n",xing_head[0],xing_head[1],xing_head[2],xing_head[3]);
		fseek(fp, 4, SEEK_CUR);
		fread(&total_frame, 1, 4, fp);
		//printf("----%x-----%x-------%x--------%x--\n",total_frame[0],total_frame[1],total_frame[2],total_frame[3]);
		total_f =( total_frame[0]<<24) |(total_frame[1]<<16 )|(total_frame[2]<<8 )|(total_frame[3]);
		//printf("--------------------------------%d--\n",total_f);

		total_time_voice = total_f *1152/44100;
	}
	else
	{	//CBR
		//printf("----%x-----%x-------%x--------%x--\n",file_head[0],file_head[1],file_head[2],file_head[3]);

		cur_mpeg = (file_head[1]&0x18)>>3;
		cur_layer = (file_head[1]&0x6)>>1;
		cur_bit_hz = (file_head[2]&0xF0)>>4;

		total_time = nFileSize*8/M_L_W[cur_mpeg][cur_layer][cur_bit_hz]/1000;
		//printf("cur mp3 nFileSize is ------------>%d\n",nFileSize);
		//printf("cur mp3 M_L_W is ------------>%d\n",M_L_W[cur_mpeg][cur_layer][cur_bit_hz]);
		//printf("cur mp3 total time is ------------>%d\n",total_time);
		total_time_voice = total_time;
	}
	
}




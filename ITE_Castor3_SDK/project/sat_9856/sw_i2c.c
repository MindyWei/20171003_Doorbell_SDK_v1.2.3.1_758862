#include "function_user.h"


struct i2c_info sw_i2c_info[SW_I2C_ITEM_MAX];



void sw_i2c_set()
{
	sw_i2c_info[0].sda 	= 83;	//CAP_SDA
	sw_i2c_info[0].scl		= 82;	//CAP_SCL
	sw_i2c_info[1].sda 	= 0;		//TOUCH_SDA
	sw_i2c_info[1].scl 	= 0;		//TOUCH_SCL
	sw_i2c_info[2].sda	= 0;		//AUDIO_SDA
	sw_i2c_info[2].scl 	= 0;		//ADUIO_SCL
	sw_i2c_info[3].sda	= 87;	//6502_SDA
	sw_i2c_info[3].scl 	= 86;	//6502_SCL
}

void sw_i2c_init(int SW_I2C_ITEM)
{	
	ithGpioSetMode(sw_i2c_info[SW_I2C_ITEM-1].sda , ITH_GPIO_MODE0);
	ithGpioSetMode(sw_i2c_info[SW_I2C_ITEM-1].scl, ITH_GPIO_MODE0);
	ithGpioEnable(sw_i2c_info[SW_I2C_ITEM-1].sda);
	ithGpioEnable(sw_i2c_info[SW_I2C_ITEM-1].scl);
	ithGpioSetOut(sw_i2c_info[SW_I2C_ITEM-1].sda);
	ithGpioSetOut(sw_i2c_info[SW_I2C_ITEM-1].scl);
	ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].sda);		//³õÊ¼×´Ì¬
	ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].scl);
}

void sw_i2c_start(int SW_I2C_ITEM)
{
	ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].scl);				//³õÊ¼×´Ì¬
	ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].sda);
	usleep(DELAY_TIME);
	ithGpioClear(sw_i2c_info[SW_I2C_ITEM-1].sda);			// start
	usleep(DELAY_TIME);
	ithGpioClear(sw_i2c_info[SW_I2C_ITEM-1].scl);
	usleep(DELAY_TIME);
}

void sw_i2c_end(int SW_I2C_ITEM)
{
	ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].scl);		
	usleep(DELAY_TIME);
	if(ithGpioGet(sw_i2c_info[SW_I2C_ITEM-1].sda))
	{
		ithGpioClear(sw_i2c_info[SW_I2C_ITEM-1].sda);		//³õÊ¼×´Ì¬
		usleep(DELAY_TIME);
	}
	ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].sda);		//³õÊ¼×´Ì¬
	
	//usleep(10000);
	usleep(DELAY_TIME);
}

void sw_i2c_write(int SW_I2C_ITEM,int val)
{
	int i;
	int tmp = 0x80;
	
	for(i = 0;i<8;i++)
	{
		if(val&tmp)
		{
			ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].sda);		// 1
			usleep(DELAY_TIME);
			ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].scl);
			usleep(DELAY_TIME);
			ithGpioClear(sw_i2c_info[SW_I2C_ITEM-1].scl);
			usleep(DELAY_TIME);
		}
		else
		{
			ithGpioClear(sw_i2c_info[SW_I2C_ITEM-1].sda);		// 0
			usleep(DELAY_TIME);
			ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].scl);
			usleep(DELAY_TIME);
			ithGpioClear(sw_i2c_info[SW_I2C_ITEM-1].scl);
			usleep(DELAY_TIME);
		}
		tmp >>= 1;
	}
		
}

void write_ack(int SW_I2C_ITEM)
{
	ithGpioSetIn(sw_i2c_info[SW_I2C_ITEM-1].sda);
	usleep(DELAY_TIME);
	ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].scl);
	usleep(10);
#if SW_I2C_MSG
	if(ithGpioGet(sw_i2c_info[SW_I2C_ITEM-1].sda))
		printf("fail..........\n");
	else
		printf("success..........\n");
#endif 
	ithGpioClear(sw_i2c_info[SW_I2C_ITEM-1].scl);
	usleep(DELAY_TIME);
	ithGpioSetOut(sw_i2c_info[SW_I2C_ITEM-1].sda);
	usleep(DELAY_TIME);
}

int sw_i2c_read(int SW_I2C_ITEM)
{
	int i;
	int val = 0;
	int rc = 1;
	
	ithGpioSetIn(sw_i2c_info[SW_I2C_ITEM-1].sda);
	usleep(DELAY_TIME);
	for(i = 0;i < 8;i++)
	{
		ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].scl);
		usleep(DELAY_TIME);
		if(ithGpioGet(sw_i2c_info[SW_I2C_ITEM-1].sda))
			val = val<<1 | rc;
		else
			val = val<<1;
		ithGpioClear(sw_i2c_info[SW_I2C_ITEM-1].scl);
		usleep(DELAY_TIME);

	}
		//printf("--------------->%x\n",val);
	return val;
}

void read_ack(int SW_I2C_ITEM)
{
#if 1
	ithGpioSetOut(sw_i2c_info[SW_I2C_ITEM-1].sda);
	usleep(DELAY_TIME);
	ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].sda);
	usleep(DELAY_TIME);
	ithGpioSet(sw_i2c_info[SW_I2C_ITEM-1].scl);
	usleep(DELAY_TIME);
#if SW_I2C_MSG
	if(ithGpioGet(sw_i2c_info[SW_I2C_ITEM-1].sda))
		printf("fail..........\n");
	else
		printf("success..........\n");
#endif 
	ithGpioClear(sw_i2c_info[SW_I2C_ITEM-1].scl);
	usleep(DELAY_TIME);
#endif
}


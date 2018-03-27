#ifndef _SW_I2C_H_
#define _SW_I2C_H_

#define SW_I2C_MSG				0
#define SW_I2C_ITEM_MAX		4

#define CAP_I2C		1		//CAP_SDA		CAP_SCL
#define TOUCH_I2C	2		//TOUCH_SDA		TOUCH_SCL
#define AUDIO_I2C	3		//AUDIO_SDA		ADUIO_SCL
#define V6502_I2C	4		//V6502_SDA		V6502_SCL

#define GPIO_PORT 	int
#define DELAY_TIME 	10		//us

struct i2c_info
{
	GPIO_PORT sda;
	GPIO_PORT scl;
};

extern struct i2c_info sw_i2c_info[SW_I2C_ITEM_MAX];

void sw_i2c_set();
void sw_i2c_init(int SW_I2C_ITEM);
void sw_i2c_start(int SW_I2C_ITEM);
void sw_i2c_end(int SW_I2C_ITEM);
void sw_i2c_write(int SW_I2C_ITEM,int val);
void write_ack(int SW_I2C_ITEM);
int sw_i2c_read(int SW_I2C_ITEM);
void read_ack(int SW_I2C_ITEM);

#endif // _SW_I2C_H_

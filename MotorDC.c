/*
 * MotorDC.c
 *
 * Created: 12/9/2019 12:07:15 PM
 *  Author: ahmad
 */ 


#include "MotorDC.h"
#include "gpio.h"
#include "led.h"
/**
 * Description: 
 * @param
 */
void 
MotorDC_Init(En_motorType_t MOT_x)
{
	switch(MOT_x)
	{
		case MOT_1:
		//Led_On(LED_2);
		gpioPinDirection(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, OUTPUT);
		gpioPinDirection(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, OUTPUT);
		gpioPinDirection(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, OUTPUT);
		break;
		case MOT_2:
		gpioPinDirection(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, OUTPUT);
		gpioPinDirection(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, OUTPUT);
		gpioPinDirection(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, OUTPUT);
		break;
	}
}


/**
 * Description: 
 * @param 
 * @param 
 */
void 
MotorDC_Dir(En_motorType_t MOT_x, En_motorDir_t dir)
{
	switch (MOT_x)
	{
	case MOT_1:
		switch (dir)
		{
		case STOP:
			gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, 0x00);
			gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, 0xFF);
			break;
		case FORWARD:
			Led_On(LED_2);
			gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, 0x00);
			gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, 0xFF);
			break;
		case BACKWARD:
			gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, 0xFF);
			gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, 0x00);
			break;
		}
		break;
	case MOT_2:
		switch (dir)
		{
		case STOP:
			gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, 0x00);
			gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, 0x00);
			break;
		case FORWARD:
			gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, 0x00);
			gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, 0xFF);
			break;
		case BACKWARD:
			gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, 0xFF);
			gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, 0x00);
			break;
		}
	break;
	}
}


/**
 * Description: 
 * @param 
 */
void 
MotorDC_Speed_PollingWithT1(uint8 speed)
{
	timer1SwPWM(speed, 1);
}
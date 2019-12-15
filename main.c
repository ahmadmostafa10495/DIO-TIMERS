/*
 * GPIO.c
 *
 * Created: 12/3/2019 2:30:38 PM
 *  Author: ahmad
 */ 


//#include <avr/io.h>
#include "gpio.h"
#include "registers.h"
#include "softwareDelay.h"
#include "led.h"
#include "pushButton.h"
#include "timers.h"
#include "interrupt.h"
#include "MotorDC.h"
volatile uint16 speed;
//#include <util/delay.h>
//#define F_CPU 8000000UL
int main(void)
{
	Led_Init(LED_2);
	MotorDC_Init(MOT_1);
	MotorDC_Init(MOT_2);
	MotorDC_Dir(MOT_1, FORWARD);
	MotorDC_Dir(MOT_2, FORWARD);
	sei();	
	timer1Init(T1_NORMAL_MODE,T1_OC1_DIS,T1_PRESCALER_1024,0,0,0,0,T1_INTERRUPT_CMP_1A|T1_INTERRUPT_NORMAL);
	/*Led_Init(LED_0);
	
	Led_Init(LED_3);
	Led_Off(LED_1);
	Led_On(LED_0);
	pushButton_Init(BTN_0);*/
	Led_Init(LED_0);
	uint16 c = 5000, t = 1, f=0;
	speed = 10;

	uint8 counter = 0, onFlag = 0, value = 10;

	MotorDC_Speed_PollingWithT1(speed);
	timer1Start();
    while(1)
    {

		if (speed == 90)
		{
			f=1;
		}
		else if(speed == 10)
		{
			f=0;
		}
		t++;
		if (t==50000)
		{
			if (f==0)
			{
				speed++;
			}
			else
			{
				speed--;
			}
			t=1;
		}
		//MotorDC_Speed_PollingWithT1(speed);
		
		
		//timer0Delay_ms(1000);
		//timer1SwPWM(1,25);
		
		/*pushButton_Update();
		SwDelay_ms(80);
		//timer0Delay_ms(80);
		if (pushButton_GetStatus(BTN_0)==Pressed)
		{
			Led_On(LED_1);
			if (onFlag == 1)
			{
				value = 20;
			}
			else
				onFlag = 1;
		}
		else
		{
			if (onFlag == 0)
			{
				Led_Off(LED_1);
				onFlag = 0;
				value = 10;
			}
		}
		if (onFlag == 1)
		{
			if (counter<value)
			{
				counter++;
			}
			else
			{
				onFlag = 0;
				counter = 0;
			}
		}*/
			
			
		
		/*pushButton_Update();
		if (pushButton_GetStatus(BTN_0)==Pressed)
		{
			Led_Toggle(LED_1);
		}
        //TODO:: Please write your application code 
		Led_On(LED_1);
		SwDelay_ms(1000);
		Led_Off(LED_1);
		Led_On(LED_2);
		SwDelay_ms(1000);
		Led_Off(LED_2);
		Led_On(LED_3);
		SwDelay_ms(1000);
		Led_Off(LED_3);*/
		
    }
}
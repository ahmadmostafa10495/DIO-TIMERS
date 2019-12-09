/*
 * led.c
 *
 * Created: 12/3/2019 7:35:01 PM
 *  Author: ahmad
 */ 

#include "led.h"


#define ON 0xFF
#define OFF 0x00

/**
 * Description: Initialize the LED_x (where x 0, 1, 2, 3) as output
 * @param led_id: The led to be initialized and it takes
 * 				  one of the enum (En_LedNumber_t) parameters
 *
 */
void 
Led_Init(En_LedNumber_t led_id)
{
	switch(led_id)
	{
		case LED_0:
		gpioPinDirection(LED_0_GPIO, LED_0_BIT, OUTPUT);
		break;
		case LED_1:
		gpioPinDirection(LED_1_GPIO, LED_1_BIT, OUTPUT);
		break;
		case LED_2:
		gpioPinDirection(LED_2_GPIO, LED_2_BIT, OUTPUT);
		break;
		case LED_3:
		gpioPinDirection(LED_3_GPIO, LED_3_BIT, OUTPUT);
		break;
	}
	
}

/**
 * Description: Change the LED_x state (where x 0, 1, 2, 3) to be on
 * @param led_id: The led to be initialized and it takes
 * 				  one of the enum (En_LedNumber_t) parameters
 *
 */
void 
Led_On(En_LedNumber_t led_id)
{
	switch(led_id)
	{
		case LED_0:
		gpioPinWrite(LED_0_GPIO, LED_0_BIT, ON);
		break;
		case LED_1:
		gpioPinWrite(LED_1_GPIO, LED_1_BIT, ON);
		break;
		case LED_2:
		gpioPinWrite(LED_2_GPIO, LED_2_BIT, ON);
		break;
		case LED_3:
		gpioPinWrite(LED_3_GPIO, LED_3_BIT, ON);
		break;
	}
}

/**
 * Description: Change the LED_x state (where x 0, 1, 2, 3) to be off
 * @param led_id: The led to be initialized and it takes
 * 				  one of the enum (En_LedNumber_t) parameters
 *
 */
void 
Led_Off(En_LedNumber_t led_id)
{
	switch(led_id)
	{
		case LED_0:
		gpioPinWrite(LED_0_GPIO, LED_0_BIT, OFF);
		break;
		case LED_1:
		gpioPinWrite(LED_1_GPIO, LED_1_BIT, OFF);
		break;
		case LED_2:
		gpioPinWrite(LED_2_GPIO, LED_2_BIT, OFF);
		break;
		case LED_3:
		gpioPinWrite(LED_3_GPIO, LED_3_BIT, OFF);
		break;
	}
}

/**
 * Description: Toggle the LED_x state (where x 0, 1, 2, 3)
 * @param led_id: The led to be initialized and it takes
 * 				  one of the enum (En_LedNumber_t) parameters
 *
 */
void 
Led_Toggle(En_LedNumber_t led_id)
{
	switch(led_id)
	{
		case LED_0:
		gpioPinToggle(LED_0_GPIO, LED_0_BIT);
		break;
		case LED_1:
		gpioPinToggle(LED_1_GPIO, LED_1_BIT);
		break;
		case LED_2:
		gpioPinToggle(LED_2_GPIO, LED_2_BIT);
		break;
		case LED_3:
		gpioPinToggle(LED_3_GPIO, LED_3_BIT);
		break;
	}
}
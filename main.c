/*
 * GPIO.c
 *
 * Created: 12/3/2019 2:30:38 PM
 *  Author: ahmad
 */ 


//#include <avr/io.h>
#include "gpio.h"
#include "registers.h"
#include "gpio.h"
#include "softwareDelay.h"
//#include <util/delay.h>
//#define F_CPU 8000000UL
int main(void)
{
	gpioPortDirection( GPIOB, OUTPUT);

					gpioUpperNibbleWrite(GPIOB, 0xFF);
    while(1)
    {
        //TODO:: Please write your application code 

					SwDelay_ms(1000);
					gpioUpperNibbleToggle(GPIOB);
    }
}
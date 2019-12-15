/*
 * timers.c
 *
 * Created: 12/6/2019 9:55:37 PM
 *  Author: ahmad
 */ 


#include "timers.h"
#include "MotorDC_CFG.h"
#include "led.h"
#include "interrupt.h"
#include "MotorDC.h"
extern uint16 speed;

static En_timer0perscaler_t g_prescal0;
static En_timer1perscaler_t g_prescal1;
static En_timer2perscaler_t g_prescal2;

/*===========================Timer0 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void 
timer0Init(En_timer0Mode_t mode,En_timer0OC_t OC0,En_timer0perscaler_t prescal, uint8 initialValue, uint8 outputCompare, En_timer0Interrupt_t interruptMask)
{
	
	TCCR0 = 0;
	TCCR0 |= mode|OC0;
	g_prescal0 = prescal;
	TCNT0 = initialValue;
	OCR0 = outputCompare;
	TIMSK |=interruptMask;	
}

/**
 * Description:
 * @param value
 */
void 
timer0Set(uint8 value)
{
	TCNT0 |= value;
}


/**
 * Description:
 * @return
 */
uint8 
timer0Read(void)
{
	return TCNT0;
}

/**
 * Description:
 */
void 
timer0Start(void)
{
	TCCR0 |= g_prescal0;
}


/**
 * Description:
 */
void 
timer0Stop(void)
{
	TCCR0 &= ~(0x07);
}


/**
 * Description:
 * @param delay
 */
void 
timer0Delay_ms(uint16 delay)
{	
	uint16 i;
	timer0Init(T0_NORMAL_MODE, T0_OC0_DIS, T0_PRESCALER_64, 131, 0, T0_POLLING); 
	timer0Start();
	for (i=0;i<delay;i++)
	{
		while(!(TIFR & (1 << 0)));
		TIFR |= (1 << 0);
		timer0Set(131);
	}
	timer0Stop();
}

/**
 * Description:
 * @param dutyCycle
 */
void timer0SwPWM(uint8 dutyCycle,uint8 freq)
{
	
}



/*===========================Timer1 Control===============================*/
/**
 * Description:
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void 
timer1Init(En_timer1Mode_t mode,En_timer1OC_t OC,En_timer1perscaler_t prescal, uint16 initialValue, uint16 outputCompareA, uint16 outputCompareB,uint16 inputCapture, En_timer1Interrupt_t interruptMask)
{
	TCCR1 = 0;
	TCCR1 |= mode|OC;
	g_prescal1 = prescal;
	TCNT1 = initialValue;
	OCR1A =	outputCompareA;
	OCR1B = outputCompareB;
	ICR1 = inputCapture;
	TIMSK |= interruptMask;
}

/**
 * Description:
 * @param value
 */
void 
timer1Set(uint16 value)
{
	TCNT1 = value;
}



/**
 * Description:
 * @return
 */
uint16 
timer1Read(void)
{
	return TCNT1;
}



/**
 * Description:
 */
void 
timer1Start(void)
{
	TCCR1 |= g_prescal1;
}

/**
 * Description:
 */
void 
timer1Stop(void)
{
	TCCR1 &= ~(0x07);
}

/**
 * Description:
 * @param delay
 */
void timer1Delay_ms(uint16 delay)
{
	uint16 i;
	timer1Init(T1_NORMAL_MODE, T1_OC1_DIS, T1_PRESCALER_64, 65410, 0, 0, 0, T1_POLLING);
	timer1Start();
	for (i=0;i<delay;i++)
	{
		while(!(TIFR & (1 << 2)));
		TIFR |= (1 << 2);
		timer1Set(65410);
	}
	timer0Stop();
}

/**
 * Description:
 * @param dutyCycle
 */
/*void 
timer1SwPWM(uint8 dutyCycle,uint8 freq)
{
	
	
	//uint16 tempTCCNT =TCNT1;
	//uint16 tempTCCR =TCCR1;
	//uint16 tempOCR =OCR1A;
	uint32 x,y,z;
	//TCNT1=		65537-(((16000000UL)/(freq*(1000UL))));
	//	TCNT1=		65535-((16000000UL)/(freq*(1000UL)*8));
	//TCNT1=64897;
	x=(16000000UL)/(freq*(1000UL)*1024);
	TCNT1=65536-x;
	//				OCR1A=   ((((16000000UL)/(freq*(1000UL)*8))*dutyCycle)/100)+TCNT1;
	//OCR1A=   ((((16000000UL)/(freq*(1000UL)))*dutyCycle)/100)+TCNT1;
	//OCR1A=65408;
	//OCR1A=65520;
	y=dutyCycle*x;
	z=y/100;
	OCR1A=z+TCNT1;
	
	
	gpioPinWrite(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, HIGH);
	gpioPinWrite(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, HIGH);
	Led_On(LED_0);
	//gpioPinWrite(GPIOD, BIT4, HIGH);
	//Led_On(LED_2);
	timer1Start();
	
	while((TIFR&0x10)==0);
	TIFR|=0x10;
	//
	//gpioPinWrite(GPIOD, BIT4, LOW);
	//Led_Off(LED_2);
	gpioPinWrite(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, LOW);
	gpioPinWrite(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, LOW);
	Led_Off(LED_0);
	while((TIFR&0x04)==0);
	TIFR|=0x04;
	timer1Stop();

}*/
/**
 * Description:
 * @param dutyCycle
 */
void 
timer1SwPWM(uint8 dutyCycle,uint8 freq)
{
	
	
	//uint16 tempTCCNT =TCNT1;
	//uint16 tempTCCR =TCCR1;
	//uint16 tempOCR =OCR1A;
	uint32 x,y,z;
	//TCNT1=		65537-(((16000000UL)/(freq*(1000UL))));
	//	TCNT1=		65535-((16000000UL)/(freq*(1000UL)*8));
	//TCNT1=64897;
	x=(16000000UL)/(freq*(1000UL)*1024);
	TCNT1=65536-x;
	//				OCR1A=   ((((16000000UL)/(freq*(1000UL)*8))*dutyCycle)/100)+TCNT1;
	//OCR1A=   ((((16000000UL)/(freq*(1000UL)))*dutyCycle)/100)+TCNT1;
	//OCR1A=65408;
	//OCR1A=65520;
	y=dutyCycle*x;
	z=y/100;
	OCR1A=z+TCNT1;
	
	
	/*gpioPinWrite(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, HIGH);
	gpioPinWrite(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, HIGH);
	Led_On(LED_0);*/
	//gpioPinWrite(GPIOD, BIT4, HIGH);
	//Led_On(LED_2);
	//timer1Start();
	
	//while((TIFR&0x10)==0);
	//TIFR|=0x10;
	//
	//gpioPinWrite(GPIOD, BIT4, LOW);
	//Led_Off(LED_2);
	/*gpioPinWrite(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, LOW);
	gpioPinWrite(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, LOW);
	Led_Off(LED_0);*/
	//while((TIFR&0x04)==0);
	//TIFR|=0x04;
	//timer1Stop();

}



/*===========================Timer2 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void 
timer2Init(En_timer2Mode_t mode,En_timer2OC_t OC,En_timer2perscaler_t prescal, uint8 initialValue, uint8 outputCompare, uint8 assynchronous, En_timer2Interrupt_t interruptMask)
{
	TCCR2 = 0;
	TCCR2 |= mode | OC;
	g_prescal2 = prescal;
	TCNT2 = initialValue;
	OCR2 = outputCompare;
	TIMSK |= interruptMask;
	
}
/**
 * Description:
 * @param value
 */
void 
timer2Set(uint8 value)
{
	TCNT2 = value;
}

/**
 * Description:
 * @return
 */
uint8 
timer2Read(void)
{
	return TCNT2;
}

/**
 * Description:
 */
void 
timer2Start(void)
{
	TCCR2 |= g_prescal2;
}

/**
 * Description:
 */
void 
timer2Stop(void)
{
	TCCR2 &= ~(0x07);
}

/**
 * Description:
 * @param delay
 */
void 
timer2Delay_ms(uint16 delay)
{
	uint16 i;
	timer2Init(T2_NORMAL_MODE, T2_OC2_DIS, T2_PRESCALER_64, 131, 0, 0, T2_POLLING);
	timer2Start();
	for (i=0;i<delay;i++)
	{
		while(!(TIFR & (1 << 0)));
		TIFR |= (1 << 0);
		timer2Set(131);
	}
	timer2Stop();
}

/**
 * Description:
 * @param dutyCycle
 */
void timer2SwPWM(uint8 dutyCycle,uint8 freq);

/*
 * user defined
 */
void 
timer2Delay_us(uint32 delay)
{
	uint16 i;
	timer2Init(T2_NORMAL_MODE, T2_OC2_DIS, T2_PRESCALER_NO, 248, 0, 0, T2_POLLING);
	timer2Start();
	for (i=0;i<delay;i++)
	{
		while(!(TIFR & (1 << 6)));
		TIFR |= (1 << 6);
		timer2Set(248);
	}
	timer2Stop();
}

ISR(TIMER1_OVF_vect)
{	gpioPinWrite(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, LOW);
	gpioPinWrite(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, LOW);
	Led_Off(LED_0);
	MotorDC_Speed_PollingWithT1(speed);
	//timer1Start();
	
}
ISR(TIMER1_COMPA_vect)
{
	gpioPinWrite(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, HIGH);
	gpioPinWrite(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, HIGH);
	Led_On(LED_0);	

}


	/*timer1Init(T1_NORMAL_MODE, T1_OC0_DIS, T1_PRESCALER_256, 0, (655 * dutyCycle), 0, 0, T1_POLLING);
	timer1Set(13107);
	gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, HIGH);
	while (!(TIFR&(1<<4)));
	gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, LOW);
	while (!(TIFR&(1<<4)));*/
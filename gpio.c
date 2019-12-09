/*
 * gpio.c
 *
 * Created: 12/3/2019 2:32:56 PM
 *  Author: ahmad
 */ 
#include "gpio.h"



/************************************************************************/
/*				 GPIO functions' implementation                         */
/************************************************************************/

/*===========================PORT Control===============================*/
/**
 * Description: set port direction (which is DDR register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param direction: set the port direction and takes the following values
 * 				- 0x00 -> Input
 * 				- 0xff -> Output
 */
void 
gpioPortDirection(uint8 port, uint8 direction)
{
	switch (port)
	{
		case GPIOA:
			PORTA_DIR = direction;
			break;
		case GPIOB:
			PORTB_DIR = direction;
			break;
		case GPIOC:
			PORTC_DIR = direction;
			break;
		case GPIOD:
			PORTD_DIR = direction;
			break;
	}
}


/**
 * Description: set the port value (which is PORT register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value: set the port value and takes the following values
 * 				- 0x00 -> Low
 * 				- 0xff -> High
 */
void 
gpioPortWrite(uint8 port, uint8 value)
{
	switch (port)
	{
		case GPIOA:
		PORTA_DATA = value;
		break;
		case GPIOB:
		PORTB_DATA = value;
		break;
		case GPIOC:
		PORTC_DATA = value;
		break;
		case GPIOD:
		PORTD_DATA = value;
		break;
	}	
}

/**
 * Description: toggle the port value (which is PORT register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 */
void 
gpioPortToggle(uint8 port)
{
	switch (port)
	{
		case GPIOA:
		PORTA_DATA ^= 0xFF;
		break;
		case GPIOB:
		PORTB_DATA ^= 0xFF;
		break;
		case GPIOC:
		PORTC_DATA ^= 0xFF;
		break;
		case GPIOD:
		PORTD_DATA ^= 0xFF;
		break;
	}
}

/**
 * Description: read the current port value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */
uint8 
gpioPortRead(uint8 port)
{	
	switch (port)
	{
		case GPIOA:
		return PORTA_PIN;
		break;
		case GPIOB:
		return PORTB_PIN;
		break;
		case GPIOC:
		return PORTC_PIN;
		break;
		case GPIOD:
		return PORTD_PIN;
		break;
	}
}

/*===========================PIN Control===============================*/
/**
 * Description: set selected pins (more than one pin [ORed]) direction
 *
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pins the user need to set its direction and takes
 * 				any member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 *
 * @param direction: set the pins direction and takes the following values
 * 				- 0x00 -> Input
 * 				- 0xff -> Output
 */
void 
gpioPinDirection(uint8 port, uint8 pins, uint8 direction)
{
	switch(direction)
		{
			case INPUT:
					switch (port)
					{
						case GPIOA:
						PORTA_DIR &= ~pins;
						break;
						case GPIOB:
						PORTB_DIR &= ~pins;
						break;
						case GPIOC:
						PORTC_DIR &= ~pins;
						break;
						case GPIOD:
						PORTD_DIR &= ~pins;
						break;
					}
					break;
				case OUTPUT:
						switch (port)
						{
							case GPIOA:
							PORTA_DIR |= pins;
							break;
							case GPIOB:
							PORTB_DIR |= pins;
							break;
							case GPIOC:
							PORTC_DIR |= pins;
							break;
							case GPIOD:
							PORTD_DIR |= pins;
							break;
						}
						break;
		}
}

/**
 * Description: set selected pins (more than one pin [ORed]) values
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pins the user need to write its values and takes
 * 				any member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 * @param value
 */
void 
gpioPinWrite(uint8 port, uint8 pins, uint8 value)
{
	switch(value)
	{
		case 0x00:
		switch (port)
		{
			case GPIOA:
			PORTA_DATA &= ~pins;
			break;
			case GPIOB:
			PORTB_DATA &= ~pins;
			break;
			case GPIOC:
			PORTC_DATA &= ~pins;
			break;
			case GPIOD:
			PORTD_DATA &= ~pins;
			break;
		}
		break;
		case 0xFF:
		switch (port)
		{
			case GPIOA:
			PORTA_DATA |= pins;
			break;
			case GPIOB:
			PORTB_DATA |= pins;
			break;
			case GPIOC:
			PORTC_DATA |= pins;
			break;
			case GPIOD:
			PORTD_DATA |= pins;
			break;
		}
		break;
	}
}

/**
 * Description: toggle selected pin (only one pin) direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pin the user need to toggle it's value and takes
 * 				only one member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 */
void 
gpioPinToggle(uint8 port, uint8 pins)
{
	switch (port)
	{
		case GPIOA:
		PORTA_DATA ^= pins;
		break;
		case GPIOB:
		PORTB_DATA ^= pins;
		break;
		case GPIOC:
		PORTC_DATA ^= pins;
		break;
		case GPIOD:
		PORTD_DATA ^= pins;
		break;
	}
}


/**
 * Description: read selected pin (only one pin) direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param pin: the selected pin the user need to read it's value and takes
 * 				only one member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 * @return
 */
uint8 
gpioPinRead(uint8 port, uint8 pin)
{
	switch (port)
	{
		case GPIOA:
		return GET_BIT(PORTA_PIN,pin);
		break;
		case GPIOB:
		return GET_BIT(PORTB_PIN,pin);
		break;
		case GPIOC:
		return GET_BIT(PORTC_PIN,pin);		//abdo portc-data
		break;
		case GPIOD:
		return GET_BIT(PORTD_PIN,pin);
		break;
	}
}


/*===========================Upper Nibble Control===============================*/
/**
 * Description: set the upper nibble direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param direction
 */
void 
gpioUpperNibbleDirection(uint8 port, uint8 direction)
{
	switch(direction)
	{
		case INPUT:
		switch (port)
		{
			case GPIOA:
			PORTA_DIR &= ~0xF0;
			break;
			case GPIOB:
			PORTB_DIR &= ~0xF0;
			break;
			case GPIOC:
			PORTC_DIR &= ~0xF0;
			break;
			case GPIOD:
			PORTD_DIR &= ~0xF0;
			break;
		}
		break;
		case OUTPUT:
		switch (port)
		{
			case GPIOA:
			PORTA_DIR |= 0xF0;
			break;
			case GPIOB:
			PORTB_DIR |= 0xF0;
			break;
			case GPIOC:
			PORTC_DIR |= 0xF0;
			break;
			case GPIOD:
			PORTD_DIR |= 0xF0;
			break;
		}
		break;
	}
}

/**
 * Description: write the upper nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value
 */
void 
gpioUpperNibbleWrite(uint8 port, uint8 value)
{

	switch(value)
	{
		case 0x00:
		switch (port)
		{
			case GPIOA:
			PORTA_DATA &= ~0xF0;
			break;
			case GPIOB:
			PORTB_DATA &= ~0xF0;
			break;
			case GPIOC:
			PORTC_DATA &= ~0xF0;
			break;
			case GPIOD:
			PORTD_DATA &= ~0xF0;
			break;
		}
		break;
		case 0xFF:
		switch (port)
		{
			case GPIOA:
			PORTA_DATA |= 0xF0;
			break;
			case GPIOB:
			PORTB_DATA |= 0xF0;
			break;
			case GPIOC:
			PORTC_DATA |= 0xF0;
			break;
			case GPIOD:
			PORTD_DATA |= 0xF0;
			break;
		}
		break;
	}
}

/**
 * Description: toggle the upper nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 */
void 
gpioUpperNibbleToggle(uint8 port)
{
	switch (port)
	{
		case GPIOA:
		PORTA_DATA ^= 0xF0;
		break;
		case GPIOB:
		PORTB_DATA ^= 0xF0;
		break;
		case GPIOC:
		PORTC_DATA ^= 0xF0;
		break;
		case GPIOD:
		PORTD_DATA ^= 0xF0;
		break;
	}
}

/**
 * Description: read the upper nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */
uint8 
gpioUpperNibbleRead(uint8 port)
{
	switch (port)
	{
		case GPIOA:
		return PORTA_PIN & 0xF0;
		break;
		case GPIOB:
		return PORTB_PIN & 0xF0;
		break;
		case GPIOC:
		return PORTC_PIN & 0xF0;
		break;
		case GPIOD:
		return PORTD_PIN & 0xF0;
		break;
	}
}


/*===========================Lower Nibble Control===============================*/
/**
 * Description: set the lower nibble direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param direction
 */
void 
gpioLowerNibbleDirection(uint8 port, uint8 direction)
{
	switch(direction)
	{
		case INPUT:
		switch (port)
		{
			case GPIOA:
			PORTA_DIR &= ~0x0F;
			break;
			case GPIOB:
			PORTB_DIR &= ~0x0F;
			break;
			case GPIOC:
			PORTC_DIR &= ~0x0F;
			break;
			case GPIOD:
			PORTD_DIR &= ~0x0F;
			break;
		}
		break;
		case OUTPUT:
		switch (port)
		{
			case GPIOA:
			PORTA_DIR |= 0x0F;
			break;
			case GPIOB:
			PORTB_DIR |= 0x0F;
			break;
			case GPIOC:
			PORTC_DIR |= 0x0F;
			break;
			case GPIOD:
			PORTD_DIR |= 0x0F;
			break;
		}
		break;
	}
}

/**
 * Description: write the lower nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value
 */
void 
gpioLowerNibbleWrite(uint8 port, uint8 value)
{
	switch(value)
	{
		case 0x00:
		switch (port)
		{
			case GPIOA:
			PORTA_DATA &= ~0x0F;
			break;
			case GPIOB:
			PORTB_DATA &= ~0x0F;
			break;
			case GPIOC:
			PORTC_DATA &= ~0x0F;
			break;
			case GPIOD:
			PORTD_DATA &= ~0x0F;
			break;
		}
		break;
		case 0xFF:
		switch (port)
		{
			case GPIOA:
			PORTA_DATA |= 0x0F;
			break;
			case GPIOB:
			PORTB_DATA |= 0x0F;
			break;
			case GPIOC:
			PORTC_DATA |= 0x0F;
			break;
			case GPIOD:
			PORTD_DATA |= 0x0F;
			break;
		}
		break;
	}
}

/**
 * Description: toggle the lower nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 */
void 
gpioLowerNibbleToggle(uint8 port)
{
	switch (port)
	{
		case GPIOA:
		PORTA_DATA ^= 0x0F;
		break;
		case GPIOB:
		PORTB_DATA ^= 0x0F;
		break;
		case GPIOC:
		PORTC_DATA ^= 0x0F;
		break;
		case GPIOD:
		PORTD_DATA ^= 0x0F;
		break;
	}
}

/**
 * Description: read the lower nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */
uint8 
gpioLowerNibbleRead(uint8 port)
{
	switch (port)
	{
		case GPIOA:
		return PORTA_PIN & 0x0F;
		break;
		case GPIOB:
		return PORTB_PIN & 0x0F;
		break;
		case GPIOC:
		return PORTC_PIN & 0x0F;
		break;
		case GPIOD:
		return PORTC_PIN & 0x0F;
		break;
	}
}

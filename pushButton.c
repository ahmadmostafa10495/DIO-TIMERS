/*
 * pushButton.c
 *
 * Created: 12/4/2019 11:03:04 AM
 *  Author: ahmad
 */ 


#include "pushButton.h"
#define BTN_COUNT (4)
#define UPDATE_PERIOD (20)
#define BTN_PRESSED_LEVEL (1)
#define BTN_RELEASED_LEVEL (0)
static En_buttonStatus_t BTN_STATE[BTN_COUNT];
static uint8 BTN_OLDEST_READING[BTN_COUNT];
static uint8 BTN_OLDER_READING[BTN_COUNT];
#define READ_BTN(BTN, i) do {  \
	if(i==BTN){ \
	BTN_OLDER_READING[i] = gpioPinRead(BTN_##i##_GPIO,BTN_##i##_BIT);  \
	} \
}while(0)

/**
 * Description: Initialize the BTN_x Pin state (where x 0, 1, 2, 3) to Input
 * @param btn_id: The btn to be initialized and it takes
 * 				  one of the enum (En_buttonId) parameters
 *
 */
void pushButton_Init(En_buttonId btn_id)
{
	switch(btn_id)
	{
		case BTN_0:
		gpioPinDirection(BTN_0_GPIO, BTN_0_BIT, INPUT);
		#if BTN_PRESSED_LEVEL == 0
		gpioPinWrite(BTN_0_GPIO, BTN_0_BIT, BTN_RELEASED_LEVEL);								
		#endif
		BTN_OLDEST_READING[BTN_0] = BTN_RELEASED_LEVEL;
		BTN_OLDER_READING[BTN_0] = BTN_RELEASED_LEVEL;
		BTN_STATE[BTN_0] = Released;
		break;
		
		case BTN_1:
		gpioPinDirection(BTN_1_GPIO, BTN_1_BIT, INPUT);
		#if BTN_PRESSED_LEVEL == 0
		gpioPinWrite(BTN_1_GPIO, BTN_1_BIT, BTN_RELEASED_LEVEL);
		#endif
		BTN_OLDEST_READING[BTN_1] = BTN_RELEASED_LEVEL;
		BTN_OLDER_READING[BTN_1] = BTN_RELEASED_LEVEL;
		BTN_STATE[BTN_1] = Released;
		break;
		
		case BTN_2:
		gpioPinDirection(BTN_2_GPIO, BTN_2_BIT, INPUT);
		#if BTN_PRESSED_LEVEL == 0
		gpioPinWrite(BTN_2_GPIO, BTN_2_BIT, BTN_RELEASED_LEVEL);
		#endif
		BTN_OLDEST_READING[BTN_2] = BTN_RELEASED_LEVEL;
		BTN_OLDER_READING[BTN_2] = BTN_RELEASED_LEVEL;
		BTN_STATE[BTN_2] = Released;
		break;
		
		case BTN_3:
		gpioPinDirection(BTN_3_GPIO, BTN_3_BIT, INPUT);
		#if BTN_PRESSED_LEVEL == 0
		gpioPinWrite(BTN_3_GPIO, BTN_3_BIT, BTN_RELEASED_LEVEL);
		#endif
		BTN_OLDEST_READING[BTN_3] = BTN_RELEASED_LEVEL;
		BTN_OLDER_READING[BTN_3] = BTN_RELEASED_LEVEL;
		BTN_STATE[BTN_3] = Released;
		break;
	}
}

/**
 * Description: read all BTN_x (where x 0, 1, 2, 3) states and store it in the program
 *
 * @note : this function must be called in the system tick handler or in the super loop handler
 */
void 
pushButton_Update(void)
{
	SwDelay_ms(UPDATE_PERIOD);
	uint8 i;
	for(i=0;i<BTN_COUNT;i++)
	{
		BTN_OLDEST_READING[i] = BTN_OLDER_READING[i];
		//READ_BTN(i, 0);
		//READ_BTN(i, 1);
		//READ_BTN(i, 2);
		//READ_BTN(i, 3);
		switch (i)
		{
		case BTN_0:
		BTN_OLDER_READING[i] = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
		break;
		case BTN_1:
		BTN_OLDER_READING[i] = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
		break;
		case BTN_2:
		BTN_OLDER_READING[i] = gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
		break;
		case BTN_3:
		BTN_OLDER_READING[i] = gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
		break;
		}
		switch (BTN_STATE[i])
		{
		case Released:
			if (BTN_OLDEST_READING[i] == BTN_PRESSED_LEVEL && BTN_OLDER_READING[i] == BTN_PRESSED_LEVEL)
			{
				BTN_STATE[i] = Prepressed;
			}
			break;
		case Prepressed:
			if (BTN_OLDER_READING[i] == BTN_PRESSED_LEVEL)
			{
				BTN_STATE[i] = Pressed;
			}
			break;
		case Pressed:
			if (BTN_OLDEST_READING[i] == BTN_RELEASED_LEVEL && BTN_OLDER_READING[i] == BTN_RELEASED_LEVEL)
			{
				BTN_STATE[i] = Prereleased;
			}
			break;
		case Prereleased:
			if (BTN_OLDER_READING[i] == BTN_RELEASED_LEVEL)
			{
				BTN_STATE[i] = Released;
			}
			break;
		}
	}
	
}


/**
 * Description: read BTN_x (where x 0, 1, 2, 3) state which is stored in the program
 * 				in the update function
 *
 */
En_buttonStatus_t 
pushButton_GetStatus(En_buttonId btn_id)
{
	return BTN_STATE[btn_id];
}

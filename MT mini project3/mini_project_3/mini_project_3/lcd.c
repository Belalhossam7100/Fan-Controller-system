/*
 * lcd.c
 *
 *  Created on: Feb 12, 2024
 *      Author: dell
 */
#include "gpio.h"
#include "lcd.h"
#include <util/delay.h>
#include "common_macros.h" /* For GET_BIT Macro */

void LCD_init(void)
{
	/*for RW*/
	GPIO_setupPinDirection(LCD_RW_PORT_ID,LCD_RW_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_LOW);/*a it is connected to  ground*/
	/* Configure the direction for RS and E pins as output pins */
	GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);

	_delay_ms(20);		/* LCD Power ON delay always > 15ms */

#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DA4_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DA5_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DA6_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DA7_PIN_ID,PIN_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BITS_MODE == 8)
	/* Configure the data port as output port */
	GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);

	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}


void LCD_sendCommand(uint8 command){
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW); /* Instruction Mode RS=0 */
		_delay_ms(1); /* delay for processing Tas = 50ns */
		GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
		_delay_ms(1);

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA4_PIN_ID,GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA5_PIN_ID,GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA6_PIN_ID,GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA7_PIN_ID,GET_BIT(command,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA4_PIN_ID,GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA5_PIN_ID,GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA6_PIN_ID,GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA7_PIN_ID,GET_BIT(command,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID,command); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/**Display the on;y only character on the screen*/
void LCD_displayCharacter(uint8 data){
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH); /* Data Mode RS=1 */
		_delay_ms(1); /* delay for processing Tas = 50ns */
		GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
		_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	#if(LCD_DATA_BITS_MODE == 4)
		GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA4_PIN_ID,GET_BIT(data,4));
		GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA5_PIN_ID,GET_BIT(data,5));
		GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA6_PIN_ID,GET_BIT(data,6));
		GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA7_PIN_ID,GET_BIT(data,7));

		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */
		GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
		_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

		GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA4_PIN_ID,GET_BIT(data,0));
		GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA5_PIN_ID,GET_BIT(data,1));
		GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA6_PIN_ID,GET_BIT(data,2));
		GPIO_writePin(LCD_DATA_PORT_ID,LCD_DA7_PIN_ID,GET_BIT(data,3));

		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */

	#elif(LCD_DATA_BITS_MODE == 8)
		GPIO_writePort(LCD_DATA_PORT_ID,data); /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */
	#endif
}
/**Display the required string on the screen*/
void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}
/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col){
	uint8 address;// the specified row and column index on the screen
	switch(row)
	{
	case 0:
		address=col;
		break;
	case 1:
			address=col+0x40;
			break;
	case 2:
			address=col+0x10;
			break;
	case 3:
			address=col+0x50;
			break;
	}
	/* Move the LCD cursor to this specific address */
		LCD_sendCommand(address | LCD_SET_CURSOR_LOCATION);
		//LCD_SET_CURSOR_LOCATION=0x80=1000 0000
}
//show what is the string in this row and column
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str){
	LCD_moveCursor(row,col);//move the courser to the wanted location
	LCD_displayString(Str);
}

void LCD_intgerToString(int data)
{
	char hold_ascii[16];//string to hold the ascii
	/*
	 * itoa(data, buff, 10);: Converts the integer data into its corresponding ASCII representation using the itoa function.
	 *  The second argument buff specifies where the resulting string will be stored,
	 *  and the third argument 10 indicates that the conversion should be in base 10 (decimal).*/
	itoa(data,hold_ascii,10);
	LCD_displayString(hold_ascii); /* Display the string */
	}


/** Send the clear screen command*/
void LCD_clearScreen(void)
{
	LCD_sendCommand(0x01); /* Send clear display command */
}


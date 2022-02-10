/*
 * Calculator_Project using LCD and Keypad with ATmega32
 *
 *  Created on: Nov 15, 2021
 *      Author: amgdRaghed
 */

/* Include LIB Layer */
#include "std_Types.h"
#include "errorState.h"

/* Include MCAL Layer */
#include "DIO_Interface.h"

/* Include HAL Layer */
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"


int main(void)
{
	LCD_enumInit();
	KEYPAD_enumInit();

	enum operator { ADD = 1, SUB, MUL, DIV };

	u8	key_pressed, operator_flag=0;
	s64 num1=0, num2=0;

	while(1)
	{

		do{
			key_pressed = KEYPAD_u8GetPressedKey();
		}while(key_pressed == KEYPAD_NO_PRESSED_KEY);

		switch(key_pressed)
		{
		case 'C':
			LCD_enumSendCommand(CLEAR_DISPLAY);
			num1=0;
			num2=0;
			operator_flag=0;
			break;

		case '0'...'9':
		if(operator_flag==0)
		{
			LCD_enumSendData(key_pressed);
			num1 *= 10;
			num1 += (key_pressed-'0');
		}
		else
		{
			LCD_enumSendData(key_pressed);
			num2 *= 10;
			num2 += (key_pressed-'0');
		}
		break;

		case '+':
			LCD_enumSendData(key_pressed);
			operator_flag=1;
			break;

		case '-':
			LCD_enumSendData(key_pressed);
			operator_flag=2;
			break;

		case 'x':
			LCD_enumSendData(key_pressed);
			operator_flag=3;
			break;

		case '/':
			LCD_enumSendData(key_pressed);
			operator_flag=4;
			break;

		case '=':
			LCD_enumCursorPosition(ROW_2, COL_1);
			LCD_enumSendData(key_pressed);

			switch(operator_flag)
			{
			case ADD:
				LCD_enumSendInteger(num1+num2);
				break;

			case SUB:
				LCD_enumSendInteger(num1-num2);
				break;

			case MUL:
				LCD_enumSendInteger(num1*num2);
				break;

			case DIV:
				LCD_enumSendFloat(num1/(float)num2);
				break;
			}

			break;
		}

	}

	return 0;
}

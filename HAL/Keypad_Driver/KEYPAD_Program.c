/*
 * KEYPAD_Program.c
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
#include "KEYPAD_Private.h"
#include "KEYPAD_Config.h"

#include "util/delay.h"


void KEYPAD_enumInit(void)
{
	// Step1: Configure Keypad Columns C1:C4 as an OUTPUT
	DIO_enumSetPinDirection(COL_PORT, COL0_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(COL_PORT, COL1_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(COL_PORT, COL2_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(COL_PORT, COL3_PIN, DIO_OUTPUT);

	// Step2: Initialize Columns Pins to HIGH
	DIO_enumSetPinValue(COL_PORT, COL0_PIN, HIGH);
	DIO_enumSetPinValue(COL_PORT, COL1_PIN, HIGH);
	DIO_enumSetPinValue(COL_PORT, COL2_PIN, HIGH);
	DIO_enumSetPinValue(COL_PORT, COL3_PIN, HIGH);

	// Step3: Configure Keypad Rows R1:R4 as an INPUT
	DIO_enumSetPinDirection(ROW_PORT, ROW0_PIN, DIO_INPUT);
	DIO_enumSetPinDirection(ROW_PORT, ROW1_PIN, DIO_INPUT);
	DIO_enumSetPinDirection(ROW_PORT, ROW2_PIN, DIO_INPUT);
	DIO_enumSetPinDirection(ROW_PORT, ROW3_PIN, DIO_INPUT);

	// Step4: Configure Keypad Rows INPUT Mode to Pull_UP
	DIO_enumSetInputMode(ROW_PORT, ROW0_PIN, DIO_PULL_UP);
	DIO_enumSetInputMode(ROW_PORT, ROW1_PIN, DIO_PULL_UP);
	DIO_enumSetInputMode(ROW_PORT, ROW2_PIN, DIO_PULL_UP);
	DIO_enumSetInputMode(ROW_PORT, ROW3_PIN, DIO_PULL_UP);
}

u8 KEYPAD_u8GetPressedKey(void)
{
	u8 Local_u8returnValue =  KEYPAD_NO_PRESSED_KEY;

	u8 col_index, row_index;
	u8 button_state;
	u8 Local_u8KeypadArr [KEYPAD_ROWS][KEYPAD_COLS] = KEYPAD_ARR;

	// Nested For to check the pressed key
	for(col_index = COL0_PIN; col_index <= COL3_PIN ;col_index++)
	{
		// Set col_index value to 0
		DIO_enumSetPinValue(COL_PORT, col_index, LOW);

		// check input
		for(row_index = ROW0_PIN; row_index <= ROW3_PIN ;row_index++)
		{
			// Get Row value and assign to Copy_u8PressedKey
			DIO_enumGetPinValue(ROW_PORT, row_index, &button_state);
			if(button_state == LOW)
			{
				Local_u8returnValue = Local_u8KeypadArr[row_index-ROW0_PIN][col_index-COL0_PIN];

				// Single press "Busy Waiting"
				while(button_state == LOW)
				{
					DIO_enumGetPinValue(ROW_PORT, row_index, &button_state);
				}
				//de bouncing button
				_delay_ms(10);
			}
		}
		// Return col state to high
		DIO_enumSetPinValue(COL_PORT, col_index, HIGH);
	}

	return Local_u8returnValue;
}

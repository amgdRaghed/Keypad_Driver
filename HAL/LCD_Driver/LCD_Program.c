/*
 * LCD_Program.c
 *
 *  Created on: Nov 14, 2021
 *      Author: amgdRaghed
 */

/* Include LIB Layer */
#include "std_Types.h"
#include "errorState.h"

/* Include MCAL Layer */
#include "DIO_Interface.h"

/* Include HAL Layer */
#include "LCD_Config.h"
#include "LCD_Private.h"

#include <util/delay.h>


ES_t LCD_enumInit(void)
{
	ES_t Local_enumErrorState = ES_NOK;

	// Step1: Configure control pins and data pins as DIO_OUTPUT
	DIO_enumSetPinDirection(RS_PORT, RS_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(RW_PORT, RW_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(E_PORT,  E_PIN,  DIO_OUTPUT);

	DIO_enumSetPinDirection(D7_PORT, D7_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D6_PORT, D6_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D5_PORT, D5_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D4_PORT, D4_PIN, DIO_OUTPUT);

#if LCD_MODE == EIGHT_BIT

	DIO_enumSetPinDirection(D3_PORT, D3_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D2_PORT, D2_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D1_PORT, D1_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D0_PORT, D0_PIN, DIO_OUTPUT);

	// Step2: Wait and Send Function Set Command for EIGHT_BIT Mode
	_delay_ms(35);
	DIO_enumSetPinValue(RS_PORT, RS_PIN, LOW);
	WriteNLatch(FUNCTION_SET_EIGHT_BIT);

#elif LCD_MODE == FOUR_BIT

	// Step2: Wait and Send Function Set Command for FOUR_BIT Mode
	_delay_ms(35);
	DIO_enumSetPinValue(RS_PORT, RS_PIN, LOW);
	WriteNLatch(FUNCTION_SET_FOUR_BIT);

#endif

	// Step3: Wait and Send display control Command
	_delay_ms(1);
	DIO_enumSetPinValue(RS_PORT, RS_PIN, LOW);
	WriteNLatch(DISPLAY_CONTROL);

	// Step4: Wait and Send Clear display Command
	_delay_ms(1);
	DIO_enumSetPinValue(RS_PORT, RS_PIN, LOW);
	WriteNLatch(CLEAR_DISPLAY);

	// Step5: Wait and Send Entry Mode Set Command
	_delay_ms(2);
	DIO_enumSetPinValue(RS_PORT, RS_PIN, LOW);
	WriteNLatch(ENTRY_MODE);

	return Local_enumErrorState;
}



ES_t LCD_enumSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enumErrorState = ES_NOK;

	//Set RS_Pin as LOW to send command
	DIO_enumSetPinValue(RS_PORT, RS_PIN, LOW);

	//Call WriteNLatch Static Function
	WriteNLatch(Copy_u8Command);

	return Local_enumErrorState;
}



ES_t LCD_enumSendData(u8 Copy_u8Data)
{
	ES_t Local_enumErrorState = ES_NOK;

	//Set RS_Pin as HIGH to send Data
	DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);

	//Call WriteNLatch Static Function
	WriteNLatch(Copy_u8Data);

	return Local_enumErrorState;
}



ES_t LCD_enumSendString(const char* Copy_ccString)
{
	ES_t Local_enumErrorState = ES_NOK;

	if(Copy_ccString != NULL)
	{
		while(*Copy_ccString != '\0')
		{
			//Send Data Function
			DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);
			WriteNLatch( *Copy_ccString++ );
		}
	}
	else
	{
		Local_enumErrorState = ES_NULL_POINTER;
	}


	return Local_enumErrorState;
}


ES_t LCD_enumCursorPosition(u8 Copy_u8Row, u8 Copy_u8Col)
{
	ES_t Local_enumErrorState = ES_NOK;

	if( ((Copy_u8Row>=ROW_1) & (Copy_u8Row<=ROW_2)) && ((Copy_u8Col>=COL_1) & (Copy_u8Col<=COL_16)) )
	{
		u8 Local_u8RowLocation[2] = {FORCE_CURSOR_START_FIRST_LINE, FORCE_CURSOR_START_SECOND_LINE};

		//Send Command
		DIO_enumSetPinValue(RS_PORT, RS_PIN, LOW);
		WriteNLatch( ((Local_u8RowLocation[Copy_u8Row-BIT_ONE])+(Copy_u8Col-BIT_ONE)) );

		Local_enumErrorState = ES_OK;
	}
	else
	{
		Local_enumErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enumErrorState;
}


ES_t LCD_enumSendInteger(s64 Copy_s64Int)
{
	ES_t Local_enumErrorState = ES_NOK;

	s64 Local_s32Reverse = LCD_ONE;
	u8  Local_s32Reminder;

	// Check for Negative Number
	if (Copy_s64Int < LCD_ZERO)
	{
		Copy_s64Int *= -LCD_ONE;
		//Send Data Function
		DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);
		WriteNLatch(ASCII_MINUS);
	}

	// Check for ZERO Number
	if (Copy_s64Int == LCD_ZERO)
	{
		//Send Data Function
		DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);
		WriteNLatch(ASCII_ZER0);
	}

	// Reverse the Number to Send
	while(Copy_s64Int)
	{
		Local_s32Reminder = Copy_s64Int % BASE_TEN;
		Local_s32Reverse = Local_s32Reverse*LCD_TEN + Local_s32Reminder;
		Copy_s64Int /= LCD_TEN;
	}

	// Send the Number to LCD
	while(Local_s32Reverse != LCD_ONE)
	{
		//Send Data Function
		DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);
		WriteNLatch( (Local_s32Reverse % BASE_TEN) +ASCII_ZER0 );

		Local_s32Reverse /= LCD_TEN;
	}

	return Local_enumErrorState;
}


ES_t LCD_enumSendFloat(f32 Copy_f32Float)
{
	ES_t Local_enumErrorState = ES_NOK;

	// Check for Negative Number
	if (Copy_f32Float < LCD_ZERO)
	{
		Copy_f32Float *= -LCD_ONE;
		//Send Data Function
		DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);
		WriteNLatch(ASCII_MINUS);
	}

	// Check for ZERO Number
	if (Copy_f32Float == LCD_ZERO)
	{
		//Send Data Function
		DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);
		WriteNLatch(ASCII_ZER0);
	}

	// Separate Float Number into Integer and Decimal										// Float Number = 100.56 , 10.3 , 5.53
	u32 Local_u32NumWithoutDecimalPoint = Copy_f32Float*100;								// NumWithoutDecimalPoint = Float Number*100 = 10056 , 1030 , 553
	u32 Local_u32IntegerNum = Local_u32NumWithoutDecimalPoint/100;							// Integer Number = NumWithoutDecimalPoint/100 = 100 , 10 , 5
	u8  Local_u8DecimalNum  = Local_u32NumWithoutDecimalPoint-(Local_u32IntegerNum*100);	// Decimal Number = NumWithoutDecimalPoint - (Integer Number*100) = 56 , 30 , 53

	// Send Integer Number
	SendNumber(Local_u32IntegerNum);

	// Send Decimal Point '.' using Send Data Function
	DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);
	WriteNLatch(ASCII_DOT);

	// Send Decimal Number
	SendNumber(Local_u8DecimalNum);

	return Local_enumErrorState;
}


static ES_t SendNumber(u32 Copy_u32Num)
{
	ES_t Local_enumErrorState = ES_NOK;

	s32 Local_s32Reverse = LCD_ONE;
	u8  Local_s32Reminder;

	// Check for ZERO Number
	if (Copy_u32Num == LCD_ZERO)
	{
		//Send Data Function
		DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);
		WriteNLatch(ASCII_ZER0);
	}

	// Reverse the Number to Send
	while(Copy_u32Num)
	{
		Local_s32Reminder = Copy_u32Num % BASE_TEN;
		Local_s32Reverse = Local_s32Reverse*LCD_TEN + Local_s32Reminder;
		Copy_u32Num /= LCD_TEN;
	}

	// Send the Number to LCD
	while(Local_s32Reverse != LCD_ONE)
	{
		//Send Data Function
		DIO_enumSetPinValue(RS_PORT, RS_PIN, HIGH);
		WriteNLatch( (Local_s32Reverse % BASE_TEN) +ASCII_ZER0 );

		Local_s32Reverse /= LCD_TEN;
	}

	return Local_enumErrorState;
}


static ES_t WriteNLatch (u8 Copy_u8Byte)
{
	ES_t Local_enumErrorState = ES_NOK;

	//Step1: Initialize RW_PIN & E_PIN with LOW
	DIO_enumSetPinValue(RW_PORT, RW_PIN, LOW);
	DIO_enumSetPinValue(E_PORT, E_PIN, LOW);

	//Step2: Write Byte on LCD Data Pins for EIGHT_BIT Configuration
#if LCD_MODE == EIGHT_BIT

	DIO_enumSetPinValue(D0_PORT, D0_PIN, ( (Copy_u8Byte >> BIT0) & BIT_ONE) );
	DIO_enumSetPinValue(D1_PORT, D1_PIN, ( (Copy_u8Byte >> BIT1) & BIT_ONE) );
	DIO_enumSetPinValue(D2_PORT, D2_PIN, ( (Copy_u8Byte >> BIT2) & BIT_ONE) );
	DIO_enumSetPinValue(D3_PORT, D3_PIN, ( (Copy_u8Byte >> BIT3) & BIT_ONE) );
	DIO_enumSetPinValue(D4_PORT, D4_PIN, ( (Copy_u8Byte >> BIT4) & BIT_ONE) );
	DIO_enumSetPinValue(D5_PORT, D5_PIN, ( (Copy_u8Byte >> BIT5) & BIT_ONE) );
	DIO_enumSetPinValue(D6_PORT, D6_PIN, ( (Copy_u8Byte >> BIT6) & BIT_ONE) );
	DIO_enumSetPinValue(D7_PORT, D7_PIN, ( (Copy_u8Byte >> BIT7) & BIT_ONE) );

	//Step3: Falling edge trigger
	DIO_enumSetPinValue(E_PORT,E_PIN, HIGH);
	_delay_ms(5);
	DIO_enumSetPinValue(E_PORT, E_PIN, LOW);
	_delay_ms(5);


#elif LCD_MODE == FOUR_BIT

	//Step2: Write Byte on LCD Data Pins for FOUR_BIT Configuration
	//Function Set command need to send in 3 steps
	if (Copy_u8Byte == FUNCTION_SET_FOUR_BIT)
	{
		// Write Upper 4-bit
		DIO_enumSetPinValue(D4_PORT, D4_PIN, ( (Copy_u8Byte >> BIT4) & BIT_ONE) );
		DIO_enumSetPinValue(D5_PORT, D5_PIN, ( (Copy_u8Byte >> BIT5) & BIT_ONE) );
		DIO_enumSetPinValue(D6_PORT, D6_PIN, ( (Copy_u8Byte >> BIT6) & BIT_ONE) );
		DIO_enumSetPinValue(D7_PORT, D7_PIN, ( (Copy_u8Byte >> BIT7) & BIT_ONE) );

		//Falling edge trigger
		DIO_enumSetPinValue(E_PORT,E_PIN, HIGH);
		_delay_ms(5);
		DIO_enumSetPinValue(E_PORT, E_PIN, LOW);
		_delay_ms(5);
	}

	// Write Upper 4-bit
	DIO_enumSetPinValue(D4_PORT, D4_PIN, ( (Copy_u8Byte >> BIT4) & BIT_ONE) );
	DIO_enumSetPinValue(D5_PORT, D5_PIN, ( (Copy_u8Byte >> BIT5) & BIT_ONE) );
	DIO_enumSetPinValue(D6_PORT, D6_PIN, ( (Copy_u8Byte >> BIT6) & BIT_ONE) );
	DIO_enumSetPinValue(D7_PORT, D7_PIN, ( (Copy_u8Byte >> BIT7) & BIT_ONE) );

	//Falling edge trigger
	DIO_enumSetPinValue(E_PORT,E_PIN, HIGH);
	_delay_ms(5);
	DIO_enumSetPinValue(E_PORT, E_PIN, LOW);
	_delay_ms(5);

	// Write Lower 4-bit
	DIO_enumSetPinValue(D4_PORT, D4_PIN, ( (Copy_u8Byte >> BIT0) & BIT_ONE) );
	DIO_enumSetPinValue(D5_PORT, D5_PIN, ( (Copy_u8Byte >> BIT1) & BIT_ONE) );
	DIO_enumSetPinValue(D6_PORT, D6_PIN, ( (Copy_u8Byte >> BIT2) & BIT_ONE) );
	DIO_enumSetPinValue(D7_PORT, D7_PIN, ( (Copy_u8Byte >> BIT3) & BIT_ONE) );

	//Falling edge trigger
	DIO_enumSetPinValue(E_PORT,E_PIN, HIGH);
	_delay_ms(5);
	DIO_enumSetPinValue(E_PORT, E_PIN, LOW);
	_delay_ms(5);

#endif

	return Local_enumErrorState;
}

/*
 *   File Name: DIO_PROGRAM.c
 *
 *  Created on: Nov 12, 2021
 *      Author: amgdRaghed
 */

/* Include Lib Layer */
#include "std_Types.h"
#include "errorState.h"

/* Include MCAL Layer */
#include "DIO_PRIVATE.h"


ES_t DIO_enumSetPinDirection (u8 Copy_u8PortID, u8 Copy_u8PinNum, u8 Copy_u8Direction)
{
	ES_t Local_enumErrorState = ES_NOK;

	if(Copy_u8PortID <= DIO_PORTD
		&& Copy_u8PinNum <= DIO_PIN7
		&& Copy_u8Direction <= DIO_OUTPUT)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA:
			DIO_DDRA_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_DDRA_REG |=  (Copy_u8Direction << Copy_u8PinNum);
			break;

		case DIO_PORTB:
			DIO_DDRB_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_DDRB_REG |=  (Copy_u8Direction << Copy_u8PinNum);
			break;

		case DIO_PORTC:
			DIO_DDRC_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_DDRC_REG |=  (Copy_u8Direction << Copy_u8PinNum);
			break;

		case DIO_PORTD:
			DIO_DDRD_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_DDRD_REG |=  (Copy_u8Direction << Copy_u8PinNum);
			break;
		}
		Local_enumErrorState = ES_OK;
	}
	else
	{
		Local_enumErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enumErrorState;
}

ES_t DIO_enumSetInputMode (u8 Copy_u8PortID, u8 Copy_u8PinNum, u8 Copy_u8Mode)
{
	ES_t Local_enumErrorState = ES_NOK;

	if (Copy_u8PortID <= DIO_PORTD
		&& Copy_u8PinNum <= DIO_PIN7
		&& Copy_u8Mode <= DIO_PULL_UP)
	{
		switch (Copy_u8PortID)
		{
		case DIO_PORTA:
			DIO_PORTA_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_PORTA_REG |=  (Copy_u8Mode << Copy_u8PinNum);
			break;

		case DIO_PORTB:
			DIO_PORTB_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_PORTB_REG |=  (Copy_u8Mode << Copy_u8PinNum);
			break;

		case DIO_PORTC:
			DIO_PORTC_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_PORTC_REG |=  (Copy_u8Mode << Copy_u8PinNum);
			break;

		case DIO_PORTD:
			DIO_PORTD_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_PORTD_REG |=  (Copy_u8Mode << Copy_u8PinNum);
			break;
		}
		Local_enumErrorState = ES_OK;
	}
	else
	{
		Local_enumErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enumErrorState;
}

ES_t DIO_enumSetPinValue (u8 Copy_u8PortID, u8 Copy_u8PinNum, u8 Copy_u8SetValue)
{
	ES_t Local_enumErrorState = ES_NOK;

	if (Copy_u8PortID <= DIO_PORTD
		&& Copy_u8PinNum <= DIO_PIN7
		&& Copy_u8SetValue <= HIGH)
	{
		switch (Copy_u8PortID)
		{
		case DIO_PORTA:
			DIO_PORTA_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_PORTA_REG |=  (Copy_u8SetValue << Copy_u8PinNum);
			break;

		case DIO_PORTB:
			DIO_PORTB_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_PORTB_REG |=  (Copy_u8SetValue << Copy_u8PinNum);
			break;

		case DIO_PORTC:
			DIO_PORTC_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_PORTC_REG |=  (Copy_u8SetValue << Copy_u8PinNum);
			break;

		case DIO_PORTD:
			DIO_PORTD_REG &= ~(DIO_BIT_MASK << Copy_u8PinNum);
			DIO_PORTD_REG |=  (Copy_u8SetValue << Copy_u8PinNum);
			break;
		}
		Local_enumErrorState = ES_OK;
	}
	else
	{
		Local_enumErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enumErrorState;
}

ES_t DIO_enumGetPinValue (u8 Copy_u8PortID, u8 Copy_u8PinNum, u8*Copy_pu8GetValue)
{
	ES_t Local_enumErrorState = ES_NOK;

	if (Copy_pu8GetValue != NULL)
	{
		if(Copy_u8PortID <= DIO_PORTD
			&& Copy_u8PinNum <= DIO_PIN7)
		{
			switch (Copy_u8PortID)
			{
			case DIO_PORTA:
				*Copy_pu8GetValue = ( (DIO_PINA_REG >> Copy_u8PinNum) & DIO_BIT_ONE);
				break;

			case DIO_PORTB:
				*Copy_pu8GetValue = ( (DIO_PINB_REG >> Copy_u8PinNum) & DIO_BIT_ONE);
				break;

			case DIO_PORTC:
				*Copy_pu8GetValue = ( (DIO_PINC_REG >> Copy_u8PinNum) & DIO_BIT_ONE);
				break;

			case DIO_PORTD:
				*Copy_pu8GetValue = ( (DIO_PIND_REG >> Copy_u8PinNum) & DIO_BIT_ONE);
				break;
			}
			Local_enumErrorState = ES_OK;
		}
		else
		{
			Local_enumErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enumErrorState = ES_NULL_POINTER;
	}

	return Local_enumErrorState;
}

ES_t DIO_enumTogglePin (u8 Copy_u8PortID, u8 Copy_u8PinNum)
{
	ES_t Local_enumErrorState = ES_NOK;

	if (Copy_u8PortID <= DIO_PORTD
		&& Copy_u8PinNum < DIO_PIN7)
	{
		switch (Copy_u8PortID)
		{
		case DIO_PORTA :
			DIO_PORTA_REG ^= (DIO_BIT_MASK << Copy_u8PinNum);
			break;

		case DIO_PORTB :
			DIO_PORTB_REG ^= (DIO_BIT_MASK << Copy_u8PinNum);
			break;

		case DIO_PORTC :
			DIO_PORTC_REG ^= (DIO_BIT_MASK << Copy_u8PinNum);
			break;

		case DIO_PORTD :
			DIO_PORTD_REG ^= (DIO_BIT_MASK << Copy_u8PinNum);
			break;
		}
		Local_enumErrorState = ES_OK;
	}
	else
	{
		Local_enumErrorState = ES_OUT_OF_RANGE;
	}


	return Local_enumErrorState;
}

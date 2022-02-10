/*
 *   File Name: DIO_Interface.h
 *
 *  Created on: Nov 12, 2021
 *      Author: amgdRaghed
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/*   Prototypes User APIs   */
ES_t DIO_enumInit            (void);

ES_t DIO_enumSetPinDirection (u8 Copy_u8PortID, u8 Copy_u8PinNum, u8 Copy_u8Direction);

ES_t DIO_enumSetInputMode    (u8 Copy_u8PortID, u8 Copy_u8PinNum, u8 Copy_u8Mode);

ES_t DIO_enumSetPinValue     (u8 Copy_u8PortID, u8 Copy_u8PinNum, u8 Copy_u8SetValue);

ES_t DIO_enumGetPinValue     (u8 Copy_u8PortID, u8 Copy_u8PinNum, u8*Copy_pu8GetValue);

ES_t DIO_enumTogglePin       (u8 Copy_u8PortID, u8 Copy_u8PinNum);

/* Definitions of ATmega32 DIO Port ID */
#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

/* Definitions of ATmega32 DIO Pin Number */
#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

/* Definitions of ATmega32 DIO Pin Direction */
#define DIO_INPUT		0
#define DIO_OUTPUT		1

/* Definitions of ATmega32 DIO Pin Input Mode */
#define DIO_FLOATING	0
#define DIO_PULL_UP		1

#endif /* DIO_INTERFACE_H_ */

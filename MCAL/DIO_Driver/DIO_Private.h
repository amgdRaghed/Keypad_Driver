/*
 *   File Name: DIO_PRIVATE.h
 *
 *  Created on: Nov 12, 2021
 *      Author: amgdRaghed
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* Definitions of Magic Number */
#define DIO_BIT_MASK		1
#define DIO_BIT_ONE			1

/*   Definitions of ATmega32 DIO Registers   */
#define DIO_PORTA_REG		*((volatile u8*)0x3B)
#define DIO_DDRA_REG		*((volatile u8*)0x3A)
#define DIO_PINA_REG		*((volatile u8*)0x39)

#define DIO_PORTB_REG		*((volatile u8*)0x38)
#define DIO_DDRB_REG		*((volatile u8*)0x37)
#define DIO_PINB_REG		*((volatile u8*)0x36)

#define DIO_PORTC_REG		*((volatile u8*)0x35)
#define DIO_DDRC_REG		*((volatile u8*)0x34)
#define DIO_PINC_REG		*((volatile u8*)0x33)

#define DIO_PORTD_REG		*((volatile u8*)0x32)
#define DIO_DDRD_REG		*((volatile u8*)0x31)
#define DIO_PIND_REG		*((volatile u8*)0x30)

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

#endif /* DIO_PRIVATE_H_ */

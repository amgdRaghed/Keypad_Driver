/*
 * ATmega32_Reg.h
 *
 *  Created on: Nov 12, 2021
 *      Author: amgdRaghed
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define		SET_BIT(Reg,Bit)	Reg |=  ( 1 << (Bit) )
#define		CLR_BIT(Reg,Bit)	Reg &= ~( 1 << (Bit) )
#define		TOG_BIT(Reg,Bit)	Reg ^=  ( 1 << (Bit) )
#define		GET_BIT(Reg,Bit)	( (Reg) >> (Bit) ) & (0x01) )


#endif /* BIT_MATH_H_ */
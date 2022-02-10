/*
 * LCD_Private.h
 *
 *  Created on: Nov 14, 2021
 *      Author: amgdRaghed
 */

#ifndef LCD_DRIVER_LCD_PRIVATE_H_
#define LCD_DRIVER_LCD_PRIVATE_H_

/*             LCD Mode             */
#define EIGHT_BIT		8
#define FOUR_BIT		4

/*            LCD Command           */
#define FUNCTION_SET_EIGHT_BIT	0x38
#define FUNCTION_SET_FOUR_BIT	0x28

#define DISPLAY_CONTROL 		0x0F

#define CLEAR_DISPLAY			0x01

#define ENTRY_MODE				0x06

/*            LCD Positions           */
#define  ROW_1					1
#define  ROW_2					2

#define  COL_1					1
#define  COL_2					2
#define  COL_3					3
#define  COL_4					4
#define  COL_5					5
#define  COL_6					6
#define  COL_7					7
#define  COL_8					8
#define  COL_9					9
#define  COL_10					10
#define  COL_11					11
#define  COL_12					12
#define  COL_13					13
#define  COL_14					14
#define  COL_15					15
#define  COL_16					16

/*                       LCD Command                      */
#define FORCE_CURSOR_START_FIRST_LINE					0x80
#define FORCE_CURSOR_START_SECOND_LINE					0xC0

/*          Local Function          */
static ES_t WriteNLatch (u8 Copy_u8Byte);
static ES_t SendNumber	(u32 Copy_u32Num);

/*           Magic Number           */
#define BIT0			0
#define BIT1			1
#define BIT2			2
#define BIT3			3
#define BIT4			4
#define BIT5			5
#define BIT6			6
#define BIT7			7

#define BIT_ONE 		1

#define LCD_ZERO		0
#define LCD_ONE			1
#define LCD_TEN			10
#define BASE_TEN		10

#define ASCII_MINUS 	'-'
#define ASCII_ZER0		'0'
#define ASCII_DOT		'.'

#endif /* LCD_DRIVER_LCD_PRIVATE_H_ */

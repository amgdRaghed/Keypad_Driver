/*
 * LCD_Interface.h
 *
 *  Created on: Nov 14, 2021
 *      Author: amgdRaghed
 */

#ifndef LCD_DRIVER_LCD_INTERFACE_H_
#define LCD_DRIVER_LCD_INTERFACE_H_

ES_t LCD_enumInit(void);

ES_t LCD_enumSendCommand(u8 Copy_u8Command);

ES_t LCD_enumSendData(u8 Copy_u8Data);

ES_t LCD_enumSendString(const char* Copy_ccString);

ES_t LCD_enumCursorPosition(u8 Copy_u8Row, u8 Copy_u8Col);

ES_t LCD_enumSendInteger(s64 Copy_s64Int);

ES_t LCD_enumSendFloat(f32 Copy_f32Float);


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

#define 	CLEAR_DISPLAY								0x01
#define 	RETURN_HOME									0x02

#define 	DECREMENT_CURSOR_TO_LEFT					0x04
#define 	INCREMENT_CURSOR_TO_RIGHT					0x06

#define 	SHIFT_DISPLAY_TO_RIGHT						0x05
#define 	SHIFT_DISPLAY_TO_LEFT						0x07


#define 	DISPLAY_OFF_CURSOR_OFF						0x08
#define 	DISPLAY_OFF_CURSOR_ON						0x0A
#define 	DISPLAY_ON_CURSOR_OFF						0x0C
#define 	DISPLAY_ON_CURSOR_BLINK						0x0E


#define 	SHIFT_CURSOR_POSITION_TO_LEFT				0x10
#define 	SHIFT_CURSOR_POSITION_TO_RIGHT				0x14

#define 	SHIFT_ENTRIE_DISPLAY_TO_LEFT				0x18
#define 	SHIFT_ENTRIE_DISPLAY_TO_RIGHT				0x1C

#define 	FORCE_CURSOR_START_FIRST_LINE				0x80
#define 	FORCE_CURSOR_START_SECOND_LINE				0xC0

#define     GO_TO_CGRAM									0x40

#endif /* LCD_DRIVER_LCD_INTERFACE_H_ */

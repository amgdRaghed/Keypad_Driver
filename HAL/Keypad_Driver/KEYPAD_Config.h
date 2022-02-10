/*
 * KEYPAD_Config.h
 *
 *  Created on: Nov 15, 2021
 *      Author: amgdRaghed
 */

#ifndef KEYPAD_DRIVER_KEYPAD_CONFIG_H_
#define KEYPAD_DRIVER_KEYPAD_CONFIG_H_

/*   Keypad Columns & ROWs Port   */
#define COL_PORT		DIO_PORTC
#define ROW_PORT		DIO_PORTC

/*    Keypad Rows Pins    */
#define ROW0_PIN		DIO_PIN0
#define ROW1_PIN		DIO_PIN1
#define ROW2_PIN		DIO_PIN2
#define ROW3_PIN		DIO_PIN3

/*   Keypad Columns Pins   */
#define COL0_PIN		DIO_PIN4
#define COL1_PIN		DIO_PIN5
#define COL2_PIN		DIO_PIN6
#define COL3_PIN		DIO_PIN7

/*    Keypad Buttons    */
#define KEYPAD_ARR  { {'7','8','9','/'}, {'4','5','6','x'}, {'1','2','3','-'}, {'C','0','=','+'} }

#endif /* KEYPAD_DRIVER_KEYPAD_CONFIG_H_ */

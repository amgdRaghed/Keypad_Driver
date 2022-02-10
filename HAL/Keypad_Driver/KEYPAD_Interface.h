/*
 * KEYPAD_Interface.h
 *
 *  Created on: Nov 15, 2021
 *      Author: amgdRaghed
 */

#ifndef KEYPAD_DRIVER_KEYPAD_INTERFACE_H_
#define KEYPAD_DRIVER_KEYPAD_INTERFACE_H_

void KEYPAD_enumInit(void);

u8 KEYPAD_u8GetPressedKey(void);

#define KEYPAD_NO_PRESSED_KEY  	0
#define KEYPAD_CLEAR			'C'

#endif /* KEYPAD_DRIVER_KEYPAD_INTERFACE_H_ */

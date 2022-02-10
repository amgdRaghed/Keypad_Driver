/*
 * LCD_Config.h
 *
 *  Created on: Nov 14, 2021
 *      Author: amgdRaghed
 */

#ifndef LCD_DRIVER_LCD_CONFIG_H_
#define LCD_DRIVER_LCD_CONFIG_H_

/*             LCD Mode             */
/*	Choose EIGHT_BIT  or  FOUR_BIT  */
#define LCD_MODE 	EIGHT_BIT


/*   LCD Control Pins   */
#define RS_PORT		DIO_PORTC
#define RS_PIN		DIO_PIN0

#define RW_PORT		DIO_PORTC
#define RW_PIN		DIO_PIN1

#define E_PORT		DIO_PORTC
#define E_PIN		DIO_PIN2


/*    LCD Data Pins    */
#define D0_PORT		DIO_PORTD
#define D0_PIN		DIO_PIN0

#define D1_PORT		DIO_PORTD
#define D1_PIN		DIO_PIN1

#define D2_PORT		DIO_PORTD
#define D2_PIN		DIO_PIN2

#define D3_PORT		DIO_PORTD
#define D3_PIN		DIO_PIN3

#define D4_PORT		DIO_PORTD
#define D4_PIN		DIO_PIN4

#define D5_PORT		DIO_PORTD
#define D5_PIN		DIO_PIN5

#define D6_PORT		DIO_PORTD
#define D6_PIN		DIO_PIN6

#define D7_PORT		DIO_PORTD
#define D7_PIN		DIO_PIN7



#endif /* LCD_DRIVER_LCD_CONFIG_H_ */

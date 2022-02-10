/*
 * std_Types.h
 *
 *  Created on: Nov 12, 2021
 *      Author: amgdRaghed
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*  Definition of NULL Address  */
#ifndef NULL
#define NULL	((void*)0)
#endif


/*  Boolean Values  */
#ifndef HIGH
#define HIGH 	1u
#endif

#ifndef LOW
#define LOW		0u
#endif

#ifndef TRUE
#define TRUE	1u
#endif

#ifndef FALSE
#define FALSE 	0u
#endif


/*  typedef <dataType> <newName>  */
typedef unsigned char	 		 u8;		/*                            0 .. 255                         */
typedef signed   char	 		 s8;		/*                         -128 .. +127                        */

typedef	unsigned short 			u16;		/*                            0 .. 65,535                      */
typedef	signed   short 			s16;		/*                      -32,768 .. +32,767                     */

typedef unsigned long 			u32;		/*                            0 .. 4,294,967,295               */
typedef signed   long 			s32;		/*               -2,147,483,648 .. 2,147,483,647               */

typedef unsigned long long		u64;		/*                            0 .. 18,446,744,073,709,551,615  */
typedef signed   long long		s64;		/*   -9,223,372,036,854,775,808 .. 9,223,372,036,854,775,807   */

typedef float 					f32;		/*   -3.4E+38 .. +3.4E+38   Accuracy: 6 decimal digit  */
typedef double					f64;		/*  -1.7E+308 .. +1.7E+308  Accuracy: 6 decimal digit  */

#endif /* STD_TYPES_H_ */

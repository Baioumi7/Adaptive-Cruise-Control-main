/*=================================================================================*/
/*  File        : GPIO_Program.c                                                   */
/*  Description : This Program file includes GPIO Program for STM32f103C8T6        */
/*  Author      : Ahmed bayoumii                   Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bayoumii77/             */
/*  Git account : https://github.com/Baioumi7				               */
/*  mail        : ahmedbayoumii2024@gmil.com                                         */
/*=================================================================================*/
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short int u16;
typedef signed short int   s16;
typedef unsigned long int  u32;
typedef signed long int    s32;
typedef float              f32;
typedef double             f64;
typedef long double        f128;
typedef void(*fptr_t)(void);

#define STD_TYPES_OK            1
#define STD_TYPES_NOK           0

#define NULL                   ((void*)0)
#define F_CPU				8000000 /* 8Mhz */

#endif

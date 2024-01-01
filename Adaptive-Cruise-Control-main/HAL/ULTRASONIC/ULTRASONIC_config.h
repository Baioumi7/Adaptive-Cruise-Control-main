/*=================================================================================*/
/*  File        : GPIO_Program.c                                                   */
/*  Description : This Program file includes GPIO Program for STM32f103C8T6        */
/*  Author      : Ahmed bayoumii                   Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bayoumii77/             */
/*  Git account : https://github.com/Baioumi7				               */
/*  mail        : ahmedbayoumii2024@gmil.com                                         */
/*=================================================================================*/
#ifndef HAL_ULTRASONIC_CONFIG_H_
#define HAL_ULTRASONIC_CONFIG_H_

#define ULTRASONIC_TRIGGER_PORT_ID           GPIO_u8_GPIOA
#define ULTRASONIC_TRIGGER_PIN_ID            GPIO_u8_PIN7

#define ULTRASONIC_ECHO_PORT_ID              GPIO_u8_GPIOB
#define ULTRASONIC_ECHO_PIN_ID               GPIO_u8_PIN0

#define ULTRASONIC_TIMER                     TIMER_u8_3
#define ULTRASONIC_TIMER_CHANNEL             CC3

#endif /* HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_ */

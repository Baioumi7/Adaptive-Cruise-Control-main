/*=================================================================================*/
/*  File        : GPIO_Program.c                                                   */
/*  Description : This Program file includes GPIO Program for STM32f103C8T6        */
/*  Author      : Ahmed bayoumii                   Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bayoumii77/             */
/*  Git account : https://github.com/Baioumi7				               */
/*  mail        : ahmedbayoumii2024@gmil.com                                         */
/*=================================================================================*/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "LIB/stm32f103xx.h"

#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/STK/STK_interface.h"

#include "HAL/ULTRASONIC/ULTRASONIC_Interface.h"
#include "HAL/MOTOR_DRIVER/MOTOR_Interface.h"

#define MINIMUM_DISTANCE     10
#define SAVE_DISTANCE        20
#define STOP_DISTANCE        4

#define MAX_SPEED            80
#define MIN_SPEED            15
#define START_SPEED          10
#define ZERO_SPEED           0

int main(void)
{
	u16 Ultrasonic_u16DistanceValue;
	u8 Current_Speed = 0, min_speed_flag = 1;

	RCC_u8InitSysClk();

	RCC_u8EnableDisablPeripheralClk(RCC_u8_AFIO, RCC_u8_Enable);

	RCC_u8EnableDisablPeripheralClk(RCC_u8_TIM1, RCC_u8_Enable);
	RCC_u8EnableDisablPeripheralClk(RCC_u8_TIM2, RCC_u8_Enable);
	RCC_u8EnableDisablPeripheralClk(RCC_u8_TIM3, RCC_u8_Enable);

	RCC_u8EnableDisablPeripheralClk(RCC_u8_GPIOA, RCC_u8_Enable);
	RCC_u8EnableDisablPeripheralClk(RCC_u8_GPIOB, RCC_u8_Enable);
	RCC_u8EnableDisablPeripheralClk(RCC_u8_GPIOC, RCC_u8_Enable);

	STK_u8Init(STK_u8_AHB);

	Ultrasonic_init();

	MOTORS_voidInit();

	for(;;)
	{
		Ultrasonic_u16DistanceValue = Ultrasonic_readDistance_average();

		if (Ultrasonic_u16DistanceValue >= MAX_SPEED)
		{
			Ultrasonic_u16DistanceValue = MAX_SPEED;
			min_speed_flag  = 1;
		}

		if(Ultrasonic_u16DistanceValue <= MINIMUM_DISTANCE && Ultrasonic_u16DistanceValue > STOP_DISTANCE)
		{
			if(min_speed_flag)
			{
				MOTORS_voidForward(MAX_SPEED);
				STK_u8SetmSBusyWait(3);
				min_speed_flag = 0;
			}
			Current_Speed = START_SPEED;
		}
		else if(Ultrasonic_u16DistanceValue > MINIMUM_DISTANCE && Ultrasonic_u16DistanceValue <= SAVE_DISTANCE)
		{
			Current_Speed = MIN_SPEED;
			min_speed_flag  = 1;
		}
		else if (Ultrasonic_u16DistanceValue > SAVE_DISTANCE)
		{
			Current_Speed = Ultrasonic_u16DistanceValue ;
			min_speed_flag  = 1;
		}
		else if(Ultrasonic_u16DistanceValue <= STOP_DISTANCE)
		{
			Current_Speed = ZERO_SPEED;
			min_speed_flag  = 1;
		}

		MOTORS_voidForward(Current_Speed);

		STK_u8SetmSBusyWait(10);

	}
}

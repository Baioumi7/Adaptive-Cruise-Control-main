/*=================================================================================*/
/*  File        : GPIO_Program.c                                                   */
/*  Description : This Program file includes GPIO Program for STM32f103C8T6        */
/*  Author      : Ahmed bayoumii                   Embedded SW Engineer           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bayoumii77/             */
/*  Git account : https://github.com/Baioumi7				               */
/*  mail        : ahmedbayoumii2024@gmil.com                                         */
/*=================================================================================*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/GPT/GPT_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"

#include "MOTOR_config.h"
#include "MOTOR_Interface.h"
#include "MOTOR_Private.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void MOTORS_voidInit(void)
{
	if(MOTOR1_TIMER == TIMER_u8_1)
	{
		TIMER1_u8InitPwmChannel(MOTOR1_TIMER_CC);
	}
	else
	{
		GPT_u8InitPwmChannel(MOTOR1_TIMER, MOTOR1_TIMER_CC);
	}

	if(MOTOR2_TIMER == TIMER_u8_1)
	{
		TIMER1_u8InitPwmChannel(MOTOR2_TIMER_CC);
	}
	else
	{
		GPT_u8InitPwmChannel(MOTOR2_TIMER, MOTOR2_TIMER_CC);
	}


	GPIO_u8SetPinMode(MOTOR1_PORT, MOTOR1_PWM_PIN, GPIO_u8_OUTPUT_AF_PP_50MHZ);
	GPIO_u8SetPinMode(MOTOR2_PORT, MOTOR2_PWM_PIN, GPIO_u8_OUTPUT_AF_PP_50MHZ);

	GPIO_u8SetPinMode(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_OUTPUT_GP_PP_50MHZ);
	GPIO_u8SetPinMode(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_OUTPUT_GP_PP_50MHZ);
	GPIO_u8SetPinMode(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_OUTPUT_GP_PP_50MHZ);
	GPIO_u8SetPinMode(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_OUTPUT_GP_PP_50MHZ);

	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_LOW);

	MOTORS_voidSpeed(0);

}


void MOTORS_voidSpeed(u8 speed)
{
	MOTOR1_voidSpeed(speed);
	MOTOR2_voidSpeed(speed);
}


void MOTORS_voidForward(u8 speed)
{
	MOTORS_voidSpeed(speed);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_HIGH);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_HIGH);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_LOW);
}


void MOTORS_voidBackward(u8 speed)
{
	MOTORS_voidSpeed(speed);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_HIGH);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_HIGH);
}

void MOTORS_voidRight(u8 speed)
{
	MOTORS_voidSpeed(speed);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_HIGH);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_HIGH);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_LOW);
}

void MOTORS_voidLeft(u8 speed)
{
	MOTORS_voidSpeed(speed);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_HIGH);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_HIGH);
}


void MOTORS_voidStop(void)
{
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_LOW);
}

void MOTOR1_voidSpeed(u8 speed)
{
	if(MOTOR1_TIMER == TIMER_u8_1)
	{
		TIMER1_u8SetPWM(MOTOR1_TIMER_CC, 100, speed);
	}
	else
	{
		GPT_u8SetPWM(MOTOR1_TIMER, MOTOR1_TIMER_CC, 100, speed);
	}
}

void MOTOR2_voidSpeed(u8 speed)
{
	if(MOTOR2_TIMER == TIMER_u8_1)
	{
		TIMER1_u8SetPWM(MOTOR1_TIMER_CC, 100, speed);
	}
	else
	{
		GPT_u8SetPWM(MOTOR2_TIMER, MOTOR2_TIMER_CC, 100, speed);
	}
}





/*
 * EXTI.c
 *
 * Created: 10/6/2023 4:51:12 PM
 *  Author: ADAM
 */ 
#include "std_types.h"
#include "bit_math.h"
#include "EXTI.h"

#include <avr/io.h>
#include <avr/interrupt.h>

void(*global_ptr)(void)= NULL;

void EXIT_voidInit(void)
{
	//Choose EXternal interrupt mode
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	//Enable interrupt
	SET_BIT(GICR,6);
	//Enable Global interrupt
	//SET_BIT(SREG,)= macro el t7t ei = enable register
	sei();
}

void Callback(void(*ptr)(void))
{
	global_ptr=ptr;
}
ISR(INT0_vect)
{
	global_ptr();
}
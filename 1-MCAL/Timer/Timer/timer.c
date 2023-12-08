/*
 * timer.c
 *
 * Created: 10/13/2023 4:19:02 PM
 *  Author: ADAM
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
void INITITIMER_Initi()
{   //select prescaler 8 bit
	/* Frequancy of CPU :16000000 prescaler :8bit 
	tick time : 0.5 over flow :128us  */  
	sei();/*enable global Interrupt*/
	TCNT0 =254;
	SET_BIT(TCCR0,CS01);
	SET_BIT(TIMSK,TOV0);//enable PIE Interrupt
	
}

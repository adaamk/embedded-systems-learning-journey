/*
 * main.c
 *
 * Created: 10/13/2023 4:06:04 PM
 *  Author: ADAM
 */ 

#include <xc.h>
#include "timer.h"
#include <avr/interrupt.h>
void toggleLed()
{
	static unsigned char state =0;
	if(state ==0)
	{
		SET_BIT(PORTD,3);
		state =1;
	}
	else if(state ==1)
	{
		CLEAR_BIT(PORTD,3);
		state =0;
	}
}
int main(void)
{DDRD =0b00001000;
	INITITIMER_Initi();
	while(1)
	{
		//TODO:: Please write your application code
	}
}
ISR(TIMER0_OVF_vect)
{
	static unsigned short counter =0;
	counter++;
	if(counter ==7812)
	{
		counter =0;
		TCNT0 =254;
		toggleLed();
	}
	
}
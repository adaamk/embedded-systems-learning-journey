/*
 * main.c
 * Created: 10/6/2023 4:05:23 PM
 *  Author: ADAM
 */ 
#include "bit_math.h"
#include "std_types.h"
#include <xc.h>
#include <avr/interrupt.h>

void Toggle(void)
{
	static u8 x =0;
	if (x==0)
	{
		SET_BIT(PORTD,3);
		x =1;
	}
	else if (x==1)
	{
		CLEAR_BIT(PORTD,3);
		x=0;
	}
	
}
int main(void)
{
	// define data direction for push button and led
	CLEAR_BIT(DDRD,2);//set to 0 because push button is input
	SET_BIT(DDRD,3);//set to 1 because led is output
	
	EXIT_voidInit();
	Callback(&Toggle);
    while(1)
    {
       
    }
}


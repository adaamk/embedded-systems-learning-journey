/*
 * main.c
 * Created: 9/30/2023 5:09:47 PM
 *  Author: ADAM
 */ 

#include <xc.h>
#define F_CPU 16000000UL
#include "std_types.h"
#include "LCD_driver.h"
#include <avr/delay.h>
int main(void)
{
    DDRA = 0xff;
	DDRB = 0b00001111;
	LCD_VoidInit();
	LCD_voidSenddata('a');
	LCD_voidSenddata('d');
	LCD_voidSenddata('a');
	LCD_voidSenddata('m');
    

    while (1) {
	    // Do nothing
    }

    return 0;
 
}
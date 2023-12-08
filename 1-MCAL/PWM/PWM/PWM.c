/*
 * PWM.c
 *
 * Created: 10/14/2023 3:42:44 PM
 *  Author: ADAM
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
void INITITIMER_Initi()
{  
	SET_BIT(TCCR0,6);
    SET_BIT(TCCR0,5);
    SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,1);
	
}
void timer_ocr (u8 ocr_value)
{
	OCR0=ocr_value;
}
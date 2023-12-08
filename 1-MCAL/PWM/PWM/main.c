/*
 * main.c
 *
 * Created: 10/14/2023 3:41:11 PM
 *  Author: ADAM
 */ 

#include <xc.h>
#include "PWM.h"
#include "bit_math.h"
int main(void)
{ 
	SET_BIT (DDRB,3);
	INITITIMER_Initi();
    while(1)
    {
        timer_ocr(150);
    }
}
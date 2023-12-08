/*
 * timer.h
 *
 * Created: 10/13/2023 4:19:21 PM
 *  Author: ADAM
 */ 


#ifndef TIMER_H
#define TIMER_H
#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLEAR_BIT(reg,bit) reg&=~(1<<bit)
void INITITIMER_Initi();

#endif //TIMER_H

/*
 * SPI.c
 *
 * Created: 10/27/2023 3:00:23 PM
 *  Author: ADAM
 */ 
#include <avr/io.h>
#include "std_types.h"
#include "bit_math.h"
#include "SPI.h"
 
 void Master_Init(void)
 {
	 //choosing master
	 SET_BIT(SPCR,MSTR);
	 //Enable the SPI
	 SET_BIT(SPCR,SPE);
	 //msb transfer first
	 SET_BIT(SPCR,DORD);
 } 
 
 void Slave_Init(void)
 {
	 //choosing slave 
	 CLEAR_BIT(SPCR,MSTR);
	 //enable the SPI
	 SET_BIT(SPCR,SPE);
	 //msb transfer first
	 SET_BIT(SPCR,DORD);
 }
 
 void Wright_Data(u8 data)
 {
	 SPDR =data;
	 while(GET_BIT(SPCR,WCOL)==0)
	 {
		 //no action
	 }
 }
 
 u8 Read_Data(void)
 {
	 u8 Data=0;
	 while(GET_BIT(SPSR,WCOL)==0)
	 {
	 }
	 Data=SPDR;
	 return Data;
 }
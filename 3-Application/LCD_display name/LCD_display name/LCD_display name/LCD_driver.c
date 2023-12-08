#include "bit_math.h"
#include "std_types.h"
#include <util/delay.h>
#include "LCD_driver.h"
#include <avr/io.h>



void LCD_voidSendcommand(u8 command)
{
	//send High nipple "data"
	Data_port = (Data_port & 0x0f)|(command & 0xf0);
	//set RS 0 (Register select)
	CLEAR_BIT(control_port,LCD_RS);
	//set RW 0 (Read/write)
	CLEAR_BIT(control_port,LCD_RW);
	//Enable High
	SET_BIT(control_port,LCD_E);
	//Delay 1Us
	_delay_us(1);
	//Enable LOW
	CLEAR_BIT(control_port,LCD_E);
	
	//Send Low Nipple
	//send data
	Data_port = (Data_port & 0x0f)|(command << 4);
	//set RS 0 (Register select)
	CLEAR_BIT(control_port,LCD_RS);
	//set RW 0 (Read/write)
	CLEAR_BIT(control_port,LCD_RW);
	//Enable High
	SET_BIT(control_port,LCD_E);
	//Delay 1Us
	_delay_us(1);
	//Enable LOW
	CLEAR_BIT(control_port,LCD_E);
}
void LCD_voidSenddata(u8 data)
{
	//send High nipple "data"
	Data_port = (Data_port & 0x0f)|(data & 0xf0);
	//set RS 1 (Register select)
	SET_BIT(control_port,LCD_RS);
	//set RW 0 (Read/write)
	CLEAR_BIT(control_port,LCD_RW);
	//Enable High
	SET_BIT(control_port,LCD_E);
	//Delay 1Us
	_delay_us(1);
	//Enable LOW
	CLEAR_BIT(control_port,LCD_E);
	//Send Low Nipple
	//send data
	Data_port = (Data_port & 0x0f)|(data << 4);
	//set RS 1 (Register select)
	SET_BIT(control_port,LCD_RS);
	//set RW 0 (Read/write)
	CLEAR_BIT(control_port,LCD_RW);
	//Enable High
	SET_BIT(control_port,LCD_E);
	//Delay 1Us
	_delay_us(1);
	//Enable LOW
	CLEAR_BIT(control_port,LCD_E);
}
void LCD_VoidInit(void)
{
	_delay_ms(40);
	LCD_voidSendcommand(0x28);//Function set
	_delay_us(40);
	LCD_voidSendcommand(0x02);//return home
	_delay_ms(2);
	LCD_voidSendcommand(0x06);//Entry mode
	_delay_us(40); 
	LCD_voidSendcommand(0x0f);//display ON
	LCD_voidSendcommand(0x14);//shift cursor right
	_delay_ms(40);
	LCD_voidSendcommand(0x01);//clear
	_delay_ms(2);
}
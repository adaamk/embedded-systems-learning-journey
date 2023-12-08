#include "std_types.h"
#include "bit_math.h"
#include "DIO_program.h"
#include <avr/io.h>

u8 DIO_SetpinDirection(u8 Port_number,u8 PIN_number,u8 Value)
{
	u8 Error = 1;
	if ((Port_number<=DIO_PORTD)&&(PIN_number <= 7)&&((Value == DIO_INPUT)||(Value == DIO_OUTPUT)))
{
	switch(Port_number)
		{
			case DIO_PORTA:
			switch(Value)
			{
				case DIO_OUTPUT : SET_BIT(DDRA,PIN_number);break;
				case DIO_INPUT : CLEAR_BIT(DDRA,PIN_number);break;
			}
			break;
			case DIO_PORTB:
			switch(Value)
			{
				case DIO_OUTPUT : SET_BIT(DDRB,PIN_number);break;
				case DIO_INPUT : CLEAR_BIT(DDRB,PIN_number);break;
			}
			break;
			case DIO_PORTC:
			switch(Value)
			{
				case DIO_OUTPUT : SET_BIT(DDRC,PIN_number);break;
				case DIO_INPUT : CLEAR_BIT(DDRC,PIN_number);break;
			}
			break;
			case DIO_PORTD:
			switch(Value)
			{
				case DIO_OUTPUT : SET_BIT(DDRD,PIN_number);break;
				case DIO_INPUT : CLEAR_BIT(DDRD,PIN_number);break;
			}
			break;
		}
} 
else
{
	Error =0;
}
	return Error;
}

u8 DIO_SetpinValue(u8 Port_number,u8 PIN_number,u8 Value)
{
	u8 Error = 1;
	if ((Port_number<=DIO_PORTD)&&(PIN_number <= 7)&&((Value == DIO_HIGH)||(Value == DIO_LOW)))
{
	switch(Port_number)
		{
			case DIO_PORTA:
			switch(Value)
			{
				case DIO_HIGH : SET_BIT(PORTA,PIN_number);break;
				case DIO_LOW : CLEAR_BIT(PORTA,PIN_number);break;
			}
			break;
			case DIO_PORTB:
			switch(Value)
			{
				case DIO_HIGH : SET_BIT(PORTB,PIN_number);break;
				case DIO_LOW : CLEAR_BIT(PORTB,PIN_number);break;
			}
			break;
			case DIO_PORTC:
			switch(Value)
			{
				case DIO_HIGH : SET_BIT(PORTC,PIN_number);break;
				case DIO_LOW : CLEAR_BIT(PORTC,PIN_number);break;
			}
			break;
			case DIO_PORTD:
			switch(Value)
			{
				case DIO_HIGH : SET_BIT(PORTD,PIN_number);break;
				case DIO_LOW : CLEAR_BIT(PORTD,PIN_number);break;
			}
			break;
		}
} 
else
{
	Error =0;
}
	return Error;
}

u8 DIO_GetpinValue(u8 Port_number,u8 PIN_number,u8 * Value)
{
	u8 Error = 1;
	if ((Port_number<=DIO_PORTD)&&(PIN_number <= 7)&&(Value != NULL))
	{	
		*Value = 0;
		switch(Port_number)
		{
			case DIO_PORTA : *Value = GET_BIT(PINA,PIN_number);break;
			case DIO_PORTB : *Value = GET_BIT(PINB,PIN_number);break;
			case DIO_PORTC : *Value = GET_BIT(PINC,PIN_number);break;
			case DIO_PORTD : *Value = GET_BIT(PIND,PIN_number);break;
		}
	}
	else
	{
		Error = 0;
	}
	return Error;
}
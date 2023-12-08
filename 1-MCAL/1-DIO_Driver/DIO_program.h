#ifndef DIO_PROGRAM_H //header guard to define once without overwrite
#define DIO_PROGRAM_H//header guard

//defines
#define DIO_OUTPUT 1
#define DIO_INPUT 0

#define DIO_HIGH 1
#define DIO_LOW 0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

//functions
u8 DIO_SetpinDirection(u8 Port_number,u8 PIN_number,u8 Value);
u8 DIO_SetpinValue(u8 Port_number,u8 PIN_number,u8 Value);
u8 DIO_GetpinValue(u8 Port_number,u8 PIN_number,u8 * Value);

#endif //header guard
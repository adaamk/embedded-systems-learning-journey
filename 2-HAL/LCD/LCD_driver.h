#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#define Data_port PORTA
#define control_port PORTB

#define LCD_RS 1
#define LCD_RW 2
#define LCD_E 3

void LCD_VoidInit(void);
void LCD_VoidSendcommand(u8 command);
void LCD_voidSenddata(u8 data);

#endif
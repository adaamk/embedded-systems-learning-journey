/*
 * SPI.h
 *
 * Created: 10/27/2023 3:00:42 PM
 *  Author: ADAM
 */ 

#ifndef SPI_H_
#define SPI_H_

void Master_Init(void);
void Slave_Init(void);
u8 Read_Data(void);
void Wright_Data(u8 data);


#endif /* SPI_H_ */
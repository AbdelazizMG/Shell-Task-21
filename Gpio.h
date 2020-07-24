/*
 * Gpio.h
 *
 * Created: 7/23/2020 12:02:01 PM
 *  Author: Abdulazez
 */ 


#ifndef GPIO_H_
#define GPIO_H_

///Macros to Clear and Set the Bits
#define SetBit(Reg,Bit) Reg|= (1<<Bit)        
#define ClearBit(Reg,Bit) Reg&= ~(1<<Bit)

/// prototype for GpioInit Function
void GpioInit();

#endif /* GPIO_H_ */
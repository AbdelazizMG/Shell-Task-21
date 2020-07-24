/*
 * Gpio.c
 *
 * Created: 7/23/2020 12:02:14 PM
 *  Author: Abdulazez
 */ 
#include "Gpio.h"
#include <avr/io.h>
void GpioInit()
{
	/// Setting OC1A & OC1B as Outputs
	 SetBit(DDRB,DDB1); 
	 SetBit(DDRB,DDB2);
}
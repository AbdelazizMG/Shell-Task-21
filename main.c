/*
 * AtmelStudioProject.c
 *
 * Created: 7/23/2020 12:01:33 PM
 * Author : Abdulazez
 */ 

#include <avr/io.h>
#include "Gpio.h"
#include "Timer1.h"

/// CPU Clock Frequency = 8MHz
int main(void)
{
  GpioInit();
  Timer1Init();
  while(1);
}


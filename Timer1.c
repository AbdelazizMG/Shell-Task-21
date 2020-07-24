/*
 * Timer1.c
 *
 * Created: 7/23/2020 12:02:39 PM
 *  Author: Abdulazez
 */ 
#include "Timer1.h"
#include <avr/io.h>

void Timer1Init()
{
	   /* details
		*
	    * (CPU Frequency 8MHz/ PWM Frequency 5000)= 1600  
		* ICR= 1600/2= 800 
		*/
	    ICR1 = 800; 
		
	   /* CPU Frequency / PWM Frequency =  2prescaler * ICR (TOP )
		* So Prescaler = 1  ( NO Prescaling ) 
		* Setting CS10 and Clearing CS11 , CS12
		*/
		SetBit(TCCR1B,CS10);
		ClearBit(TCCR1B,CS11);
		ClearBit(TCCR1B,CS12);
		
	   /* Duty Cylce = Ton / Period , Period = 200 Micro Second
		* For Non inverting Signal , Let the Duty cycle = 40% 
		* So Ton= Duty Cycle * Period = 0.4 * 200 = 80
		* is Toff = 120 , OCR1B = 0.4 * 800 = 320   
		* Dead Time = 10 Micro Second So the Ton of (A) will be less Ton (B) by 2*10 = 20 
		* For inverting signal : Ton=60 , Toff = 140 Duty=30% 
		* OCR1A= 0.3 * 800 = 240
		*/
		OCR1A= 240;
		OCR1B= 320;
		
	   /* PhasaeCorrect PWM
		* WGM10       WGM11      WGM12     WGM13
		*   1           0          1         0
		*/                              
	  	ClearBit(TCCR1A,WGM10);
	  	SetBit(TCCR1A,WGM11); 
	  	ClearBit(TCCR1B,WGM12); 
	  	SetBit(TCCR1B,WGM13); 
		  
	    /* Inverting and Non inverting to get Complementary PWM signals
		 * Setting COM1A1,COM1B and COM1B1 , Clearing COM1A0 in TCCR1A Register
		 */
		SetBit(TCCR1A,COM1A1);   
		ClearBit(TCCR1A,COM1A0);
		SetBit(TCCR1A,COM1B1);
		SetBit(TCCR1A,COM1B0);
	   
	  
	  
}


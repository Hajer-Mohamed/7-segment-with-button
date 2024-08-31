/*
 * _7_seg_with_button.c
 *
 * Created: 7/9/2024 3:20:26 PM
 *  Author: elsawah
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "seven.h"
#include "button.h"
int main(void)
{
	seven_seg_init('A');
	unsigned char counter=0;
	unsigned char button_val;
	button_init('D',0);
    while(1)
    {
         button_val=button_read('D',0);
		 if(button_val==1)
		 {
			counter++;
		 }		
		 if(counter>9)
		 {
			 counter=0;
		 }	
		seven_seg_write('A',counter);
		_delay_ms(1000);	    
    }
}
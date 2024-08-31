/*
 * button.c
 *
 * Created: 5/6/2024 3:43:33 PM
 *  Author: elsawah
 */ 

#include <avr/io.h>
//#define F_CPU 8000000UL      don't use delay 
//#include <util/delay.h>
#include "button.h"
#include "LED.h"
int main(void)
{
	button_init('D',0);
	led_init('D',1);
    while(1)
    {
        if(button_read('D',0)==1)
		{
			led_on('D',1);	
		}			
		else{
			led_off('D',1);	
		}			
    }
}
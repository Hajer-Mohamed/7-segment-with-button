/*
 * DIO.c
 *
 * Created: 4/30/2024 2:34:49 PM
 *  Author: elsawah
 */ 
#include<avr/io.h>
#include "std_macros.h"
void set_pin_dir(char port ,char pin,char dir)
{
	switch(port)
	{	
		case 'a':
		case 'A':
		if(dir==1)
		{
			SET_BIT(DDRA,pin);
		}
		else
		{
			CLR_BIT(DDRA,pin);
		}
       break;

		case 'b':
		case 'B':
		if(dir==1)
		{
			SET_BIT(DDRB,pin);
		}
		else
		{
			CLR_BIT(DDRB,pin);
		}
		break;

	   case 'C':
	   case 'c':
	   if(dir==1)
	   {
		   SET_BIT(DDRC,pin);
	   }
	   else
	   {
		   CLR_BIT(DDRC,pin);
	   }
	   break;

      case 'd':
      case 'D':
      if(dir==1)
      {
	      SET_BIT(DDRD,pin);
      }
      else
      {
	      CLR_BIT(DDRD,pin);
      }
      break;
	}
}

void DIO_write_pin(char port,char pin ,char val)
{
	switch(port)
	{
		case 'a':
		case 'A':
		if(val==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;

		case 'b':
		case 'B':
		if(val==1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLR_BIT(PORTB,pin);
		}
		break;

		case 'C':
		case 'c':
		if(val==1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLR_BIT(PORTC,pin);
		}
		break;

		case 'd':
		case 'D':
		if(val==1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLR_BIT(PORTD,pin);
		}
		break;
	}
}

void DIO_toggle_pin(char port,char pin)
{
	  switch(port)
	  {
		  case 'a':
		  case 'A':
			  TOG_BIT(PORTA,pin);
		  break;

		  case 'b':
		  case 'B':
		     TOG_BIT(PORTB,pin);
		  break;

		  case 'C':
		  case 'c':
		    TOG_BIT(PORTC,pin);
		  break;

		  case 'd':
		  case 'D':
		    TOG_BIT(PORTD,pin);
		  break;
	  }

}

char DIO_read_pin(char port,char pin)
{
	unsigned char x;
	switch(port)
	{
		case 'a':
		case 'A':
			x=READ_BIT(PINA,pin);
		break;

		case 'b':
		case 'B':
			x=READ_BIT(PINB,pin);
		break;

		case 'C':
		case 'c':
			x=READ_BIT(PINC,pin);	
		break;

		case 'd':
		case 'D':
			x=READ_BIT(PIND,pin);
		break;
	}
return x;
}
void dio_connet_pullup(char port,char pin, char connect)
{
	DIO_write_pin(port,pin,connect);
}


void set_port_dir(char port ,char dir)
{
	switch(port)
	{
		case 'a':
		case 'A':
			DDRA=dir;
			break;

		case 'b':
		case 'B':
			DDRB=dir;
		   break;

		case 'C':
		case 'c':
			DDRC=dir;
		break;

		case 'd':
		case 'D':
			DDRD=dir;
		break;
	}
}

void DIO_write_port(char port,char val)
{
	switch(port)
	{
		case 'a':
		case 'A':
			PORTA=val;
		break;

		case 'b':
		case 'B':
			PORTB=val;
		break;

		case 'C':
		case 'c':
			PORTC=val;
		break;

		case 'd':
		case 'D':
			PORTD=val;
		break;
	}
}

void DIO_toggle_port(char port)
{
	switch(port)
	{
		case 'a':
		case 'A':
		PORTA=~PORTA;
		break;

		case 'b':
		case 'B':
		PORTB=~PORTB;
		break;

		case 'C':
		case 'c':
		PORTC=~PORTC;
		break;

		case 'd':
		case 'D':
		PORTD=~PORTD;
		break;
	}

}

char DIO_read_port(char port)
{
	unsigned char x;
	switch(port)
	{
		case 'a':
		case 'A':
		x=PINA;
		break;

		case 'b':
		case 'B':
		x=PINB;
		break;

		case 'C':
		case 'c':
		x=PINC;
		break;

		case 'd':
		case 'D':
		x=PIND;
		break;
	}
	return x;
}
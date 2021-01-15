/************************************************************************/
/* Name:	MDIO_program.c												*/
/* Author:	Mostafa Hendawy												*/
/* Version: v1.0														*/
/* Description: This file contains DIO module logical program.          */
/************************************************************************/

/************************************************************************/
/*                          Includes                                    */
/************************************************************************/
 
 #include "LBIT_MATH.h"
 #include "LSTD_TYPES.h"
 #include "MDIO_private.h"
 #include "MDIO_interface.h"

/************************************************************************/
/*                      Functions implementations                       */
/************************************************************************/

/*This function is responsible for setting a pin or pins state wether input or output  for a dedicated port*/
void mdio_pinStatus(u8_t port,u8_t pin,u8_t pin_status)
{
	switch(port)
	{	
		case PORTA:
			switch(pin_status)
			{	/*Setting the pins as outputs */
				case OUTPUT:
					
					MDIO_DDRA |= pin;
					break;
					/*Setting the pins as inputs without pull up */
				case  INPUT_FLOAT:
					MDIO_DDRA &= ~pin;
					break;	
					/*Setting the pins as inputs with pull up */
				case INPUT_PULLUP:
					MDIO_DDRA &= ~pin;
					MDIO_PORTA |= pin;
					break;	
			}
			break;
		case PORTB:
		switch(pin_status)
		{
			case OUTPUT:
			
				MDIO_DDRB |= pin;
				break;
			case  INPUT_FLOAT:
				MDIO_DDRB &= ~pin;
				break;
			case INPUT_PULLUP:
				MDIO_DDRB &= ~pin;
				MDIO_PORTB |= pin;
				break;
		}
		break;
		case PORTC:
		switch(pin_status)
		{
			case OUTPUT:
			
				MDIO_DDRC |= pin;
				break;
			case  INPUT_FLOAT:
				MDIO_DDRC &= ~pin;
				break;
			case INPUT_PULLUP:
				MDIO_DDRC &= ~pin;
				MDIO_PORTC |= pin;
				break;
		}
		break;		
		case PORTD:
		switch(pin_status)
		{
			case OUTPUT:
			
				MDIO_DDRD |= pin;
				break;
			case  INPUT_FLOAT:
				MDIO_DDRD &= ~pin;
				break;
			case INPUT_PULLUP:
				MDIO_DDRD &= ~pin;
				MDIO_PORTD |= pin;
				break;
		}
		break;		
		
	}
	
	
	return;
}

/*This function is responsible for setting a dedicated value for a pin or pins*/
void mdio_setPinValue(u8_t port,u8_t pin,u8_t pin_value)
{
	switch(port)
	{  
		case PORTA:
		switch(pin_value)
		{	
			case HIGH:
			
				MDIO_PORTA |= pin;
				break;
			case  LOW:
				MDIO_PORTA &= ~pin;
				break;
		}
		break;
		
		
		case PORTB:
		switch(pin_value)
		{
			case HIGH:
			
				MDIO_PORTB |= pin;
				break;
			case  LOW:
				MDIO_PORTB &= ~pin;
				break;
		}
			break;
			
			
		case PORTC:
		switch(pin_value)
		{
			case HIGH:
			
				MDIO_PORTC |= pin;
				break;
			case  LOW:
				MDIO_PORTC &= ~pin;
				break;
		}
			break;
			
			
		case PORTD:
		switch(pin_value)
		{
			case HIGH:
			
				MDIO_PORTD |= pin;
				break;
			case  LOW:
				MDIO_PORTD &= ~pin;
				break;
	
		}
			break;
		
	}
	
	
	return;
}


void mdio_togglePinValue(u8_t port,u8_t pin)
{
	switch(port)
	{
		case PORTA:
		MDIO_PORTA ^=pin;
		break;
		
		
		case PORTB:
		
		MDIO_PORTB ^=pin;		
		break;
		
		
		case PORTC:
				MDIO_PORTC ^=pin;
				break;
		
		
		case PORTD:
				MDIO_PORTD ^=pin;
				break;
	}
		
	
	return;	
}


u8_t mdio_getPinValue(u8_t port, u8_t pin)
{
	/*Local variable used to get a dedicated pin value*/
	u8_t pinValue = 0;
	
	/*Switching over DIO ports*/
	switch(port)
	{
		/*In case of PORTA*/
		case PORTA:
			/*Anding PIN register value with pin number*/
			if(MDIO_PINA & pin)
			{
				/*If any other value than zero then pin value is HIGH*/
				pinValue = HIGH;
			}
			else
			{
				/*If any other value than zero then pin value is LOW*/
				pinValue = LOW;
			}
			break;

		/*In case of PORTB*/
		case PORTB:
			/*Anding PIN register value with pin number*/
			if(MDIO_PINB & pin)
			{
				/*If any other value than zero then pin value is HIGH*/
				pinValue = HIGH;
			}
			else
			{
				/*If any other value than zero then pin value is LOW*/
				pinValue = LOW;
			}
			break;

		/*In case of PORTC*/
		case PORTC:
			/*Anding PIN register value with pin number*/
			if(MDIO_PINC & pin)
			{
				/*If any other value than zero then pin value is HIGH*/
				pinValue = HIGH;
			}
			else
			{
				/*If any other value than zero then pin value is LOW*/
				pinValue = LOW;
			}
			break;

		/*In case of PORTD*/
		case PORTD:
			/*Anding PIN register value with pin number*/
			if(MDIO_PIND & pin)
			{
				/*If any other value than zero then pin value is HIGH*/
				pinValue = HIGH;
			}
			else
			{
				/*If any other value than zero then pin value is LOW*/
				pinValue = LOW;
			}
			break;
	}
	
	/*Return the real value of the pin*/
	return pinValue;
}
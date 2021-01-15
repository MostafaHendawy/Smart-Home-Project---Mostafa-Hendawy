/*
 * Actuator.c
 *
 * Author : Mostafa Hendawy
 */ 

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MUART_interface.h"
#include "MSPI_interface.h"
#include "MUART_private.h"
#include "MDIO_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	mdio_pinStatus(PORTB, PIN4, INPUT_FLOAT);
	mdio_pinStatus(PORTB, PIN5, INPUT_FLOAT);
	mdio_pinStatus(PORTB, PIN6, OUTPUT);
	mdio_pinStatus(PORTB, PIN7, INPUT_FLOAT);

	mspi_initSlave(MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_32);
	
	mdio_pinStatus(PORTC, PIN0, OUTPUT);
	mdio_pinStatus(PORTC, PIN1, OUTPUT);
	
	while (1)
	{
		/*switching over the received character from mobile app via bluetooth*/
		switch(mspi_recieve())
		{
			/* in case of character a*/
			case 'a':
				/* Switch on LED 1 */
				mdio_setPinValue(PORTC, PIN0, HIGH);
				break;
				
			/* in case of character b*/
			case 'b':
				/* Switch off LED 1 */
				mdio_setPinValue(PORTC, PIN0, LOW);
				break;
				
			/* in case of character c*/
			case 'c':
				/* Switch on LED 2 */
				mdio_setPinValue(PORTC, PIN1, HIGH);
				break;
				
			/* in case of character d*/				
			case 'd':
				/* Switch off LED 2 */
				mdio_setPinValue(PORTC, PIN1, LOW);
				break;
				
			/* in case of character e*/				
			case 'e':
			
				/* Switch on both LEDs*/		
				mdio_setPinValue(PORTC, PIN0, HIGH);
				mdio_setPinValue(PORTC, PIN1, HIGH);
				break;
				
			/* in case of other character */			
			default:
				
				/* Switch off both LEDs */			
				mdio_setPinValue(PORTC, PIN0, LOW);
				mdio_setPinValue(PORTC, PIN1, LOW);
				break;	
		}
		
	}
	
	return 0;
	
}


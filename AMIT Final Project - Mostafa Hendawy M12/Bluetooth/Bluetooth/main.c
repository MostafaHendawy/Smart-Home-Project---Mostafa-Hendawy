/*
 * Bluetooth.c
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
	u8_t recieve = 0;
	mdio_pinStatus(PORTB, PIN4, OUTPUT);
	mdio_pinStatus(PORTB, PIN5, OUTPUT);
	mdio_pinStatus(PORTB, PIN6, INPUT_FLOAT);
	mdio_pinStatus(PORTB, PIN7, OUTPUT);

	mspi_init(MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_32);	
	muart_init(MUART_9600_BPS);
	
	while (1)
	{
		
		muart_recvByte(&recieve);
		mspi_sendRecvByte(recieve);
		
	}
	
	return 0;
	
}




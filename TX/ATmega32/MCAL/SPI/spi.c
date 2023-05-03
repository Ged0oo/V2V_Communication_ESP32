/*
 * spi.c
 *
 *  Created on: 8 Oct 2022
 *      Author: El-Wattaneya
 */

#include "spi.h"
void SPI_SlaveInit(void)
{
/* Set MISO output, all others input */
DDRB = (1<<6);
/* Enable SPI */
SPCR = (1<<SPE);
}


char SPI_SlaveReceive(void)
{
/* Wait for reception complete */
while(!(SPSR & (1<<SPIF)))
;
/* Return data register */
return SPDR;
}


void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
DDRB = (1<<5)|(1<<7);
/* Enable SPI, Master, set clock rate fck/16 */
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}


void SPI_MasterTransmit(char cData)
{
/* Start transmission */
SPDR = cData;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)));
}

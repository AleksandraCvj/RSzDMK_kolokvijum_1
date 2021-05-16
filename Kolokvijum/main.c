#include "../timer/timer.h"
#include "../usart/usart.h"
#include "pin.h"
#include "util.h"
#include <avr/pgmspace.h>
/*
 * main.c
 *
 *  Created on: May 16, 2021
 *      Author: Anja
 */

int main()
{
	int16_t duzina_niza;
	int8_t mode = 1;
	int16_t niz[64];
	usartInit(9600);

	while(1)
	{
		usartPutString(PSTR("Unesite duzinu niza: \r\n"));
		do
		{
			PORTB |= 1 << 5;

		}while(!usartAvailable());


		duzina_niza = usartParseInt();

		usartPutString("Unesite elemente niza:\r\n");
		UnosElemenata(niz);

		Sort(niz, duzina_niza, 1);

		IspisNiza(niz);







	}



	return 0;
}

void UnosElemenata(int16_t niz[], int16_t duzina)
{
	int16_t tmp[30];
	for (uint16_t i = 0; i < duzina; i++)
	{
			sprintf(tmp, "clan[%d] = \0", i);
			usartPutString(tmp);

			while (usartAvailable() == 0)
			;
			_delay_ms(100);

			niz[i] = usartParseInt();

			sprintf(tmp, "%d \0", niz[i]);
			usartPutString(tmp);
	}
		usartPutString("\r\n\0");
}


void IspisNiza(int16_t niz[], int16_t duzina)
{
	int16_t tmp[duzina];
	for (int16_t i = 0; i < duzina; i++)
	{
			sprintf(tmp, "%d \0", niz[i]);
			usartPutString(tmp);

	}
		usartPutString("\r\n\0");
}


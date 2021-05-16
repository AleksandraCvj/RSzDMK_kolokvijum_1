#include "util.h"
#include <stdint.h>
#include <stdlib.h>

/*
 * util.c
 *
 *  Created on: May 16, 2021
 *      Author: Anja
 */

void Sort(int16_t *array, int16_t array_length, int8_t mode)
{
	//1 - UP
	//0 - DOWN
	int16_t tmp[array_length];
	int16_t duzina;

	switch(mode)
	{
		case 1:

			int16_t i = 0;
			int16_t j, pom;

		for(j = i + 1; j < duzina; j++)
		{
			if(tmp[j] < tmp[i])
			{
			pom = tmp[i];
			tmp[i] = tmp[j];
			tmp[j] = pom;
			}
		}
		break;


		case 2:
			int16_t i = 0;
			int16_t j, pom;

		 for(j = i + 1; j < duzina; j++)
					{
						if(tmp[j] < tmp[i])
						{
						pom = tmp[i];
						tmp[i] = tmp[j];
						tmp[j] = pom;
						}
					}

		break;

		default:
		break;
	}


}

int8_t Check(int16_t *array)
{



}



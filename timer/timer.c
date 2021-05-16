#include <avr/io.h>
#include <avr/interrupt.h>
#include <timer.h>

unsigned long miliseconds = 0;

unsigned char Broj_milisekundi(unsigned long miliseconds) {
	if (ms == miliseconds) {
		PORTB ^= 1<<5 ; //xor, invertuje stalno PB5
		return 1;
	}
	return 0;
}

unsigned long timer0DelayMs(unsigned long delay_length)
{
    unsigned long t0; // Trenutak pocevsi od kog se racuna pauza

    // Implementacija pauze
    t0 = ms;
    while ((ms - t0) < delay_length)
    ;  // Pauza delay_length milisekundi

    return ms;
}

void timer0InteruptInit()
{
    // Inicijalizacija tajmera 0 tako da perioda prekida bude 1ms
    TCCR0A = 0x02;
    TCCR0B = 0x03;
    OCR0A = 249;
    TIMSK0 = 0x02;

    // Podesavanje globalne dozvole prekida
    sei();
}

ISR(TIMER0_COMPA_vect)
{
    // Inkrementovanje broja milisekundi koje su prosle od pokretanja aplikacije
    ms++;
}

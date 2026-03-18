#define F_CPU 16000000UL
#define __AVR_ATMEGA__

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Set PB5 as output
    DDRB |= (1 << PB5);

    while (1)
    {
        // Toggle LED
        PORTB ^= (1 << PB5);

        // Wait 500 ms
        _delay_ms(500);
    }
}
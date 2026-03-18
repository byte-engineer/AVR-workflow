#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // setting PB5 as an input
    DDRB |= (1 << PB5);

    while (1)
    {
        // toggeling PB5
        PORTB ^= (1 << PB5);

        // wait for 500ms
        _delay_ms(500);
    }
}

// same as main()
int _main(void)
{
    *(volatile uint8_t *)(0x37) |= 0x20;
    while (1)
    {
        *(volatile uint8_t *)(0x38) ^= 0x20;
        _delay_ms(500);
    }
}

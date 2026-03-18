#define F_CPU 16000000UL

// includes
#include <avr/io.h>
#include <avr/interrupt.h>


// interrupt handeler
ISR (INT0_vect)
{
    PORTC |= 0x00;
    PORTD |= 0x00;
    while(1);         // helt
}

int main(void)
{
    // enable local INT0/PD2 pin interrupt
    GICR  |= (1 << INT0);
    MCUCR |= (1 << ISC00);

    // setting up global interrupt.
    sei();

    // setting up I/O's
    DDRB = 0x00;             // all inputs
    DDRC = 0xff;             // all outputs
    DDRD = (1 << PD2);       // all inputs exept PD4

    PORTD |= (1 << PD2);

    unsigned char sensor;
    unsigned char temp;
    unsigned char level;

    while (1)
    {
        sensor = PINB;
        temp   = sensor & 0x1f; // lower 5 bits for tempreture 
        level  = (sensor >> 5); // upper 3 bits for tempreture

        // putting temp value in port C.
        PORTC = temp;

        // updating LEDs
        if ((level & 0x01) == 0) // if level is even turn PD5 ON 
        {
            PORTD |=  (1 << PD5);
        } else {
            PORTD &= ~(1 << PD5);
        }

        if ((temp & 0x01) == 0)  // if temp is even turn PD6 ON 
        {
            PORTD &= ~(1 << PD6);
        } else {
            PORTD |=  (1 << PD6);
        }

        // Motor ON if level >= 5
        if (level <= 5)
        {
            PORTD |=  (1 << PD7);
        } else {
            PORTD &= ~(1 << PD7);
        }
    } // while
} // main

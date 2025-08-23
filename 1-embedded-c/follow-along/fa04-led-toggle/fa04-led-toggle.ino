#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect) {
    // Toggle pin 13 (onboard LED)
    PINB |= 0x20;

    // Toggle pin 8 (external LED)
    PINB |= 0x01;
    
    // toggle pin 9
    PINB |= 0x02;

    // toggle pin 9
    PINB |= 0x08;
}

int main(void) {
    // Set pin 13 (PB5) and pin 8 (PB0) as output
    DDRB |= 0x20 | 0x01 | 0x02 | 0x08;

    // Optional: enable internal pull-up on pin 2 (INT0) if using button
    DDRD &= ~0x04;   // Set PD2 (INT0) as input
    PORTD |= 0x04;   // Enable internal pull-up resistor

    // Configure INT0: rising edge
    EIFR |= 0x01;
    EICRA |= 0x02;
    EIMSK |= 0x01;

    sei();  // Enable global interrupts

    while (1); // Infinite loop
}

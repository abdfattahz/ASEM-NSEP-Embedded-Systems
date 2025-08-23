#include "global.h"

uint64_t SYS_TICK = 0;

ISR(TIMER0_COMPA_vect) {
    SYS_TICK++;
}

int32_t TIMER0_Init(void) {
    // Set CTC mode (WGM01 = 1, WGM00 = 0)
    // TCCR0A |= (1 << WGM01); --> Bit 1 = 0x02
    // TCCR0A &= ~(1 << WGM00); --> Clear bit 0
    TCCR0A |= 0x02;
    TCCR0A &= ~0x01;

    // Set compare value for 1ms tick (250,000 / 1000 = 250)
    OCR0A = 0xF9;  // 249 decimal = 0xF9

    // Set prescaler to 64
    // CS02 = 0, CS01 = 1, CS00 = 1 → binary: 0b011 → hex: 0x03
    TCCR0B |= 0x03;
    TCCR0B &= ~0x04;  // Clear CS02 bit (bit 2 = 0x04)

    // Enable Output Compare Match A Interrupt
    // OCIE0A = bit 1 → 0x02
    TIMSK0 |= 0x02;

    // Reset counter
    TCNT0 = 0x00;

    return TIMER0_SUCCESS;
}

//timer0.c
#include "global.h"

int32_t TIMER0_Init(void) {
  TCCR0A = 0x02;      // Set CTC mode
  TCCR0B = 0x03;      // Prescaler = 64
  OCR0A  = 249;       // Compare value for 1ms tick
  TIFR0  = 0x07;      // Clear all interrupt flags
  TIMSK0 = 0x02;      // Enable COMPA interrupt

  return TIMER0_SUCCESS;
}

ISR(TIMER0_COMPA_vect) {
  SYS_TICK++;
}

#include <stdint.h>
#include <avr/io.h>

#define LED_DEBUG_PIN     5
#define LED_DEBUG_DDR     DDRB
#define LED_DEBUG_PORT    PORTB

#define LED_DELAY         100000 

void SYS_Init(void) {
  LED_DEBUG_DDR |= (1 << LED_DEBUG_PIN);
  LED_DEBUG_PORT &= ~(1 << LED_DEBUG_PIN);
}

int main (void) {
  SYS_Init();
  volatile uint32_t delay;

  for (;;) {
    LED_DEBUG_PORT |= (1 << LED_DEBUG_PIN);
    for(delay = 0; delay < LED_DELAY; delay++);

    LED_DEBUG_PORT &= ~(1 << LED_DEBUG_PIN);
    for(delay = 0; delay < LED_DELAY; delay++);
  }

}

#include <stdint.h>
#define LED_DELAY       100000

int main (void) {
  uint8_t* ptr;
  volatile uint32_t delay;

  ptr = 0x24;
  *ptr |= 0x20;

  ptr = 0x25;
  *ptr &= ~0x20;

  for (;;) {
    *ptr |= 0x20;
    for(delay = 0; delay < LED_DELAY; delay++);

    *ptr &= ~0x20;
    for(delay = 0; delay < LED_DELAY; delay++);
  }

  return 0;
}

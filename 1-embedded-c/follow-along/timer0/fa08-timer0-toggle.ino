#include "global.h"

void setup(void) {
  SYS_Init();
  volatile uint32_t delay;
  
  for(;;) {
    GPIO_Write(LED_DEBUG_PIN, GPIO_HIGH);  // Toggle the LED
    for(delay = 0; delay < 100000; delay++); // Simple delay loop
    GPIO_Write(LED_DEBUG_PIN, GPIO_LOW);  // Toggle the LED back
    for(delay = 0; delay < 100000; delay++); // Simple delay

	GPIO_Write(LED_DEBUG_PIN2, GPIO_HIGH);  // Toggle the LED
    for(delay = 0; delay < 100000; delay++); // Simple delay loop
    GPIO_Write(LED_DEBUG_PIN2, GPIO_LOW);  // Toggle the LED back
    for(delay = 0; delay < 100000; delay++); // Simple delay

	GPIO_Write(LED_DEBUG_PIN3, GPIO_HIGH);  // Toggle the LED
    for(delay = 0; delay < 100000; delay++); // Simple delay loop
    GPIO_Write(LED_DEBUG_PIN3, GPIO_LOW);  // Toggle the LED back
    for(delay = 0; delay < 100000; delay++); // Simple delay

	GPIO_Write(LED_DEBUG_PIN4, GPIO_HIGH);  // Toggle the LED
    for(delay = 0; delay < 100000; delay++); // Simple delay loop
    GPIO_Write(LED_DEBUG_PIN4, GPIO_LOW);  // Toggle the LED back
    for(delay = 0; delay < 100000; delay++); // Simple delay

  
  }

}

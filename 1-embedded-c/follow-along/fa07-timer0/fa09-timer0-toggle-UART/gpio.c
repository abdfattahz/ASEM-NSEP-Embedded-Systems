//gpio.c
#include "global.h"

int32_t GPIO_Init(void) {
  DDRD = 0x00;  // DDR or all 8 pins at port D as INPUT --> DDR is used to set whether it is OUTPUT or INPUT
  DDRB = 0x00;  // DDR or all 8 pins at port B as INPUT
  PORTD = 0x00; // turn all port D OUTPUT = LOW
  PORTB = 0x00; // turn all port B OUTPUT = LOW
  return GPIO_SUCCESS;
}

int32_t GPIO_Read(uint8_t pin, uint8_t* value) {

  if (pin > GPIO_MAX) return GPIO_ERROR_RANGE;  // Check range

  if (pin < 8)
    //return (PIND & (1 << pin)) ? GPIO_HIGH : GPIO_LOW;  // Read from Port D
    *value = PIND & (1 << pin);         //PIND (0 to  7)
  else
    *value = PINB & (1 << (pin & 7));   //PINB (8 to 13, becomes 0 to 5)

  if (*value > 0) *value = GPIO_HIGH;
  return GPIO_SUCCESS;  // Read from Port B
}

int32_t GPIO_Mode(uint8_t pin, uint8_t direction) {
  if (pin > GPIO_MAX) return GPIO_ERROR_RANGE;
  if (direction > GPIO_OUTPUT)return GPIO_ERROR_RANGE;

  if (direction == GPIO_INPUT) {
    if (pin < 8) DDRD &= ~(1 << pin); // Set pin LOW
    else DDRB &= ~(1 << (pin & 7)); // Set pin high
  }
  else {
    if (pin < 8) DDRD |= (1 << pin); // Set pin LOW
    else DDRB |= (1 << (pin & 7)); // Set pin high
  }
  return GPIO_SUCCESS;
}

int32_t GPIO_Write(uint8_t pin, uint8_t state) {
  if (pin > GPIO_MAX) return GPIO_ERROR_RANGE;
  if (state > GPIO_HIGH)return GPIO_ERROR_RANGE;

  if (state == GPIO_HIGH) {
    if (pin < 8) PORTD |= (1 << pin);
    else PORTB |= (1 << (pin & 7));
  }
  else {
    if (pin < 8) PORTD &= ~(1 << pin);
    else PORTB &= ~(1 << (pin & 7));
  }
  return GPIO_SUCCESS;
}

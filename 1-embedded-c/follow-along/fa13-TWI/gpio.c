#include "global.h"

int32_t GPIO_Init(void) {
  DDRD = 0x00; DDRB = 0x00; PORTD = 0x00; PORTB = 0x00; // Set Port D as input and Port B as output
  return GPIO_SUCCESS;
}

int32_t GPIO_Mode(uint8_t pin, uint8_t direction) {
  if (pin > GPIO_MAX) return GPIO_ERROR_RANGE;
  if (direction > GPIO_OUTPUT)return GPIO_ERROR_VALUE;

  if (direction == GPIO_INPUT) {
    if (pin < 8) DDRD |= (1 << pin); // Set pin high
    else DDRB |= (1 << (pin & 7)); // Set pin high
  }
  else {
    if (pin < 8) DDRD |= (1 << pin); // Set pin high
    else DDRB |= (1 << (pin & 7)); // Set pin high
  }
  return GPIO_SUCCESS;
}

int32_t GPIO_Write(uint8_t pin, uint8_t state) {
  if (pin > GPIO_MAX) return GPIO_ERROR_RANGE;
  if (state > GPIO_HIGH)return GPIO_ERROR_VALUE;

  if (state == GPIO_HIGH) {
    if (pin < 8) PORTD |= (1 << pin); // Set pin high
    else PORTB |= (1 << (pin & 7)); // Set pin high
  }
  else {
    if (pin < 8) PORTD &= ~(1 << pin); // Set pin high
    else PORTB &= ~(1 << (pin & 7)); // Set pin high
  }
  return GPIO_SUCCESS;
}

int32_t GPIO_Read(uint8_t pin, uint8_t* value) {
  if (pin > GPIO_MAX) return GPIO_ERROR_RANGE;

  if (pin < 8) *value = PIND & (1 << pin);
  else *value = PINB |= (1 << (pin & 8));

  if (*value > 0) *value = GPIO_HIGH;

  return GPIO_SUCCESS;
}

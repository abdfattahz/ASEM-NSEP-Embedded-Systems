#include "global.h"

int32_t ADC_Init(void) {
  ADMUX = 0x40; //ADC0, VREF = AVCC
  ADCSRA = 0x84;

  return ADC_SUCCESS;
}

int32_t ADC_Read_Single(uint8_t ch, uint16_t* value) {
  if (ch > ADC_CHANNEL_MAX) {
    return ADC_ERROR_RANGE;
  }
  ADMUX &= ~0x0F; //set channel
  ADMUX |= (ch & 0x0F);

  ADCSRA |= 0x40;

  while ((ADCSRA & 0x40) == 0x40); //wait till conversion ends
  *value = ADCL; //read value
  *value += ((uint16_t)ADCH << 8);

  return ADC_SUCCESS;
}

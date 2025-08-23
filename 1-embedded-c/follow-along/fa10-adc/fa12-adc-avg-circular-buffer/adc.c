#include "adc.h"

#include "global.h"

int32_t ADC_Init(void) {
    ADMUX = 0x40;   // AVcc with external capacitor at AREF
    ADCSRA = 0x84;  // ADC Enable and start conversion at F_CPU/16
    return ADC_SUCCESS;
}

int32_t ADC_Read_Single(uint8_t ch, uint16_t* value) {
    if (ch > ADC_CHANNEL_MAX) {
        return ADC_ERROR_RANGE;
    }

    ADMUX &= ~0x0F;  // Select channel
    ADMUX |= (ch & 0x0F);

    ADCSRA |= (1 << ADSC);         // Start conversion
    while (ADCSRA & (1 << ADSC));  // Wait until done

    *value = ADCL;
    *value |= ((uint16_t)ADCH << 8);

    return ADC_SUCCESS;
}

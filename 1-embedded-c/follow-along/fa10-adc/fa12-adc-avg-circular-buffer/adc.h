#ifndef ADC_H
#define ADC_H

#ifdef __cplusplus
extern "C" {
#endif

#define ADC_ERROR_BASE 0x00030000
#define ADC_SUCCESS 0
#define ADC_ERROR_RANGE (ADC_ERROR_BASE + 1)

#define ADC_MIN 0
#define ADC_MAX 1023
#define ADC_CHANNEL_MIN 0
#define ADC_CHANNEL_MAX 5

int32_t ADC_Init(void);  // ✅ Fixed: match name and case
int32_t ADC_Read_Single(uint8_t ch, uint16_t *value);

#ifdef __cplusplus
}
#endif

#endif

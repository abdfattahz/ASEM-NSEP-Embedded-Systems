#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_MAX 13
#define GPIO_MIN 0
#define GPIO_LOW 0
#define GPIO_HIGH 1
#define GPIO_INPUT 0
#define GPIO_OUTPUT 1
#define GPIO_SUCCESS 0
#define GPIO_ERROR_RANGE 1

extern int32_t GPIO_Init(void);
extern int32_t GPIO_Mode(uint8_t pin, uint8_t direction);
extern int32_t GPIO_Write(uint8_t pin, uint8_t state);

#ifdef __cplusplus
}

#endif
#endif

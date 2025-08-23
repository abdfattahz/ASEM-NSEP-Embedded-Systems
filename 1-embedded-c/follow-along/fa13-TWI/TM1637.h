#ifndef TM1637_H
#define TM1637_H

#ifdef __cplusplus
extern "C" {
#endif

#define TM1637_SUCCESS                          0
#define TM1637_ERROR_BASE                       0x00003200
#define TM1637_ERROR_RANGE                      (TM1637_ERROR_BASE + 1)

#define TM1637_I2C_ADDR                         0x40


extern int32_t TM1637_Init(void);
extern int32_t TM1637_Write(uint16_t value);

#ifdef __cplusplus
}
#endif

#endif // TM1637_H

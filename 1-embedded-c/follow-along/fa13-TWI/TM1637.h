#ifndef __TM1637_H__
#define __TM1637_H__
#ifdef  __cplusplus
extern "C" {

#endif

#define TM1637_ERROR_BASE                 0x00007000
#define TM1637_SUCCESS                    0
#define TM1637_ERROR_RANGE                (TM1637_ERROR_BASE + 1)

#define TM1637_I2C_ADDRESS                0x40

extern int32_t TM1637_Init(void);
extern int32_t TM1637_Write(uint16_t value);
extern int32_t Decode7seg(uint16_t value);
extern void TM1637_Delay(void);


#ifdef __cpluplus
}
#endif
#endif

// i2c.h
#ifndef __I2C_H__
#define __I2C_H__
#ifdef __cplusplus
extern "C" {
#endif

#define I2C_ERROR_BASE                      0x00006000
#define I2C_SUCCESS                         0
#define I2C_ERROR_START                     (I2C_ERROR_BASE + 1)
#define I2C_ERROR_RESTART                   (I2C_ERROR_BASE + 2)
#define I2C_ERROR_DEVICE_NOT_FOUND          (I2C_ERROR_BASE + 3)
#define I2C_ERROR_DATA_WRITE                (I2C_ERROR_BASE + 4)
#define I2C_ERROR_DATA_READ                 (I2C_ERROR_BASE + 5)

#define I2C_ACK                             (0)
#define I2C_NACK                            (1)

extern int32_t I2C_Init(void);
extern int32_t I2C_START(void);
extern int32_t I2C_RESTART(void);
extern int32_t I2C_Address_Write(uint8_t add);
extern int32_t I2C_Address_Read(uint8_t add);
extern int32_t I2C_Data_Send(uint8_t byte, uint8_t* ack);
extern int32_t I2C_Data_Read(uint8_t* data);
extern int32_t I2C_Data_Read_ACK(uint8_t* data);
extern int32_t I2C_STOP(void);

#ifdef __cplusplus
}
#endif
#endif

//usart.h
#ifndef __USART_H__
#define __USART_H__
#ifdef __cplusplus
extern "C" {
#endif

#define USART_ERROR_BASE        0x00004000
#define USART_SUCCESS           0

#define SYS_F_CPU               16000000UL
#define USART_BAUDRATE          9600
#define USART_BAUD_PRESCALE (((SYS_F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define USART_TX_BUF_SIZE       16    // must be 2^N size
#define USART_ERROR_TX_BUF_FULL (USART_ERROR_BASE + 1)

extern uint8_t USART_TX_BYTES;
extern int32_t USART_Init(void);
extern int32_t USART_Write(uint8_t byte);
extern int32_t USART_Read(uint8_t *count, uint8_t *byte);
extern int32_t USART_Write_String(uint8_t *str);
extern int32_t USART_Process(void);

#ifdef __cplusplus
}
#endif
#endif

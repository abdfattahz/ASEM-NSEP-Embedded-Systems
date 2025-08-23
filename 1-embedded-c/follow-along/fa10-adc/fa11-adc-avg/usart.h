#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>  // For uint8_t, uint16_t
#include <stddef.h>  // For NULL (optional, but commonly used)

/*
 * USART configuration and buffer
 */
#define USART_ERROR_BASE        0x00004000
#define USART_SUCCESS           0
#define USART_ERROR_TX_BUF_FULL (USART_ERROR_BASE + 1)
#define USART_ERROR_RX_BUF_EMPTY (USART_ERROR_BASE + 2)

#ifndef SYS_F_CPU
#define SYS_F_CPU 16000000UL    // Default to 16MHz if not defined elsewhere
#endif

#define USART_BAUDRATE      9600
#define USART_BAUD_PRESCALE (((SYS_F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define USART_TX_BUF_SIZE   32
#define USART_RX_BUF_SIZE   32

extern uint8_t USART_TX_BUF[USART_TX_BUF_SIZE];
extern uint8_t USART_TX_BYTES;
extern uint8_t USART_TX_BUF_WR;
extern uint8_t USART_TX_BUF_RD;

extern uint8_t USART_RX_BUF[USART_RX_BUF_SIZE];
extern uint8_t USART_RX_BYTES;
extern uint8_t USART_RX_BUF_WR;
extern uint8_t USART_RX_BUF_RD;
/*
 * USART function declarations
 */
extern int32_t USART_Init(void);
extern int32_t USART_Write(uint8_t byte);
extern int32_t USART_Read(uint8_t *count , uint8_t *byte);
extern int32_t USART_Write_String(uint8_t *str, uint16_t strlength);
extern int32_t USART_Process(void);

#ifdef __cplusplus
}
#endif

#endif // __USART_H__

//usart.c
#include "global.h"

uint8_t USART_TX_BUF[USART_TX_BUF_SIZE];
uint8_t USART_TX_BUF_WR, USART_TX_BUF_RD;
uint8_t USART_TX_BYTES;

int32_t USART_Init(void) {
  UBRR0H = (USART_BAUD_PRESCALE >> 8);   // set baudrate
  UBRR0L = USART_BAUD_PRESCALE;
  UCSR0C = 0x06;                         // 8-bit data
  UCSR0B = 0x18;                         // enable tx, rx
  
  USART_TX_BUF_WR = 0, USART_TX_BUF_RD = 0, USART_TX_BYTES = 0;
  
  return USART_SUCCESS;
}

int32_t USART_Write(uint8_t byte) {
  while (!(UCSR0A & (1 << UDRE0)));  // Wait until transmit buffer is empty
  UDR0 = byte;                       // Send byte
  return USART_SUCCESS;
}

//int32_t USART_Write_String(uint8_t *str) {
//  uint8_t i;
  
//  if((USART_TX_BYTES + size > USART_TX_BUF_SIZE)) return USART_ERROR_TX_BUF_FULL;
//  
//  for(i = 0, i < size; i++) {
//    USART_TX_BUF[USART_TX_BUF_WR] = *str;
//    str++;
//    BUF[USART_TX_BUF_WR + 1] & (USART_TX_BUF_SIZE - 1);
//    }
//  USART_TX_BYTES += size;
    
int32_t USART_Write_String(uint8_t *str) {
  while (*str != '\0') {
    SYS_Error_Check(USART_Write(*str));  // transmit byte
    str++;                               // advance to next character
  }
  return USART_SUCCESS;
}


int32_t USART_Process(void) {
  if ((USART_TX_BYTES > 0) && ((UCSR0A & 0x20) > 0)) {
    UDR0 = USART_TX_BUF[USART_TX_BUF_RD];
    USART_TX_BUF_RD = (USART_TX_BUF_RD + 1) & (USART_TX_BUF_SIZE - 1);
    USART_TX_BYTES--;
  }
  return USART_SUCCESS;
}


int32_t USART_Read(uint8_t *count, uint8_t *byte) {
  if ((UCSR0A & 0x80) == 0) {
    *count = 0;
  } else {
    *byte = UDR0;                     // receive byte
    *count = 1;                       // number of bytes received
  }
  return USART_SUCCESS;
}

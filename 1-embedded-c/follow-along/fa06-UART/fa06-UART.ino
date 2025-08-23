#define USART_BAUDRATE 9600
#define USART_BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

void USART_Config(void) {
  UBRR0H = (USART_BAUD_PRESCALE >> 8);         //set baudrate
  UBRR0L = USART_BAUD_PRESCALE;

  UCSR0C |= 0x06;                              //8-bit data
  UCSR0B |= 0x18;                              //enable tx & rx
}

void USART_Write(uint8_t byte) {
  while ((UCSR0A & 0x20) == 0);                //wait until USART ready
  UDR0 = byte;                                 //transmit byte
}

uint8_t USART_Read(void) {
  return UDR0;                                 //receive byte
}

int main(void) {
  //    SYSTEM_Config();                             //configure SYSTEM
  USART_Config();                              //configure USART

  for (;;) {
    while ((UCSR0A & 0x80) == 0);            //wait until USART receive
    USART_Write(USART_Read());               //echo
  }
}

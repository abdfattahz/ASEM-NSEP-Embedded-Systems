//sys.c
#include "global.h"
#include "sys.h"

int32_t SYS_ERROR_NUM = 0;
volatile uint64_t SYS_TICK = 0;


void SYS_Fatal_Error(int32_t err, int32_t line, char* file) {
    char str[80];
    char str2[80];
    DDRB |= 0x20;
    PORTB |= 0x20;

    // Format error message into 'str'
    sprintf(str, "FATAL ERROR 0x%08X", err);
    sprintf(str2, " at line %d", line);
    strcat(str, str2);
    sprintf(str2, " in file %s\n", file);
    strcat(str, str2);
    
    USART_TX_BYTES = 0;
    USART_TX_BUF_WR = 0;
    USART_TX_BUF_RD = 0;
    USART_Write_String((uint8_t *)str, strlen(str));

    for (;;); // Halt system
}


int32_t SYS_Init(void) {
  SYS_Error_Check(USART_Init());
  SYS_Error_Check(TIMER0_Init());

  SYS_Error_Check(GPIO_Init());
  SYS_Error_Check(ADC_Init());
  //  GPIO_Init();

  SYS_Error_Check(GPIO_Mode(LED_DEBUG_PIN, GPIO_OUTPUT));
  SYS_Error_Check(GPIO_Mode(LED_BLUE_PIN, GPIO_OUTPUT));
  SYS_Error_Check(GPIO_Mode(LED_YELLOW_PIN, GPIO_OUTPUT));
  SYS_Error_Check(GPIO_Mode(LED_RED_PIN, GPIO_OUTPUT));
  SYS_Error_Check(GPIO_Mode(SW1_PIN, GPIO_INPUT));

  SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_LOW));
  SYS_Error_Check(GPIO_Write(LED_BLUE_PIN, GPIO_LOW));
  SYS_Error_Check(GPIO_Write(LED_YELLOW_PIN, GPIO_LOW));
  SYS_Error_Check(GPIO_Write(LED_RED_PIN, GPIO_LOW));


  sei();
  return SYS_SUCCESS;

}

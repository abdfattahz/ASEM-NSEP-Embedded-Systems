#include "global.h"

#define AVG_NUM 4

int main(void) {
  volatile uint32_t delay;
  volatile uint64_t LED_timeout, SW_timeout;
  uint8_t toggle = 0;
  uint8_t SW[2] = {0};
  uint8_t sw_history[2] = {0, 0};
  uint16_t sw_pressed = 0;
  uint8_t byte_num;
  uint8_t byte;
  char str[20] = {0};
  uint8_t size = strlen(str);
  uint16_t ADC_value[AVG_NUM] = {0};
  uint32_t ADC_sum;
  uint8_t i;
  uint8_t count;

  SYS_Error_Check(SYS_Init());
  SYS_Error_Check(USART_Init());
  SYS_Error_Check(I2C_Init());
  SYS_Error_Check(TM1637_Init());
  //  SYS_Error_Check(TM1637_Write(0));
  SYS_Error_Check(USART_Write_String("Hello World!\n", strlen("Hello World!\n")));
  SYS_Error_Check(USART_Write_String(str, "SYS_TICK: \n"));
  //  SYS_Error_Check(GPIO_Write(20, GPIO_LOW));

  //  SYS_Init();
  LED_timeout = SYS_TICK + 1000;
  SW_timeout = SYS_TICK + 20;
  DDRB &= 0x10;

  for (;;) {

    if (SYS_TICK > LED_timeout) {
      LED_timeout = SYS_TICK + 1000;

      if (toggle) {
        SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_LOW));
        SYS_Error_Check(GPIO_Write(LED_GREEN_PIN, GPIO_LOW));
        toggle = 0;
      } else {
        SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_HIGH));
        SYS_Error_Check(GPIO_Write(LED_GREEN_PIN, GPIO_HIGH));
        toggle = 1;
      }
      //      sprintf(str, "SYS_TICK=%lu\n", SYS_TICK);
      //      SYS_Error_Check(USART_Write_String(str,size));
      //        SYS_Error_Check(ADC_Read_Single(POT_PIN, &ADC_value));
      //        sprintf(str,"ADC - %u\n", ADC_value);
      //        SYS_Error_Check(USART_Write_String(str, strlen(str)));

      for (i = AVG_NUM - 1; i > 0; i--) ADC_value[i] = ADC_value[i - 1];
      SYS_Error_Check(ADC_Read_Single(POT_PIN, &ADC_value[0]));
      ADC_sum = 0;
      for (i = 0; i < AVG_NUM; i++) ADC_sum += ADC_value[i];
      sprintf(str, "ADC (avg) = %u\n", ADC_sum / AVG_NUM);
      SYS_Error_Check(USART_Write_String(str, strlen(str)));

      //          ADC_sum -= ADC_value[ADC_write];
      //          SYS_Error_Check (ADC_Read_Single(POT_PIN,&ADC_value[ADC_write]));
      //          ADC_sum += ADC_value[ADC_write];
      //          ADC_write = (ADC_write + 1) & (AVG_NUM - 1);
      //          sprintf(str, "ADC(avg) = %u\n", ADC_sum / AVG_NUM);
      //          SYS_Error_Check(USART_Write_String(str, strlen(str)));

      TM1637_Write(count);
      count++;
      count %= 10000;

    }

    if (SYS_TICK > SW_timeout) {
      SW_timeout = SYS_TICK + 20;
      sw_history[1] = sw_history[0];


      SYS_Error_Check(GPIO_Read(SW1_PIN, &sw_history[0]));

      if (sw_history[0] == sw_history[1]) {
        SW[1] = SW[0];
        SW[0] = sw_history[0];
        if ((SW[0] == 1) && (SW[1] == 0)) {
          sw_pressed++;
          sprintf(str, "SW1 pressed %u times\n", sw_pressed);
          SYS_Error_Check(USART_Write_String(str, strlen(str)));
        }
      }
      if (SW[0] == GPIO_HIGH) {
        SYS_Error_Check(GPIO_Write(LED_YELLOW_PIN, GPIO_HIGH));
        SYS_Error_Check(GPIO_Write(LED_RED_PIN, GPIO_HIGH));
      } else {
        SYS_Error_Check(GPIO_Write(LED_YELLOW_PIN, GPIO_LOW));
        SYS_Error_Check(GPIO_Write(LED_RED_PIN, GPIO_LOW));
      }
    }
    SYS_Error_Check(USART_Read(&byte_num, &byte));
    if (byte_num > 0) {
      SYS_Error_Check(USART_Write(byte));
    }
  }
}
}
}  // Add these two closing braces

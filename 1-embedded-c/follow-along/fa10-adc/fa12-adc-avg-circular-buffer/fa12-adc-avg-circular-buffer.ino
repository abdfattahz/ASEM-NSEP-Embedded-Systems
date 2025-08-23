// arduino.ino
#include "global.h"

int main(void) {
    volatile uint32_t delay;
    volatile uint64_t LED_timeout, SW_timeout;
    uint8_t toggle = 0;
    uint8_t sw;
    uint8_t sw_history[2] = {0, 0};
    uint8_t SW[2] = {0, 0};
    uint16_t sw_pressed = 0;
    char str[20];
    uint8_t size = strlen(str);

    uint16_t ADC_value[AVG_NUM] = {0};
    uint32_t ADC_sum = 0;
    uint8_t ADC_write = 0;  // Index for circular buffer

    SYS_Error_Check(SYS_Init());
    SYS_Error_Check(USART_Init());
    SYS_Error_Check(USART_Write_String((uint8_t *)"Hello World\n",
                                       strlen("Hello World\n")));

    LED_timeout = SYS_TICK + 1000;
    SW_timeout = SYS_TICK + 20;

    for (;;) {
        SYS_Error_Check(USART_Process());

        if (SYS_TICK > LED_timeout) {
            LED_timeout = SYS_TICK + 1000;

            if (toggle) {
                SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_LOW));
                toggle = 0;
            } else {
                SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_HIGH));
                toggle = 1;
            }

            // Circular buffer logic:
            // Remove oldest value from sum
            ADC_sum -= ADC_value[ADC_write];

            // Read new ADC value into buffer
            SYS_Error_Check(ADC_Read_Single(POT_PIN, &ADC_value[ADC_write]));

            // Add new value to sum
            ADC_sum += ADC_value[ADC_write];

            // Move index forward with wrap-around (circular buffer)
            ADC_write = (ADC_write + 1) &
                        (AVG_NUM - 1);  // Requires AVG_NUM to be power of 2

            // Print average
            sprintf(str, "ADC AVG value: %u\n", ADC_sum / AVG_NUM);
            SYS_Error_Check(USART_Write_String((uint8_t *)str, strlen(str)));
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
                    SYS_Error_Check(
                        USART_Write_String((uint8_t *)str, strlen(str)));
                }
            }

            SYS_Error_Check(GPIO_Read(SW1_PIN, &sw));
            if (sw == GPIO_HIGH) {
                SYS_Error_Check(GPIO_Write(LED_RED_PIN, GPIO_HIGH));
                SYS_Error_Check(GPIO_Write(LED_BLUE_PIN, GPIO_HIGH));
                SYS_Error_Check(GPIO_Write(LED_YELLOW_PIN, GPIO_HIGH));
            } else {
                SYS_Error_Check(GPIO_Write(LED_RED_PIN, GPIO_LOW));
                SYS_Error_Check(GPIO_Write(LED_BLUE_PIN, GPIO_LOW));
                SYS_Error_Check(GPIO_Write(LED_YELLOW_PIN, GPIO_LOW));
            }
        }
    }
}

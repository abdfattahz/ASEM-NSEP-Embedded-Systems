// sys.c
#include "global.h"
#include "sys.h"

int32_t SYS_ERROR_NUM = 0;

void SYS_Fatal_Error(int32_t err) {
    SYS_ERROR_NUM = err;
    DDRB |= 0x20;
    PORTB |= 0x20;

//    Serial.println(err); 
    for(;;);  // Halt system
}

void SYS_Init(void){
    SYS_Error_Check(TIMER0_Init());
//    Serial.begin(9600);

    SYS_Error_Check(GPIO_Init());

    SYS_Error_Check(GPIO_Mode(LED_DEBUG_PIN, GPIO_OUTPUT));
    SYS_Error_Check(GPIO_Mode(LED_DEBUG_PIN2, GPIO_OUTPUT));
    SYS_Error_Check(GPIO_Mode(LED_DEBUG_PIN3, GPIO_OUTPUT));
    SYS_Error_Check(GPIO_Mode(LED_DEBUG_PIN4, GPIO_OUTPUT));

    SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_LOW));
    SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN2, GPIO_LOW));
    SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN3, GPIO_LOW));
    SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN4, GPIO_LOW));
}

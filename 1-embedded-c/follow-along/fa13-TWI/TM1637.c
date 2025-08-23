// tm1637.c
#include "global.h"

uint8_t decode7seg(uint8_t value) {
  switch(value){
    case 0: return 0xFC;
    case 1: return 0x0C;
    case 2: return 0xDA;
    case 3: return 0x9E;
    case 4: return 0x2E;
    case 5: return 0xB6;
    case 6: return 0xF6;
    case 7: return 0x1C;
    case 8: return 0xFE;
    case 9: return 0x3E;
    case 0xFF: return 0x00; // Blank digit
    default: return 0x00;
  }
}

int32_t TM1637_Init(void){
  return TM1637_SUCCESS;
}

int32_t TM1637_Write(uint16_t value) {
    uint8_t ack;
    uint8_t digits[4];
    char str[32];

    if (value > 9999) return TM1637_ERROR_RANGE;

    sprintf(str, "TM1637 value: %u\n", value);
    USART_Write_String(str, strlen(str));

    // Split value into digits (thousands to units)
    digits[3] = value / 1000;
    value %= 1000;
    digits[2] = value / 100;
    value %= 100;
    digits[1] = value / 10;
    digits[0] = value % 10;    

    // 1. Set data write mode
    SYS_Error_Check(I2C_START());
    SYS_Error_Check(I2C_Address_Write(0x40));
    SYS_Error_Check(I2C_STOP());

    Delay();

    SYS_Error_Check(I2C_START());
    SYS_Error_Check(I2C_Address_Write(0xC0));
    for (int i = 0; i < 4; i++) {
        SYS_Error_Check(I2C_Data_Send(decode7seg(digits[i]), &ack));
    }
    SYS_Error_Check(I2C_STOP());

    Delay();

    // 3. Display control
    SYS_Error_Check(I2C_START());
    SYS_Error_Check(I2C_Address_Write(0x88));
    SYS_Error_Check(I2C_STOP());

    return TM1637_SUCCESS;
}

void Delay(void){
  uint64_t timeout = SYS_TICK + 20;
  while (SYS_TICK < timeout);
}





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

void Delay(void) {
    uint64_t timeout = SYS_TICK + 2;
    while (SYS_TICK < timeout);
        // Wait
    }

int32_t TM1637_Init(void){
  return TM1637_SUCCESS;
}

int32_t TM1637_Write(uint16_t value) {
    uint8_t ack;
    uint8_t digits[4];

    if (value > 9999) return TM1637_ERROR_RANGE;

    // Split value into digits (thousands to units)
    digits[0] = (value / 1000) % 10;
    digits[1] = (value / 100) % 10;
    digits[2] = (value / 10) % 10;
    digits[3] = value % 10;

    // Optional: blank leading zeros
    for (int i = 0; i < 3; i++) {
        if (digits[i] == 0) {
            digits[i] = 0xFF;  // blank
        } else {
            break;
        }
    }

    char str[32];
    sprintf(str, "TM1637 value: %u\n", value);
    USART_Write_String((uint8_t *)str, strlen(str));

    // 1. Set data write mode
    SYS_Error_Check(I2C_START());
    SYS_Error_Check(I2C_Address_Write(0x40));
    SYS_Error_Check(I2C_STOP());

    Delay();

    // ✅ 2. Send digit data in reverse order
    SYS_Error_Check(I2C_START());
    SYS_Error_Check(I2C_Address_Write(0xC0));
    for (int i = 0; i < 4; i++) {
        SYS_Error_Check(I2C_Data_Send(decode7seg(digits[3 - i]), &ack));
    }
    SYS_Error_Check(I2C_STOP());

    Delay();

    // 3. Display control
    SYS_Error_Check(I2C_START());
    SYS_Error_Check(I2C_Address_Write(0x88));
    SYS_Error_Check(I2C_STOP());

    return TM1637_SUCCESS;
}






#include "global.h"  // if needed for types or constants

// int32_t TM1637_Init(void) {
//     return TM1637_SUCCESS;
// }

int32_t TM1637_Init(void) {
    GPIO_Mode(TM1637_CLK_PIN, GPIO_OUTPUT);
    GPIO_Mode(TM1637_DIO_PIN, GPIO_OUTPUT);
    return SYS_SUCCESS;
}

int32_t TM1637_Write(uint16_t value) {
    uint8_t ack, i;

    // First I2C write sequence
    SYS_Error_Check(I2C_START());
    SYS_Error_Check(I2C_Address_Write(0x40));
    SYS_Error_Check(I2C_STOP());

    // Second I2C write sequence
    SYS_Error_Check(I2C_START());
    SYS_Error_Check(I2C_Address_Write(0xC0));
    for (i = 0; i < 6; i++) {
        SYS_Error_Check(I2C_Data_Send(0x08, &ack));
    }
    SYS_Error_Check(I2C_STOP());

    // Third I2C read sequence
    SYS_Error_Check(I2C_START());
    SYS_Error_Check(I2C_Address_Read(0x8E));
    SYS_Error_Check(I2C_STOP());

    return TM1637_SUCCESS;
}

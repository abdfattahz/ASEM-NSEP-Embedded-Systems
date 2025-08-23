#include "global.h"

uint32_t I2C_Init(void) {
  TWSR = 0x01;                //prescaler = 4
  TWBR = 18;                  //SCL = 100kHz @ 16MHz
}

uint32_t I2C_Start(void) {
  uint64_t timeout = SYS_TICK + 10;
  TWCR = 0xA4;                //reset int., START, enable
  while (((TWCR & 0x80) == 0x00) && (SYS_TICK < timeout));      //wait till START sent

  if (SYS_TICK > timeout) return I2C_ERROR_TIMEOUT;

  if ((TWSR & 0xF8) == 0x08) return I2C_SUCCESS;    //START sent, OK
  else return I2C_ERROR_START;                //START not sent, ERROR
}

uint32_t I2C_Restart(void) {
  uint64_t timeout = SYS_TICK + 10;
  TWCR = 0xA4;                //rst int., RESTART, enable
  while (((TWCR & 0x80) == 0x00) && (SYS_TICK < timeout));      //wait till RESTART sent//

  if (SYS_TICK > timeout) return I2C_ERROR_TIMEOUT;

  if ((TWSR & 0xF8) == 0x10) return I2C_SUCCESS;    //RESTART sent, OK
  else return I2C_ERROR_RESTART;                //RESTART not sent, ERROR
}

uint32_t I2C_Address_Write(uint8_t add) {
  uint64_t timeout = SYS_TICK + 10;
  TWDR = (add << 1) & 0xFE;         //address + W
  TWCR = 0x84;                //rst int., enable
  while (((TWCR & 0x80) == 0x00) && (SYS_TICK < timeout));      //wait till address+W sent

  if (SYS_TICK > timeout) return I2C_ERROR_TIMEOUT;

  if ((TWSR & 0xF8) == 0x18) return I2C_SUCCESS;    //address + W sent OK
  else return I2C_ERROR_DEVICE_NOT_FOUND;               //ERROR
}

uint32_t I2C_Address_Read(uint8_t add) {
  uint64_t timeout = SYS_TICK + 10;
  TWDR = (add << 1) | 0x01;         //address + R
  TWCR = 0x84;                //rst int., enable
  while (((TWCR & 0x80) == 0x00) && (SYS_TICK < timeout));      //wait till address+R sent

  if (SYS_TICK > timeout) return I2C_ERROR_TIMEOUT;

  if ((TWSR & 0xF8) == 0x40) return I2C_SUCCESS;    //address + R sent OK
  else return I2C_ERROR_DEVICE_NOT_FOUND;               //ERROR
}

uint32_t I2C_Data_Send(uint8_t byte, uint8_t* ack) {
  uint64_t timeout = SYS_TICK + 10;
  TWDR = byte;                //data
  TWCR = 0x84;                //rst int., enable
  while (((TWCR & 0x80) == 0x00) && (SYS_TICK < timeout));      //wait till data sent

  if (SYS_TICK > timeout) return I2C_ERROR_TIMEOUT;

  if ((TWSR & 0xF8) == 0x28) {
    *ack = I2C_ACK;
    return I2C_SUCCESS;
  }                                                   //data sent, ACKed
  else if ((TWSR & 0xF8) == 0x30) {
    *ack = I2C_NACK;
    return I2C_SUCCESS;
  }                   //data sent, not ACKed
  else return I2C_ERROR_DATA_WRITE;               //ERROR
}


uint32_t I2C_Data_Read(uint8_t* data) {
  uint64_t timeout = SYS_TICK + 10;
  TWCR = 0x84;                //rst int., enable
  while (((TWCR & 0x80) == 0x00) && (SYS_TICK < timeout));      //wait till data sent
  *data = TWDR;               //data

  if (SYS_TICK > timeout) return I2C_ERROR_TIMEOUT;

  if ((TWSR & 0xF8) == 0x58) return I2C_SUCCESS;    //data read no ACK OK
  else return I2C_ERROR_DATA_READ;                //ERROR
}

uint32_t I2C_Data_Read_ACK(uint8_t* data) {
  uint64_t timeout = SYS_TICK + 10;
  TWCR = 0xC4;                //rst int., ACK, enable
  while (((TWCR & 0x80) == 0x00) && (SYS_TICK < timeout));      //wait till data sent
  *data = TWDR;               //data

  if (SYS_TICK > timeout) return I2C_ERROR_TIMEOUT;

  if ((TWSR & 0xF8) == 0x50) return I2C_SUCCESS;    //data read ACK OK
  else return I2C_ERROR_DATA_READ;                //ERROR
}

uint32_t I2C_Stop(void) {
  TWCR = 0x94;                //reset int., STOP, enable
  while ((TWCR & 0x10) == 0x10);      //wait till STOP sent
  return I2C_SUCCESS;
}

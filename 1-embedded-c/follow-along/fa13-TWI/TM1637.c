#include "global.h"

int32_t decode7seg(uint16_t value){
  switch(value){
    case 0 : return 0xFC;
    case 1 : return 0x0C;
    case 2 : return 0xDA;
    case 3 : return 0x9E;
    case 4 : return 0x2E;
    case 5 : return 0xB6;
    case 6 : return 0xF6;
    case 7 : return 0x1C;
    case 8 : return 0xFE;
    case 9 : return 0xBE;
    case 10 : return 0x01;        //  :
    case 11 : return 0x02;        //  -- --
    case 12 : return 0x04;        //  c
    case 13 : return 0x08;        //  b
    case 14 : return 0x10;        //  a
    case 15 : return 0x20;        //  f
    case 16 : return 0x40;        //  e
    case 17 : return 0x80;        //  d
    case 18 : return 0xFF;        // 88:88

    default : return 0x00;
  }
}

void Delay(void){
  uint64_t timeout = SYS_TICK + 20;
  while(SYS_TICK<timeout); 
}
int32_t TM1637_Init(void){
  return TM1637_SUCCESS;
}

int32_t TM1637_Write(uint16_t value){
  uint8_t ack, i, disp[6];
  char str[20];

  if(value > 9999) return TM1637_ERROR_RANGE;

  sprintf(str, "value = %u\n", value);
  USART_Write_String(str, strlen(str));

  disp[3] = value / 1000;
  value %= 1000;
  disp[2] = value / 100;
  value %= 100;
  disp[1] = value / 10;
  disp[0] = value % 10;

  SYS_Error_Check(I2C_START());
  SYS_Error_Check(I2C_Address_Write(0x40));
  SYS_Error_Check(I2C_STOP());

  Delay();
  SYS_Error_Check(I2C_START());
  SYS_Error_Check(I2C_Address_Write(0xC0));
  
  for(i=0;i<6;i++){
    SYS_Error_Check(I2C_Data_Send(decode7seg(i),&ack));
  }
  
  SYS_Error_Check(I2C_STOP());

  Delay();
  SYS_Error_Check(I2C_START());
  SYS_Error_Check(I2C_Address_Read(0x8E));
  SYS_Error_Check(I2C_STOP());

  return TM1637_SUCCESS;
}

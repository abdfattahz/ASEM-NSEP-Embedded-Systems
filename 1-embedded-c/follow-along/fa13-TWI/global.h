//global.h
#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#include "sys.h"
#include "gpio.h"
#include "timer0.h"
#include "usart.h"
#include "adc.h"
#include "i2c.h"
#include "tm1637.h"


#define LED_DEBUG_PIN     13
#define SYS_F_CPU   16000000UL
#define TM1637_CLK_PIN  2  // PD2 = Digital pin 2
#define TM1637_DIO_PIN  3  // PD3 = Digital pin 3

#endif

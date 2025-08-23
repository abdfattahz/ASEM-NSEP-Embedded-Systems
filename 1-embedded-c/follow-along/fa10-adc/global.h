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

#define LED_DEBUG_PIN     13
#define SYS_F_CPU   16000000UL
#endif

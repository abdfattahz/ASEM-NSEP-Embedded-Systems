#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#include "sys.h"
#include "gpio.h"
#include "timer.h"
#include "usart.h"
#include "adc.h"
#include "i2c.h"
#include "TM1637.h"

#define LED_DEBUG_PIN  13  // Built-in LED
#define LED_GREEN_PIN 8   // External LED
#define LED_YELLOW_PIN 6   // External LED
#define LED_RED_PIN 4   // External LED
#define SW1_PIN 2
#define POT_PIN 0

#endif

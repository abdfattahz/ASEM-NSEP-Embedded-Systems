#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdint.h>
#include <avr/io.h>

#define LED_DEBUG_PIN     5
#define LED_DEBUG_DDR     DDRB
#define LED_DEBUG_PORT    PORTB

#define LED_DELAY         100000 

#include "gpio.h"

#endif // __GLOBAL_H__

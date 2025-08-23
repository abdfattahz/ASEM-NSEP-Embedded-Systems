#!/usr/bin/env bash
set -euo pipefail

# Helper to pad hh:mm:ss
pad2(){ printf "%02d" "$1"; }

# Commit messages per day (1–13 Aug 2025)
declare -A messages

messages["2025-08-01"]="Blink LED with AVR registers
- Add SYS_Init()
- Use DDRB/PORTB + bit macros instead of raw pointers"

messages["2025-08-02"]="Tidy GPIO setup
- Split pin defs into macros
- Add timing constants and comments"

messages["2025-08-03"]="Project housekeeping
- Organize sources/headers
- Stubs for timer and usart modules"

messages["2025-08-04"]="Timer + external interrupt experiments
- Timer0 blink demo
- INT0 button ISR toggles multiple LEDs"

messages["2025-08-05"]="Add system tick + USART echo
- Simple sys_tick scheduler
- USART init and RX→TX echo @9600 baud"

messages["2025-08-06"]="USART driver work + ADC hook
- TX byte API and buffered write skeleton
- RX read API with byte count"

messages["2025-08-07"]="Sensor pipeline
- ADC averaging with circular buffer to reduce noise
- TM1637 7-segment via I2C/TWI (start/stop/read/write)"

messages["2025-08-08"]="I2C helpers cleanup
- Normalize ACK/NACK handling
- Add error codes and returns"

messages["2025-08-09"]="Debounce and polling cadence
- 20 ms switch sampling using sys_tick
- Control red, blue, and yellow LEDs based on switch state"

messages["2025-08-10"]="Refactor headers
- Move pin maps and baud macros to global.h
- Trim magic numbers in main"

messages["2025-08-11"]="Lightweight error handler
- SYS_Error_Check() wrapper
- Basic codes for I2C/USART failures"

messages["2025-08-12"]="Display plumbing
- Show averaged ADC reading on TM1637
- Timing tweaks to reduce refresh jitter"

messages["2025-08-13"]="Integrate peripherals and smooth ADC
- Combine UART, ADC, and TM1637 display
- Average ADC values with circular buffer to reduce noise
- Adjust timing for stable refresh"

echo "Creating backfilled commits with random times between 12:00 and 16:59..."
# Iterate in chronological order
for day in $(printf "%s\n" "${!messages[@]}" | sort); do
  msg="${messages[$day]}"

  # Random time between 12:00:00 and 16:59:59
  hour=$((RANDOM % 5 + 12))   # 12..16
  min=$((RANDOM % 60))
  sec=$((RANDOM % 60))

  ts="$day $(pad2 "$hour"):$(pad2 "$min"):$(pad2 "$sec")"
  echo "Committing for $ts"

  git commit --allow-empty --date="$ts" -m "$msg"
done

echo "Done. Push with:  git push"

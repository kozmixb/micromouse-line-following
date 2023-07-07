#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Hardware mapping
const uint8_t USER_IO = 6;
const uint8_t LED_RIGHT = 6; // an alias for USER_IO
const uint8_t MOTOR_LEFT_DIR = 7;
const uint8_t MOTOR_RIGHT_DIR = 8;
const uint8_t MOTOR_LEFT_PWM = 9;
const uint8_t MOTOR_RIGHT_PWM = 10;
const uint8_t LED_LEFT = 11; // an alias for EMITTER_B
const uint8_t EMITTER_A = 11;
const uint8_t EMITTER_B = 12;
const uint8_t EMITTER = 12; // alias for pin 12

const uint8_t FUNCTION_PIN = A6;
const uint8_t BATTERY_VOLTS = A7;

#endif

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Arduino
const uint32_t BAUDRATE = 115200;

// Motors
const uint8_t MOTOR_LEFT_DIR = 7;
const uint8_t MOTOR_RIGHT_DIR = 8;
const uint8_t MOTOR_LEFT_PWM = 9;
const uint8_t MOTOR_RIGHT_PWM = 10;
const int MOTOR_LEFT_POLARITY = (1);
const int MOTOR_RIGHT_POLARITY = (1);
const float MAX_MOTOR_VOLTS = 6.0;

// Indicators
const uint8_t LED_RIGHT = 6;
const uint8_t LED_LEFT = 11;

// Emitters
const uint8_t EMITTER = 12;

const uint8_t USER_IO = 6;
const uint8_t EMITTER_A = 11;
const uint8_t EMITTER_B = 12;

const uint8_t FUNCTION_PIN = A6;
const uint8_t BATTERY_VOLTS = A7;

#endif

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

// Sensors
const uint8_t LINE_SENSOR_RIGHT = A0;
const uint8_t LINE_SENSOR_FRONT_RIGHT = A1;
const uint8_t LINE_SENSOR_FRONT_LEFT = A2;
const uint8_t LINE_SENSOR_LEFT = A3;
const uint8_t SENSOR_4 = A4;
const uint8_t SENSOR_5 = A5;
const uint8_t SENSOR_INTERVAL = 500;

#endif

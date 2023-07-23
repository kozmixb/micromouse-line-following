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

const uint8_t FUNCTION_PIN = A6;
const uint8_t BATTERY_PIN = A7;

// Battery
const float MAX_MOTOR_VOLTS = 6.0;
static const float BATTERY_R1 = 10000.0;  // resistor to battery +
static const float BATTERY_R2 = 10000.0;  // resistor to Gnd
static const float BATTERY_DIVIDER_RATIO =
    BATTERY_R2 / (BATTERY_R1 + BATTERY_R2);
static const float ADC_FSR = 1023.0;       // The maximum reading for the ADC
static const float ADC_REF_VOLTS = 4.987;  // Reference voltage of ADC

const float BATTERY_MULTIPLIER =
    (ADC_REF_VOLTS / ADC_FSR / BATTERY_DIVIDER_RATIO);

const float WHEEL_DIAMETER = 31.966;  // 33.298

const float MOUSE_RADIUS = 37.92;  // 39.50;

#endif

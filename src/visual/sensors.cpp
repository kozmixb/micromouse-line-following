#include "sensors.h"

#include <Arduino.h>

#include "config.h"
#include "debug.h"
#include "emitters.h"
#include "sensor.h"

Sensors::Sensors()
    : sensor_right(LINE_SENSOR_RIGHT),
      sensor_front_right(LINE_SENSOR_FRONT_RIGHT),
      sensor_front_left(LINE_SENSOR_FRONT_LEFT),
      sensor_left(LINE_SENSOR_LEFT) {}

void Sensors::calibrate() {
    emitters_on();
    if (millis() % SENSOR_INTERVAL == 0) {
        sensor_right.calibrate();
        sensor_front_right.calibrate();
        sensor_front_left.calibrate();
        sensor_left.calibrate();
    }
}

void Sensors::test() {
    emitters_on();
    if (millis() % SENSOR_INTERVAL == 0) {
        log_message("SLeft: " + String(sensor_left.read()));
        log_message("SFLeft: " + String(sensor_front_left.read()));
        log_message("SFRigh: " + String(sensor_front_right.read()));
        log_message("SRight: " + String(sensor_right.read()));
    }
}

Sensor Sensors::right() { return sensor_right; }

Sensor Sensors::front_right() { return sensor_front_right; }

Sensor Sensors::front_left() { return sensor_front_left; }

Sensor Sensors::left() { return sensor_left; }

#include "sensors.h"

#include "config.h"
#include "debug.h"
#include "sensor.h"

Sensors& Sensors::instance() {
    static Sensors INSTANCE;

    return INSTANCE;
}

Sensors::Sensors()
    : sensor_right(LINE_SENSOR_RIGHT),
      sensor_front_right(LINE_SENSOR_FRONT_RIGHT),
      sensor_front_left(LINE_SENSOR_FRONT_LEFT),
      sensor_left(LINE_SENSOR_LEFT) {}

void Sensors::enable() {
    if (!sensors_enabled) {
        sensors_enabled = true;
    }
}

void Sensors::log() {
    add_message(String("sensor_left"), String(sensor_left.read()));
    add_message(String("sensor_front_left"), String(sensor_front_left.read()));
    add_message(String("sensor_front_right"),
                String(sensor_front_right.read()));
    add_message(String("sensor_right"), String(sensor_right.read()));
}

Sensor& Sensors::right() { return sensor_right; }

Sensor& Sensors::front_right() { return sensor_front_right; }

Sensor& Sensors::front_left() { return sensor_front_left; }

Sensor& Sensors::left() { return sensor_left; }

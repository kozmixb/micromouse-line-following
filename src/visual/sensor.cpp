#include "sensor.h"

#include <Arduino.h>

#include "debug.h"

Sensor::Sensor(const uint8_t pin) : _pin(pin), _min(1024), _max(0) {
    pinMode(pin, INPUT);
}

void Sensor::calibrate() { read_raw(); }

byte Sensor::read() { return map(read_raw(), _min, _max, 0, 100); }

int Sensor::read_raw() {
    int value = analogRead(_pin);

    if (value < _min) {
        _min = value;
    }

    if (value > _max) {
        _max = value;
    }

    log_message(String(_min) + " - " + String(_max) + " = " + String(value));

    return value;
}

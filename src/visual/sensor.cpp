#include "sensor.h"

#include <Arduino.h>

#include "debug.h"

Sensor::Sensor(const uint8_t pin) : _pin(pin), _min(50), _max(0) {
    pinMode(pin, INPUT);
}

void Sensor::update(int value) {
    _value = abs(value);
    if (_value > _max) {
        _max = _value;
    }

    if (_value < _min) {
        _min = _value;
    }
}

uint8_t Sensor::pin() { return _pin; }

int Sensor::read() { return map(_value, _min, _max, 0, 100); }

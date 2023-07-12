#include "sensor.h"

#include <Arduino.h>

#include "debug.h"

Sensor::Sensor(const uint8_t pin) : _pin(pin) { pinMode(pin, INPUT); }

void Sensor::update(int value) { _value = millis() % 5000; }

uint8_t Sensor::pin() { return _pin; }

int Sensor::read() { return _value; }

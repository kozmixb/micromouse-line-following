#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
   public:
    Sensor(const uint8_t pin);
    void update(int value);
    int read();
    uint8_t pin();

   private:
    uint8_t _pin;
    int _value;
};

#endif

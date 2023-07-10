#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
   public:
    Sensor(const uint8_t pin);
    void calibrate();
    void update(int value);
    byte read();
    uint8_t pin();

   private:
    int read_raw();
    uint8_t _pin;
    int _min;
    int _max;
    int _value;
};

#endif

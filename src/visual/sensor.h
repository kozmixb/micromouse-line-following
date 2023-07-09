#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
   public:
    Sensor(const uint8_t pin);
    void calibrate();
    byte read();

   private:
    int read_raw();
    uint8_t _pin;
    int _min;
    int _max;
};

#endif

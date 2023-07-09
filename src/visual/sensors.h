#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

#include "sensor.h"

class Sensors {
   public:
    Sensors();
    void calibrate();
    void test();
    Sensor right();
    Sensor front_right();
    Sensor front_left();
    Sensor left();

   private:
    Sensor sensor_right;
    Sensor sensor_front_right;
    Sensor sensor_front_left;
    Sensor sensor_left;
};

#endif

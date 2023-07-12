#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

#include "sensor.h"

class Sensors {
   public:
    static Sensors& instance();
    void test();
    void enable();
    Sensor right();
    Sensor front_right();
    Sensor front_left();
    Sensor left();

   private:
    Sensors();
    Sensor sensor_right;
    Sensor sensor_front_right;
    Sensor sensor_front_left;
    Sensor sensor_left;
    bool sensors_enabled = false;
};

#endif

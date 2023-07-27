#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

enum { PWM_488_HZ, PWM_3906_HZ, PWM_31250_HZ };

class MotorControl {
    void init();
    void setFrequency(int frequency = PWM_31250_HZ);
    void setSpeed(int left, int right);

   public:
    MotorControl();
    void test();
    void stop();
    void turn(int angle, bool reset = false);
};

#endif

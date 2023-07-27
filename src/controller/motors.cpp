#include <Arduino.h>
#include <Controller/MotorControl.h>
#include <digitalWriteFast.h>

#include "config.h"

static void set_left_pwm(int pwm) {
    pwm = MOTOR_LEFT_POLARITY * constrain(pwm, -255, 255);

    if (pwm < 0) {
        digitalWriteFast(MOTOR_LEFT_DIR, 1);
        analogWrite(MOTOR_LEFT_PWM, -pwm);
        return;
    }

    digitalWriteFast(MOTOR_LEFT_DIR, 0);
    analogWrite(MOTOR_LEFT_PWM, pwm);
}

static void set_right_pwm(int pwm) {
    pwm = MOTOR_RIGHT_POLARITY * constrain(pwm, -255, 255);

    if (pwm < 0) {
        digitalWriteFast(MOTOR_RIGHT_DIR, 1);
        analogWrite(MOTOR_RIGHT_PWM, -pwm);
        return;
    }

    digitalWriteFast(MOTOR_RIGHT_DIR, 0);
    analogWrite(MOTOR_RIGHT_PWM, pwm);
}

void MotorControl::init() {
    pinMode(MOTOR_LEFT_DIR, OUTPUT);
    pinMode(MOTOR_RIGHT_DIR, OUTPUT);
    pinMode(MOTOR_LEFT_PWM, OUTPUT);
    pinMode(MOTOR_RIGHT_PWM, OUTPUT);
    digitalWriteFast(MOTOR_LEFT_PWM, 0);
    digitalWriteFast(MOTOR_LEFT_DIR, 0);
    digitalWriteFast(MOTOR_RIGHT_PWM, 0);
    digitalWriteFast(MOTOR_RIGHT_DIR, 0);
    setFrequency();
}

void MotorControl::setSpeed(int left, int right) {
    set_left_pwm(left);
    set_right_pwm(right);
}

void MotorControl::setFrequency(int frequency) {
    switch (frequency) {
        case PWM_31250_HZ:
            // Divide by 1. frequency = 31.25 kHz;
            bitClear(TCCR1B, CS11);
            bitSet(TCCR1B, CS10);
            break;

        case PWM_3906_HZ:
            // Divide by 8. frequency = 3.91 kHz;
            bitSet(TCCR1B, CS11);
            bitClear(TCCR1B, CS10);
            break;

        case PWM_488_HZ:
        default:
            // Divide by 64. frequency = 488Hz;
            bitSet(TCCR1B, CS11);
            bitSet(TCCR1B, CS10);
            break;
    }
}

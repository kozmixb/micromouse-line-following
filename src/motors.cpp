#include "motors.h"
#include "config.h"
#include "digitalWriteFast.h"
#include <Arduino.h>

static bool s_controllers_output_enabled;
static float s_old_fwd_error;
static float s_old_rot_error;
static float s_fwd_error;
static float s_rot_error;

void reset_motor_controllers()
{
    s_fwd_error = 0;
    s_rot_error = 0;
    s_old_fwd_error = 0;
    s_old_rot_error = 0;
}

void setup_motors()
{
    pinMode(MOTOR_LEFT_DIR, OUTPUT);
    pinMode(MOTOR_RIGHT_DIR, OUTPUT);
    pinMode(MOTOR_LEFT_PWM, OUTPUT);
    pinMode(MOTOR_RIGHT_PWM, OUTPUT);
    digitalWriteFast(MOTOR_LEFT_PWM, 0);
    digitalWriteFast(MOTOR_LEFT_DIR, 0);
    digitalWriteFast(MOTOR_RIGHT_PWM, 0);
    digitalWriteFast(MOTOR_RIGHT_DIR, 0);
    set_motor_pwm_frequency();
}

void set_left_motor_pwm(int pwm)
{
    pwm = MOTOR_LEFT_POLARITY * constrain(pwm, -255, 255);
    if (pwm < 0)
    {
        digitalWriteFast(MOTOR_LEFT_DIR, 1);
        analogWrite(MOTOR_LEFT_PWM, -pwm);
    }
    else
    {
        digitalWriteFast(MOTOR_LEFT_DIR, 0);
        analogWrite(MOTOR_LEFT_PWM, pwm);
    }
}

void set_right_motor_pwm(int pwm)
{
    pwm = MOTOR_RIGHT_POLARITY * constrain(pwm, -255, 255);
    if (pwm < 0)
    {
        digitalWriteFast(MOTOR_RIGHT_DIR, 1);
        analogWrite(MOTOR_RIGHT_PWM, -pwm);
    }
    else
    {
        digitalWriteFast(MOTOR_RIGHT_DIR, 0);
        analogWrite(MOTOR_RIGHT_PWM, pwm);
    }
}

void set_motor_pwm_frequency(int frequency)
{
    switch (frequency)
    {
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

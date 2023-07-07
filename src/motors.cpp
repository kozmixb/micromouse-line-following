#include "motors.h"
#include "config.h"
#include "digitalWriteFast.h"
#include <Arduino.h>

static bool s_controllers_output_enabled;
static float s_old_fwd_error;
static float s_old_rot_error;
static float s_fwd_error;
static float s_rot_error;
Profile forward;
Profile rotation;

void enable_motor_controllers()
{
    s_controllers_output_enabled = true;
}

void disable_motor_controllers()
{
    s_controllers_output_enabled = false;
}

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
    stop_motors();
}

float position_controller()
{
    s_fwd_error += forward.increment() - robot_fwd_increment();
    float diff = s_fwd_error - s_old_fwd_error;
    s_old_fwd_error = s_fwd_error;
    float output = settings.fwdKP * s_fwd_error + settings.fwdKD * diff;
    return output;
}

float angle_controller(float steering_adjustment)
{
    s_rot_error += rotation.increment() - robot_rot_increment();
    if (g_steering_enabled)
    {
        s_rot_error += steering_adjustment;
    }
    float diff = s_rot_error - s_old_rot_error;
    s_old_rot_error = s_rot_error;
    float output = settings.rotKP * s_rot_error + settings.rotKD * diff;
    return output;
}

void update_motor_controllers(float steering_adjustment)
{
    float pos_output = position_controller();
    float rot_output = angle_controller(steering_adjustment);
    float left_output = 0;
    float right_output = 0;
    left_output += pos_output;
    right_output += pos_output;
    left_output -= rot_output;
    right_output += rot_output;
    float v_fwd = forward.speed();
    float v_rot = rotation.speed();
    float v_left = v_fwd - (PI / 180.0) * MOUSE_RADIUS * v_rot;
    float v_right = v_fwd + (PI / 180.0) * MOUSE_RADIUS * v_rot;
    left_output += SPEED_FF * v_left;
    right_output += SPEED_FF * v_right;
    if (s_controllers_output_enabled)
    {
        set_right_motor_volts(right_output);
        set_left_motor_volts(left_output);
    }
}
/**
 * Direct register access could be used here for enhanced performance
 */
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

void set_left_motor_volts(float volts)
{
    volts = constrain(volts, -MAX_MOTOR_VOLTS, MAX_MOTOR_VOLTS);
    g_left_motor_volts = volts;
    int motorPWM = (int)(volts * g_battery_scale);
    set_left_motor_pwm(motorPWM);
}

void set_right_motor_volts(float volts)
{
    volts = constrain(volts, -MAX_MOTOR_VOLTS, MAX_MOTOR_VOLTS);
    g_right_motor_volts = volts;
    int motorPWM = (int)(volts * g_battery_scale);
    set_right_motor_pwm(motorPWM);
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

void stop_motors()
{
    set_left_motor_volts(0);
    set_right_motor_volts(0);
}

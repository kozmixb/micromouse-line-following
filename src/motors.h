#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

void enable_motor_controllers();
void disable_motor_controllers();
void reset_motor_controllers();

/***
 * The motors module provides low  control of the drive motors
 * in a two-wheel differential drive robot.
 */

void update_motor_controllers(float steering_adjustment);

enum
{
    PWM_488_HZ,
    PWM_3906_HZ,
    PWM_31250_HZ
};

/***
 *  - set the motor driver pins as outputs
 *  - configure direction to be forwards
 *  - set pwm frequency to default 32kHz
 *  - set pwm drive to zero
 * @brief configure pins and pwm for motor drive
 */
void setup_motors();

/***
 * @brief write zero volts to both motors
 */
void stop_motors();

/***
 * @brief set the motor pwn drive to one of three possible values
 */
void set_motor_pwm_frequency(int frequency = PWM_31250_HZ);

/***
 * -255 <= pwm <= 255
 * @brief set motor direction and PWM
 */
void set_left_motor_pwm(int pwm);
void set_right_motor_pwm(int pwm);

#endif

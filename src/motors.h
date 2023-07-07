#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

extern float g_left_motor_volts;
extern float g_right_motor_volts;

//***************************************************************************//

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

/***
 * The input voltage be any value and will be scaled to compensate for changes
 * in battery voltage such that maximum drive to the motors is limited to the
 * value of MAX_MOTOR_VOLTS in the defaults (normally +/- 6.0 Volts)
 * @brief adjust the motor PWM to deliver the given volate to the motor
 */
void set_left_motor_volts(float volts);
void set_right_motor_volts(float volts);

#endif

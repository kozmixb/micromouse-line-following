#ifndef MOTORS_H
#define MOTORS_H

enum { PWM_488_HZ, PWM_3906_HZ, PWM_31250_HZ };

void setup_motors();
void set_motor_pwm_frequency(int frequency = PWM_31250_HZ);
void set_left_motor_pwm(int pwm);
void set_right_motor_pwm(int pwm);
void motors_test();

#endif

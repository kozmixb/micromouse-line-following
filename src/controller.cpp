#include <Arduino.h>

#include "config.h"
#include "motors.h"

unsigned int turn_started = 0;
static bool turning = false;

static float wheel_distance_per_rotation() { return WHEEL_DIAMETER * PI; }

static float mouse_circumfence() { return 2 * MOUSE_RADIUS * PI; }

static unsigned int calculate_spin(byte speed) {
    float percentage = (float)map(speed, 0, 255, 0, 100) / 100;
    byte max_rpm = 200;
    float angular_speed = ((max_rpm * percentage) * 2 * PI) / 60;
    float time_per_revolution = wheel_distance_per_rotation() / angular_speed;
    float ratio = mouse_circumfence() / wheel_distance_per_rotation();

    return (int)(time_per_revolution * ratio * 1000);
}

void stop_motors() {
    set_left_motor_pwm(0);
    set_right_motor_pwm(0);
}

void spin_360() {
    if (!turning) {
        turn_started = millis();
        turning = true;
    }

    if (turning && (millis() - turn_started) < calculate_spin(100)) {
        Serial.println(calculate_spin(100));
        set_left_motor_pwm(100);
        set_right_motor_pwm(-100);
        return;
    }

    stop_motors();
}

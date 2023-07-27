#include <Controller/MotorControl.h>

#include "config.h"
#include "debug.h"

static byte const REFRESH_INTERVAL = 20;
static byte speed = 100;
static unsigned long started_at;
static unsigned long checked_at;
static byte step = 0;
static bool finished = true;

static float calculateAngleTime(int angle) {
    return (679.00 * (abs(angle) / 360.00) / WHEEL_CIRCUMFENCE) *
           MOUSE_CIRCUMFENCE;
}

MotorControl::MotorControl() { init(); }

void MotorControl::test() {
    unsigned long current = millis();

    if (current > checked_at + REFRESH_INTERVAL) {
        add_message(String("Test step"), step);
        switch (step) {
            case 1:
                turn(90);
                break;

            case 2:
                turn(-180);
                break;

            case 3:
                turn(270);
                break;

            case 4:
                turn(-360);
                break;

            case 5:
                turn(180);
                break;

            default:
                stop();
        }

        checked_at = current;

        if (finished && step < 7) {
            step++;
            started_at = 0;
            delay(500);
        }
    }
}

void MotorControl::stop() { setSpeed(0, 0); }

void MotorControl::turn(int angle, bool reset) {
    unsigned long current = millis();

    if (reset | !started_at) {
        started_at = current;
        finished = false;
    }

    if (current > started_at + calculateAngleTime(angle)) {
        setSpeed(0, 0);
        finished = true;
        return;
    }

    if (current > checked_at + REFRESH_INTERVAL) {
        add_message(String("Turning"), angle);
        checked_at = current;

        if (angle > 0) {
            setSpeed(speed, -speed);
            return;
        }

        setSpeed(-speed, speed);
    }
}

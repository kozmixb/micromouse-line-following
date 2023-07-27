#include <Arduino.h>
#include <Controller/MotorControl.h>

#include "utils/battery.h"
#include "utils/indicator.h"
#include "utils/switch.h"
#include "visual/emitters.h"
#include "visual/sensors.h"

static const unsigned int DELAY = 3000;
static unsigned int process_started = 0;
static bool calibrated = false;

void run_profile(byte profile, MotorControl motors) {
    unsigned long current = millis();

    switch (profile) {
        case 1:
            // debug
            motors.test();
            emitters_enable();
            Sensors::instance().log();
            log_battery();
            break;
        case 2:
            // calibration
            if (!process_started) {
                indicator_right();
                process_started = current;
                emitters_enable();
            }

            if (current < process_started + DELAY) {
                // sleep
                return;
            }

            if (current < process_started + DELAY + 5000) {
                motors.turn(360);
                return;
            }

            if (!calibrated) {
                calibrated = true;
                motors.stop();
                emitters_disable();
                indicator_left();
            }

            break;
        default:
            process_started = 0;
            log_switch();
            emitters_disable();
            indicators_off();
            motors.stop();
            break;
    }
}

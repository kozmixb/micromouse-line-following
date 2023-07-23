#include <Arduino.h>

#include "controller.h"
#include "motors.h"
#include "utils/battery.h"
#include "utils/indicator.h"
#include "utils/switch.h"
#include "visual/emitters.h"
#include "visual/sensors.h"

static const unsigned int DELAY = 3000;
static unsigned int process_started = 0;
static bool calibrated = false;

void run_profile(byte profile) {
    switch (profile) {
        case 1:
            // debug
            stop_motors();
            emitters_enable();
            Sensors::instance().log();
            log_battery();
            break;
        case 2:
            // calibration
            if (!process_started) {
                indicator_right();
                process_started = millis();
                emitters_enable();
            }

            if ((millis() - process_started) < DELAY) {
                // sleep
                return;
            }

            if ((millis() - process_started - DELAY) < 5000) {
                spin_360();
                return;
            }

            if (!calibrated) {
                calibrated = true;
                stop_motors();
                emitters_disable();
                indicator_left();
            }

            break;
        default:
            process_started = 0;
            log_switch();
            emitters_disable();
            indicators_off();
            break;
    }
}

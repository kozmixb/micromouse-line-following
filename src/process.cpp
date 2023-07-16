#include <Arduino.h>

#include "utils/battery.h"
#include "utils/indicator.h"
#include "utils/switch.h"
#include "visual/emitters.h"
#include "visual/sensors.h"

void run_profile(byte profile) {
    switch (profile) {
        case 1:
            emitters_enable();
            Sensors::instance().log();
            log_battery();
            break;

        default:
            log_switch();
            emitters_disable();
            indicators_off();
            break;
    }
}

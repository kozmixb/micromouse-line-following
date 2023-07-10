#include <Arduino.h>

#include "config.h"
#include "debug.h"
#include "motors.h"
#include "visual/emitters.h"
#include "visual/indicator.h"
#include "visual/sensors.h"

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    enable_debug();
    setup_motors();
    setup_indicators();
    setup_emitters();
}

void loop() {
    // indicators_test();
    if (millis() < 10000) {
        Sensors::instance().calibrate();
        return;
    }

    Sensors::instance().test();
    log_new_line();
}

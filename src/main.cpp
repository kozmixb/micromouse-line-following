#include <Arduino.h>

#include "config.h"
#include "debug.h"
#include "motors.h"
#include "visual/emitters.h"
#include "visual/indicator.h"
#include "visual/sensors.h"

Sensors sensors;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    enable_debug();
    setup_motors();
    setup_indicators();
    setup_emitters();
    Sensors sensors();
}

void loop() {
    // indicators_test();
    if (millis() < 10000) {
        sensors.calibrate();
        return;
    }

    sensors.test();
    log_new_line();
}

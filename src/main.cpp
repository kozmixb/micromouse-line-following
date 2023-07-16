#include "config.h"
#include "debug.h"
#include "interrupts.h"
#include "lib/adc.h"
#include "motors.h"
#include "utils/battery.h"
#include "utils/indicator.h"
#include "visual/emitters.h"
#include "visual/sensors.h"

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    enable_debug();
    setup_motors();
    enable_indicators();
    setup_emitters();
    setup_adc();
    enable_timer_interrupt();
}

void loop() {
    Sensors::instance().enable();
    Sensors::instance().log();

    log_battery();
    print_message();
}

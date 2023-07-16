#include <Arduino.h>

#include "debug.h"
#include "interrupts.h"
#include "motors.h"
#include "process.h"
#include "utils/indicator.h"
#include "utils/switch.h"
#include "visual/emitters.h"
#include "visual/sensors.h"

byte active_profile = 255;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    enable_debug();
    setup_motors();
    enable_indicators();
    setup_emitters();
    enable_timer_interrupt();
    delay(150);
}

void loop() {
    if (button_pressed()) {
        run_profile(255);
        wait_for_button_release();
        delay(150);

        active_profile = get_profile_version();
    }

    run_profile(active_profile);
    print_message();
}

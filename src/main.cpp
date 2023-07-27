#include <Arduino.h>
#include <Controller/MotorControl.h>

#include "debug.h"
#include "interrupts.h"
#include "process.h"
#include "utils/indicator.h"
#include "utils/switch.h"
#include "visual/emitters.h"
#include "visual/sensors.h"

byte active_profile = 255;
MotorControl motors;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    enable_debug();
    enable_indicators();
    setup_emitters();
    enable_timer_interrupt();
    delay(150);
}

void loop() {
    if (button_pressed()) {
        run_profile(255, motors);
        wait_for_button_release();
        delay(150);

        active_profile = get_profile_version();
    }

    run_profile(active_profile, motors);
    print_message();
}

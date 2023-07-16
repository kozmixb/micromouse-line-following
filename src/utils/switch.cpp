#include <Arduino.h>

#include "config.h"
#include "debug.h"

static byte current = 255;

void update_switch_status(int adc) {
    const int adc_thesholds[] = {1023, 660, 647, 630, 614, 590, 570, 545, 522,
                                 461,  429, 385, 343, 271, 212, 128, 44,  0};

    for (int i = 0; i < 17; i++) {
        if (adc > (adc_thesholds[i] + adc_thesholds[i + 1]) / 2) {
            current = i;
            return;
        }
    }

    current = 255;
}

void log_switch() { add_message(String("profile"), String(current)); }

bool button_pressed() { return current == 0; }

void wait_for_button_release() {
    while (button_pressed()) {
        delay(10);
    }
}

byte get_profile_version() { return current; }

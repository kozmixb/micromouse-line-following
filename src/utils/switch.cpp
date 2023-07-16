#include <Arduino.h>

#include "config.h"

static byte active_profile;

void update_switch_status(int adc) {
    const int adc_thesholds[] = {1023, 660, 647, 630, 614, 590, 570, 545, 522,
                                 461,  429, 385, 343, 271, 212, 128, 44,  0};

    for (int i = 0; i < 17; i++) {
        if (adc > (adc_thesholds[i] + adc_thesholds[i + 1]) / 2) {
            active_profile = i;
            return;
        }
    }

    active_profile = 255;
}

byte get_profile_version() { return active_profile; }

#include <Arduino.h>

#include "config.h"

bool enabled = false;
bool written = false;

void enable_debug() {
    Serial.begin(BAUDRATE);
    enabled = true;
}

void log_message(const String &message) {
    if (enabled) {
        if (written) {
            Serial.print(" | ");
        }

        Serial.print(message);
        written = true;
    }
}

void log_new_line() {
    if (enabled && written) {
        Serial.println("");
        written = false;
    }
}

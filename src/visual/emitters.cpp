#include <Arduino.h>

#include "config.h"
#include "debug.h"
#include "lib/digitalWriteFast.h"

void setup_emitters() {
    pinMode(EMITTER, OUTPUT);
    digitalWriteFast(EMITTER, LOW);
}

void emitters_test() {
    if ((millis() / DEBUG_INTERVAL) % 2) {
        if (digitalRead(EMITTER) == LOW) {
            log_message("Emitters: ON");
        }

        digitalWriteFast(EMITTER, HIGH);

        return;
    }

    if (digitalRead(EMITTER) == HIGH) {
        log_message("Emitters: OFF");
    }

    digitalWriteFast(EMITTER, LOW);
}

#include <Arduino.h>

#include "config.h"
#include "debug.h"
#include "lib/digitalWriteFast.h"

void setup_emitters() {
    pinMode(EMITTER, OUTPUT);
    digitalWriteFast(EMITTER, LOW);
}

void emitters_on() {
    if (digitalRead(EMITTER) == LOW) {
        log_message("Emitters: ON");
        digitalWriteFast(EMITTER, HIGH);
    }
}
void emitters_off() {
    if (digitalRead(EMITTER) == HIGH) {
        log_message("Emitters: OFF");
        digitalWriteFast(EMITTER, LOW);
    }
}

void emitters_test() {
    if ((millis() / DEBUG_INTERVAL) % 2) {
        emitters_on();
        return;
    }

    emitters_off();
}

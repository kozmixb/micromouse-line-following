#include <Arduino.h>
#include <digitalWriteFast.h>

#include "config.h"

static bool enabled = false;

void setup_emitters() {
    pinMode(EMITTER, OUTPUT);
    digitalWriteFast(EMITTER, LOW);
}

void emitters_on() {
    if (digitalRead(EMITTER) == LOW && enabled) {
        digitalWriteFast(EMITTER, HIGH);
    }
}
void emitters_off() {
    if (digitalRead(EMITTER) == HIGH && enabled) {
        digitalWriteFast(EMITTER, LOW);
    }
}

void emitters_enable() { enabled = true; }
void emitters_disable() {
    emitters_off();
    enabled = false;
}

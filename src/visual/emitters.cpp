#include <Arduino.h>
#include <digitalWriteFast.h>

#include "config.h"

void setup_emitters() {
    pinMode(EMITTER, OUTPUT);
    digitalWriteFast(EMITTER, LOW);
}

void emitters_on() {
    if (digitalRead(EMITTER) == LOW) {
        digitalWriteFast(EMITTER, HIGH);
    }
}
void emitters_off() {
    if (digitalRead(EMITTER) == HIGH) {
        digitalWriteFast(EMITTER, LOW);
    }
}

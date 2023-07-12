#include <Arduino.h>

#include "config.h"
#include "lib/digitalWriteFast.h"

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

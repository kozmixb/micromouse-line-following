#include <Arduino.h>
#include <digitalWriteFast.h>

#include "config.h"
#include "debug.h"

void enable_indicators() {
    pinMode(LED_RIGHT, OUTPUT);
    pinMode(LED_LEFT, OUTPUT);
    digitalWriteFast(LED_RIGHT, LOW);
    digitalWriteFast(LED_LEFT, LOW);
}

void indicator_right() {
    digitalWriteFast(LED_RIGHT, HIGH);
    digitalWriteFast(LED_LEFT, LOW);
}

void indicator_left() {
    digitalWriteFast(LED_LEFT, HIGH);
    digitalWriteFast(LED_RIGHT, LOW);
}

void indicators_off() {
    digitalWriteFast(LED_LEFT, LOW);
    digitalWriteFast(LED_RIGHT, LOW);
}

void indicators_test() {
    if ((millis() / 200 / 2) % 2) {
        if (digitalRead(LED_LEFT) == LOW) {
            add_message(String("active_indicator"), String("LEFT"));
        }

        indicator_left();
        return;
    }

    if (digitalRead(LED_RIGHT) == LOW) {
        add_message(String("active_indicator"), String("RIGHT"));
    }

    indicator_right();
}

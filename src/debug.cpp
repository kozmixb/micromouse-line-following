#include <Arduino.h>

#include "config.h"
#include "data/item.h"

static bool enabled = false;
static byte length = 0;
static Item dictionary[20];
static unsigned long last = 0;

void enable_debug() {
    Serial.begin(BAUDRATE);
    enabled = true;
}

void add_message(String key, String value) {
    if (enabled && length < 20) {
        bool updated = false;

        for (byte i = 0; i < length; i++) {
            if (dictionary[i].key() == key) {
                dictionary[i].set(key, value);
                updated = true;
            }
        }

        if (!updated) {
            dictionary[length].set(key, String(value));
            length++;
        }
    }
}

void add_message(String key, int value) { add_message(key, String(value)); }
void add_message(String key, float value) { add_message(key, String(value)); }

void print_message() {
    if (enabled && (millis() - last >= 500) && length > 0) {
        last = millis();
        Serial.print("{");

        for (byte i = 0; i < length; ++i) {
            if (dictionary[i].valid()) {
                Serial.print(dictionary[i].get());
                dictionary[i].empty();
            }

            if (i < (length - 1)) {
                Serial.print(",");
            }
        }

        Serial.println("}");
        length = 0;
    }
}

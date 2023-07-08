#include "config.h"
#include "debug.h"
#include "lib/digitalWriteFast.h"
#include <Arduino.h>

void setup_emitters()
{
    pinMode(EMITTER, OUTPUT);
    digitalWriteFast(EMITTER, LOW);
}

void emitters_test()
{
    if ((millis() / 300) % 2)
    {
        if (digitalRead(EMITTER) == LOW)
        {
            Serial.println("Emitters: ON");
        }

        digitalWriteFast(EMITTER, HIGH);

        return;
    }

    if (digitalRead(EMITTER) == HIGH)
    {
        Serial.println("Emitters: OFF");
    }

    digitalWriteFast(EMITTER, LOW);
}

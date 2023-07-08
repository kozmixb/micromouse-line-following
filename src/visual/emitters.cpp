#include "config.h"
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
        digitalWriteFast(EMITTER, HIGH);
        return;
    }

    digitalWriteFast(EMITTER, LOW);
}

#include "config.h"
#include "lib/digitalWriteFast.h"
#include <Arduino.h>

void setup_indicators()
{
    pinMode(LED_RIGHT, OUTPUT);
    pinMode(LED_LEFT, OUTPUT);
    digitalWriteFast(LED_RIGHT, LOW);
    digitalWriteFast(LED_LEFT, LOW);
}

void indicator_right()
{
    digitalWriteFast(LED_RIGHT, HIGH);
    digitalWriteFast(LED_LEFT, LOW);
}

void indicator_left()
{
    digitalWriteFast(LED_LEFT, HIGH);
    digitalWriteFast(LED_RIGHT, LOW);
}

void indicators_test()
{
    if ((millis() / 1000) % 2)
    {
        indicator_left();
        return;
    }

    indicator_right();
}

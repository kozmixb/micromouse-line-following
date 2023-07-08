#include "config.h"
#include <Arduino.h>

bool enabled = false;

void enable_debug()
{
    Serial.begin(BAUDRATE);
    enabled = true;
}

void log_message(const String &message)
{
    if (enabled)
    {
        Serial.println(message);
    }
}

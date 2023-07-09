#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

const int DEBUG_INTERVAL = 400;

void enable_debug();
void log_message(const String &message);
void log_new_line();

#endif

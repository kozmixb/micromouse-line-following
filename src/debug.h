#ifndef DEBUG_H
#define DEBUG_H

void enable_debug();
void add_message(String key, String value);
void add_message(String key, int value);
void add_message(String key, float value);
void print_message();

#endif

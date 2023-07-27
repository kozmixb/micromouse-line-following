#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

class Item {
    String _key;
    String _value;
    bool _empty = true;

   public:
    Item() : _key(String()), _value(String()) {}

    void set(String key, String value) {
        _key = key;
        _value = value;
        _empty = false;
    }

    String key() { return _key; }

    String get() { return "\"" + _key + "\":" + _value; }

    void empty() {
        _key = String();
        _value = String();
        _empty = true;
    }

    bool valid() { return !_empty; }
};

void enable_debug();
void add_message(String key, String value);
void add_message(String key, int value);
void add_message(String key, float value);
void add_message(String key, byte value);
void print_message();

#endif

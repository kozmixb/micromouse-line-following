#ifndef ITEM_H
#define ITEM_H

#include <Arduino.h>

class Item {
    String _key;
    String _value;
    bool _empty = true;

   public:
    Item();
    void set(String key, String value);
    String key();
    String get();
    void empty();
    bool valid();
};

#endif

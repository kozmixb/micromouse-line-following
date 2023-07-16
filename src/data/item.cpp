#include "item.h"

Item::Item() : _key(String()), _value(String()) {}
void Item::set(String key, String value) {
    _key = key;
    _value = value;
    _empty = false;
}

void Item::empty() {
    _key = String();
    _value = String();
};

bool Item::valid() { return !_empty; };

String Item::key() { return _key; }

String Item::get() { return "\"" + _key + "\":" + _value; }

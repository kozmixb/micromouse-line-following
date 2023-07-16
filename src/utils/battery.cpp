#include "config.h"
#include "debug.h"

static float voltage = 0.0;
static float scale = 0.0;

void update_battery_voltage(float reading) {
    voltage = BATTERY_MULTIPLIER * reading;
    scale = 255.0 / voltage;
}

float read_battery_voltage() { return voltage; }

float read_battery_scale() { return scale; }

void log_battery() {
    add_message(String("battery_voltage"), String(voltage));
    add_message(String("battery_scale"), String(scale));
}

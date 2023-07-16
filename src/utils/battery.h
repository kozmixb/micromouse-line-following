#ifndef BATTERY_H
#define BATTERY_H

void update_battery_voltage(float reading);

float read_battery_voltage();
float read_battery_scale();
void log_battery();

#endif

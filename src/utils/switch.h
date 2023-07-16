#ifndef SWITCH_H
#define SWITCH_H

void update_switch_status(int adc);

void log_switch();

bool button_pressed();

void wait_for_button_release();

byte get_profile_version();

#endif

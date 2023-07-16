#include <Arduino.h>

#include "lib/adc.h"

void enable_timer_interrupt() {
    bitClear(TCCR2A, WGM20);
    bitSet(TCCR2A, WGM21);
    bitClear(TCCR2B, WGM22);
    // set divisor to 128 => 125kHz
    bitSet(TCCR2B, CS22);
    bitClear(TCCR2B, CS21);
    bitSet(TCCR2B, CS20);
    OCR2A = 249;  // (16000000/128/500)-1 => 500Hz
    bitSet(TIMSK2, OCIE2A);
}

void disable_timer_interrupt() { bitClear(TIMSK2, OCIE2A); }

ISR(TIMER2_COMPA_vect, ISR_NOBLOCK) {
    update_sensors();
    update_switch();
    update_battery();
    start_sensor_cycle();
}

#include <Arduino.h>

#include "config.h"
#include "debug.h"
#include "lib/adc.h"
#include "motors.h"
#include "utils/indicator.h"
#include "visual/emitters.h"
#include "visual/sensors.h"

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    enable_debug();
    setup_motors();
    setup_indicators();
    setup_emitters();
    setup_adc();

    // start interrupt
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

void loop() {
    Sensors::instance().enable();
    Sensors::instance().test();
    log_new_line();
}

ISR(TIMER2_COMPA_vect, ISR_NOBLOCK) {
    update_sensors();
    start_sensor_cycle();
}

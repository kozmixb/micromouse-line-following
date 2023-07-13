#include <Arduino.h>
#include <digitalWriteFast.h>
#include <wiring_private.h>

#include "config.h"
#include "visual/emitters.h"
#include "visual/sensors.h"

static volatile int adc[4];
static uint8_t sensor_phase = 0;
static const uint8_t ADC_REF = DEFAULT;

enum {
    EMITTERS_OFF,
    DARK_RIGHT,
    DARK_FRONT_RIGHT,
    DARK_FRONT_LEFT,
    DARK_LEFT,
    EMITTERS_ON,
    BRIGHT_RIGHT,
    BRIGHT_FRONT_RIGHT,
    BRIGHT_FRONT_LEFT,
    BRIGHT_LEFT,
};

void setup_adc() {
    bitSet(ADCSRA, ADPS2);
    bitClear(ADCSRA, ADPS1);
    bitSet(ADCSRA, ADPS0);
}

static void start_adc(uint8_t pin) {
    if (pin >= 14) pin -= 14;
    // allow for channel or pin numbers
    // set the analog reference (high two bits of ADMUX) and select
    // the channel (low 4 bits).  Result is right-adjusted
    ADMUX = (ADC_REF << 6) | (pin & 0x07);
    // start the conversion
    sbi(ADCSRA, ADSC);
}

static int get_adc_result() {
    // ADSC is cleared when the conversion finishes
    // while (bit_is_set(ADCSRA, ADSC));

    // we have to read ADCL first; doing so locks both ADCL
    // and ADCH until ADCH is read.  reading ADCL second would
    // cause the results of each conversion to be discarded,
    // as ADCL and ADCH would be locked when it completed.
    uint8_t low = ADCL;
    uint8_t high = ADCH;

    // combine the two bytes
    return (high << 8) | low;
}

void update_sensors() {
    Sensors::instance().right().update(adc[0]);
    Sensors::instance().front_right().update(adc[1]);
    Sensors::instance().front_left().update(adc[2]);
    Sensors::instance().left().update(adc[3]);
}

void start_sensor_cycle() {
    emitters_off();
    sensor_phase = 0;
    bitSet(ADCSRA, ADIE);  // enable the ADC interrupt
    start_adc(0);          // begin a conversion to get things started
}

static void stop_sensor_cycle() { bitClear(ADCSRA, ADIE); }

ISR(ADC_vect) {
    switch (sensor_phase) {
        case EMITTERS_OFF:
            start_adc(Sensors::instance().right().pin());
            break;
        case DARK_RIGHT:
            adc[0] = get_adc_result();
            start_adc(Sensors::instance().front_right().pin());
            break;
        case DARK_FRONT_RIGHT:
            adc[1] = get_adc_result();
            start_adc(Sensors::instance().front_left().pin());
            break;
        case DARK_FRONT_LEFT:
            adc[2] = get_adc_result();
            start_adc(Sensors::instance().left().pin());
            break;
        case DARK_LEFT:
            adc[3] = get_adc_result();
            emitters_on();
            start_adc(0);
            break;
        case EMITTERS_ON:
            start_adc(Sensors::instance().right().pin());
            break;
        case BRIGHT_RIGHT:
            adc[0] = adc[0] - get_adc_result();
            start_adc(Sensors::instance().front_right().pin());
            break;
        case BRIGHT_FRONT_RIGHT:
            adc[1] = adc[1] - get_adc_result();
            start_adc(Sensors::instance().front_left().pin());
            break;
        case BRIGHT_FRONT_LEFT:
            adc[2] = adc[2] - get_adc_result();
            start_adc(Sensors::instance().left().pin());
            break;
        case BRIGHT_LEFT:
            adc[3] = adc[3] - get_adc_result();
            emitters_off();
            stop_sensor_cycle();
            break;
    }

    sensor_phase++;
}

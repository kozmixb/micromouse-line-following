#ifndef ADC_H
#define ADC_H

void setup_adc();

void start_sensor_cycle();

static void start_adc(uint8_t pin);

static int get_adc_result();

#endif

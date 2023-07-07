#include "motors.h"
#include "config.h"
#include <Arduino.h>

byte button_state = 0;
int pwm = 0;

int state = 0;

void setup()
{
  Serial.begin(BAUDRATE);

  pinMode(USER_IO, OUTPUT);
  pinMode(EMITTER_A, OUTPUT);
  pinMode(EMITTER_B, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  setup_motors();
  Serial.println(F("RDY"));
}

void loop()
{
  pwm = state ? pwm + 1 : pwm - 1;
  set_left_motor_pwm(pwm);
  set_right_motor_pwm(pwm);

  Serial.println(String(pwm));
  if (pwm < -255 || pwm > 255)
  {
    state = !state;
  }

  delay(10);
}

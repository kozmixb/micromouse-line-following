#include "config.h"
#include "debug.h"
#include "motors.h"
#include "visual/emitters.h"
#include "visual/indicator.h"
#include <Arduino.h>

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  enable_debug();
  setup_motors();
  setup_indicators();
  setup_emitters();
}

void loop()
{
  indicators_test();
  emitters_test();
  // motors_test();
}

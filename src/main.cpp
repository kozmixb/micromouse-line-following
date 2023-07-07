#include "motors.h"
#include "reports.h"
#include "sensors.h"
#include "settings.h"
#include "stopwatch.h"
#include "systick.h"
#include "tests.h"
#include "ui.h"
#include "user.h"
#include <Arduino.h>

void setup()
{
  Serial.begin(BAUDRATE);
  load_settings_from_eeprom();
#if ALWAYS_USE_DEFAULT_SETTINGS
  // used during development to make sure compiled-in defaults are used
  restore_default_settings();
#endif
  setup_systick();
  pinMode(USER_IO, OUTPUT);
  pinMode(EMITTER_A, OUTPUT);
  pinMode(EMITTER_B, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  enable_sensors();
  setup_motors();
  setup_adc();
  delay(150);
  Serial.println();
  disable_sensors();
  if (button_pressed())
  {
    initialise_maze(emptyMaze);
    Serial.println(F("Clearing the Maze"));
    wait_for_button_release();
  }
  Serial.println(F("RDY"));
}

void loop()
{
  if (Serial.available())
  {
    cli_run();
  }
  if (button_pressed())
  {
    wait_for_button_release();
    int function = get_switches();
    if (function > 1)
    {
      wait_for_front_sensor(); // cover front sensor with hand to start
    }
    if (USER_MODE)
    {
      run_mouse(function);
    }
    else
    {
      run_test(function);
    }
  }
}

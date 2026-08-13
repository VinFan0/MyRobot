#include "bluetooth.h"
#include "motors.h"
#include "oled.h"
#include "servo.h"

bt_commands_t bt_readings;

// ============================================================
void setup() {
  Serial.begin(115200);
  delay(500); 
  oled_init();
  servo_init();
  bluetooth_init();
  motors_init();
}

// ============================================================
void loop() {
  oled_update(&bt_readings);
  servo_update(&bt_readings);
  bluetooth_update(&bt_readings);
  motors_update(&bt_readings);

  delay(100);
}

// ============================================================

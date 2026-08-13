#include "bluetooth.h"
#include "motors.h"
#include "oled.h"
#include "servo.h"

bt_commands_t bt_readings;

// ============================================================
void setup() {
  Serial.begin(115200);
  delay(500); 
  // oled_init();
  // servo_init();
  bluetooth_init();
  motors_init();
}

// ============================================================
void loop() {
  // oled_update();
  // servo_update();
  bluetooth_update(&bt_readings);
  motors_update(&bt_readings);

  BT.read(); // read BT data while not updating
  delay(100);
}

// ============================================================

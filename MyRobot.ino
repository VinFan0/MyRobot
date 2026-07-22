#include "oled.h"
#include "motors.h"
#include "servo.h"
#include "bluetooth.h"

// ============================================================
void setup() {
  Serial.begin(115200);
  delay(500); 
  oled_init();
  motors_init();
  servo_init();
  bluetooth_init();
}

// ============================================================
void loop() {
  oled_update();
  motors_update();
  servo_update();
  bluetooth_update();
}

// ============================================================

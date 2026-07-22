#include "bluetooth.h"

void bluetooth_init(void) {
  BT.begin("MyRobot");
}
void bluetooth_update(void) {
  if (BT.available()) {
    char cmd = BT.read();

    switch(cmd) {
      case 'F':
        Serial.println("Forward");
        break;
      case 'B':
        Serial.println("Backward");
        break;
      case 'L':
        Serial.println("Left");
        break;
      case 'R':
        Serial.println("Right");
        break;
      case 'G':
        Serial.println("Forward-Left");
        break;
      case 'H':
        Serial.println("Forward-Right");
        break;
      case 'I':
        Serial.println("Backward-Left");
        break;
      case 'J':
        Serial.println("Backward-Right");
        break;
      case 'S':
        Serial.println("Release");
    }
  }
}
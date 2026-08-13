#include "bluetooth.h"

void bluetooth_init(void) {
  BT.begin("MyRobot");
}

void bluetooth_update(bt_commands_t *bt_readings) {
  if (BT.available()) {
    
    char cmd = BT.read();
    
    bt_readings->command = cmd;
    
    /* Advanced BT Control
    char val_MSD = 0;
    char val_LSD = 0;
    float val = 0.0;

    if(cmd == 'F' || cmd == 'B' || cmd == 'L' || cmd == 'R') {
        val_MSD = BT.read();
        val_LSD = BT.read();
        val = (val_MSD - '0') * 10.0 + (val_LSD - '0');

      // Higher Throttle ----> Forward
      // Higher Yaw      ----> Right
      switch(cmd) {
        case 'F':
          bt_readings->throttle_val = val;
          break;
        case 'B':
          bt_readings->throttle_val = -val;
          break;
        case 'R':
          bt_readings->yaw_val = val;
          break;
        case 'L':
          bt_readings->yaw_val = -val;
          break;
      }

    }*/
    
    // bluetooth_print(bt_readings);
    BT.read();
  }

  BT.read(); // read BT data while not updating

}

void bluetooth_print(bt_commands_t *bt_readings) {
  Serial.print("Command: ");
  Serial.println(bt_readings->command);  
}

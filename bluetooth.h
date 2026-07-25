#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <BluetoothSerial.h>

/* 
* Positive Throttle ----> Forward
* Positive Yaw      ----> Right
*/
typedef struct bt_commands_s {
  float throttle_val = NULL;
  float yaw_val = NULL;
} bt_commands_t;

BluetoothSerial BT;

void bluetooth_init(void);
void bluetooth_update(bt_commands_t *bt_readings);
void bluetooth_print(bt_commands_t *bt_readings);

#endif // BLUETOOTH_H
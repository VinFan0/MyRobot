#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <BluetoothSerial.h>

BluetoothSerial BT;

void bluetooth_init(void);
void bluetooth_update(void);

#endif // BLUETOOTH_H
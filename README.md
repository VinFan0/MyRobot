# MyRobot
ESP32 Companion Robot

## Dependency Libraries
* BluetoothSerial
* SPI
* math
* Adafruit\_GFX
* Adafruit\_SSD1306
* ESP32Servo

## Control Modes
MyRobot is controlled via Bluetooth with the BT Car Controller-Arduino/ESP mobile application, available from the [Google Play Store](https://play.google.com/store/apps/details?id=com.giristuido.bluetooth.car.controller&hl=en_US). The application offers both *Basic* and *Advanced* control modes. 

Basic mode consists of 4 main buttons for control: Forward, Backward, Right, Left. Pressing a button, or a valid combination, sends a single, corresponding, character over bluetooth.

The MyRobot\_Basic\_Control branch will be built to allow the basic mode controls. 

Advanced mode provides two joy-stick style controls. One provides a spectrum for forward and reverse, while the other controls right and left. When a stick is moved to a location, 6 individual characters are sent in the following pattern.

- Throttle Character ('F' or 'B')
- Throttle value tens digit
- Throttle value ones digit
- Direction character ('R' or 'B')
- Direction value tens digit
- Direction value ones digit

As an example, if the throttle stick is set to forward with a magnitude of 50, and the direction stick is on Left with magnitude 10, the series of Bluetooth characters will be `F 5 0 L 1 0`.

The MyRobot\_Advanced\_Control branch will be built to allow the advanced mode controls.

## Hardware Requirements

MyRobot is built using perfboard and wires. I may design a custom PCB in the future if I feel the project would benefit, and if it's affordable for me.

### Microcontroller
I used a [DOIT ESP32 DevKit V1]() for the MyRobot project. This decision was driven primarily by how many pins would be required to connect each of the peripherals. The project is not incredibly intensive on storage, so no additional flash should be required.

### Motors
MyRobot utilizes 2 DC motors for drive control, and a servo motor for head movement.
- DC Motors
+ [RF-500TB-18280 Mini DC Motor](https://www.amazon.com/RF-500TB-18280-Electric-1-5V-5V-2700RPM-Diameter/dp/B09N2PPWCW?th=1)
+ 1.5V-5V, 2700RPM.
- Servo
+ [DFROBOT DS-S006L](https://www.dfrobot.com/product-2120.html)
+ 9g, 180&deg;

### User Interface
- [Digilent PMOD OLED Module](https://digilent.com/reference/pmod/pmodoled/start)
+ SSD1306 primary IC
+ 128x32 pixels
+ SPI
- LEDs
+ Three 3mm colored LEDs to provide status information

### Power Train
- [1S 2000mAh LiPo battery](https://www.amazon.com/Winfox-Rechargeable-Connector-Bluetooth-Portable/dp/B0GDQ7Q58F)
- [HiLetgo TP4056 LiPo Charger Module](https://www.amazon.com/dp/B07PKND8KG)
- TODO: Get 5V Boost Module

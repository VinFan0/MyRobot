#ifndef OLED_H
#define OLED_H
/* Digilent PMOD OLED (SSD1306, 128x32) — DoIT ESP32 DevKit V1
 * 
 * The PMOD OLED uses a 4-wire SPI interface.
 *
 * WIRING (PMOD J1 pin → ESP32 GPIO):
 * ┌──────────────┬─────────────────┬──────────────┐
 * │ PMOD Pin     │ Signal          │ ESP32 GPIO   │
 * ├──────────────┼─────────────────┼──────────────┤
 * │ Pin 1        │ CS  (Chip Sel.) │ GPIO 5       │
 * │ Pin 2        │ MOSI (SDO)      │ GPIO 23      │
 * │ Pin 3        │ DC  (Data/Cmd)  │ GPIO 22      │
 * │ Pin 4        │ RES (Reset)     │ GPIO 21      │
 * │ Pin 5        │ GND             │ GND          │
 * │ Pin 6        │ VCC (3.3V)      │ 3.3V         │
 * │ Pin 7        │ SCK (SCLK)      │ GPIO 18      │
 * └──────────────┴─────────────────┴──────────────┘
 *
 * Library: Adafruit SSD1306 + Adafruit GFX
 * Install via Arduino Library Manager:
 *   - "Adafruit SSD1306"
 *   - "Adafruit GFX Library"
 *   - "Adafruit BusIO"        (dependency, usually auto-installed)
 *
 * Board: "DOIT ESP32 DEVKIT V1" in Arduino IDE
 * (Tools → Board → ESP32 Arduino → DOIT ESP32 DEVKIT V1)
 */

#include <SPI.h>
#include <math.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------- Display dimensions ----------
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT  32   // PMOD OLED is 128×32
#define SCREEN_REFRESH 20   // # of ms per frame

// ---------- Eye Characteristics ----------
#define EYES_RAD        8
#define EYES_OVERLAP    2
#define EYES_SEPARATION (EYES_RAD >> 1)
#define EYES_X_START    (SCREEN_WIDTH >> 1)
#define EYES_X_MIN      ((EYES_RAD << 1) + (EYES_SEPARATION >> 1) + EYES_OVERLAP)
#define EYES_X_MAX      (SCREEN_WIDTH-((EYES_RAD << 1) + (EYES_SEPARATION >> 1) + EYES_OVERLAP))
#define EYES_Y_START    (SCREEN_HEIGHT >> 1)
#define EYES_Y_MIN      (EYES_RAD - EYES_OVERLAP)
#define EYES_Y_MAX      (SCREEN_HEIGHT-EYES_RAD + EYES_OVERLAP)

typedef enum {
  EYES_X_LEFT = -1,
  EYES_X_STOP = 0,
  EYES_X_RIGHT = 1
} eyes_x_dir;

typedef enum {
  EYES_Y_UP = -1,
  EYES_Y_STOP = 0,
  EYES_Y_DOWN = 1
} eyes_y_dir;

typedef struct oled_eyes_s{
  uint32_t x = EYES_X_MIN;
  uint32_t y = EYES_Y_MIN;
  eyes_x_dir x_dir = EYES_X_STOP;
  eyes_y_dir y_dir = EYES_Y_STOP;
} oled_eyes_t;

// ---------- SPI pin assignments ----------
#define OLED_CS   5    // Chip Select
#define OLED_MOSI 23    // SPI MOSI  (SDO on PMOD)
#define OLED_SCK  18    // SPI Clock
#define OLED_DC   22    // Data / Command select
#define OLED_RST  21    // Reset (active LOW)

// Create display object (hardware SPI)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC, OLED_RST, OLED_CS);

oled_eyes_t eyes = {EYES_X_START, EYES_Y_START, EYES_X_STOP, EYES_Y_STOP};
uint32_t oledLastStep = 0;
uint32_t eyes_static_time = SCREEN_REFRESH;

void oled_init(void);
void oled_update(void);

#endif // OLED_H
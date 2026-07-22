#include <SPI.h>
#include <math.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "oled.h"

void oled_init(void) {
  Serial.println("PMOD OLED init...");

  // Initialise SPI with custom pins before calling display.begin()
  SPI.begin(OLED_SCK, -1 /*MISO unused*/, OLED_MOSI, OLED_CS);

  // SSD1306_SWITCHCAPVCC = generate display voltage internally
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println("SSD1306 init failed — check wiring!");
    while (true);   // halt
  }

  display.clearDisplay();
  display.display();

  randomSeed(analogRead(0));
}
void oled_update(void) {
  if (millis() - oledLastStep > eyes_static_time) {
    eyes_static_time = SCREEN_REFRESH;
    oledLastStep = millis();
    display.clearDisplay();

    // Draw
    display.fillCircle(eyes.x - (EYES_SEPARATION + EYES_RAD), eyes.y, EYES_RAD, SSD1306_WHITE); // Left eye
    display.fillCircle(eyes.x + (EYES_SEPARATION + EYES_RAD), eyes.y, EYES_RAD, SSD1306_WHITE); // Right eye
    display.display();

    // Smooth bounce
    // ============================================================
    // eyes.x += eyes.x_dir;
    // eyes.y += eyes.y_dir;
    // if(eyes.x + eyes.x_dir < EYES_X_MIN) { // If moving into left edge
    //   eyes.x_dir = EYES_X_RIGHT;            // move right
    //   eyes_static_time = 1000;
    // } else if (eyes.x+eyes.x_dir > EYES_X_MAX) { // If moving into right edge
    //   eyes.x_dir = EYES_X_LEFT;                   // move left
    //   eyes_static_time = 1000;
    // }

    // if (eyes.y+eyes.y_dir < EYES_Y_MIN) {  // If moving into top edge
    //   eyes.y_dir = EYES_Y_DOWN;             // move down
    // } else if (eyes.y+eyes.y_dir > EYES_Y_MAX) { // If moving into bottom edge
    //   eyes.y_dir = EYES_Y_UP;
    // }
    // ============================================================

    // Random Jumps
    uint32_t rand = random(49);
    if(rand == 0) {
      eyes.x = random(EYES_X_MIN, EYES_X_MAX);
      eyes_static_time = 1000;
    } else if ((rand > 0) && (rand < 5)) {
      eyes.x = EYES_X_START;
      eyes_static_time = 1000;
    } else if (rand == 5) {
      // blink
      display.clearDisplay();
      display.drawLine(eyes.x - (EYES_SEPARATION + (EYES_RAD << 1)), eyes.y, eyes.x - (EYES_SEPARATION), eyes.y, SSD1306_WHITE);
      display.drawLine(eyes.x + (EYES_SEPARATION + (EYES_RAD << 1)), eyes.y, eyes.x + (EYES_SEPARATION), eyes.y, SSD1306_WHITE);
      display.display();
      eyes_static_time = 80;
    }
  }
}
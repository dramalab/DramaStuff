/*
 * Cap1188Demo: Demo-Code to work with the Adafruit Cap1188 breakout board
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 11.04.2015	 
 */
 
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>

// Reset Pin is used for I2C
#define CAP1188_RESET  8

Adafruit_CAP1188 cap = Adafruit_CAP1188(CAP1188_RESET);

void setup() {
  Serial.begin(9600);
  Serial.println("CAP1188 test!");

  if (!cap.begin()) {
    Serial.println("CAP1188 not found");
    while (1);
  }
  Serial.println("CAP1188 found!");
}

void loop() {
  uint8_t touched = cap.touched();

  if (touched == 0) {
    return;
  }
  
  for (uint8_t i=0; i<8; i++) {
    if (touched & (1 << i)) { // bit shift operations
      Serial.print("C"); Serial.print(i+1); Serial.print("\t");
    }
  }
  Serial.println();
  delay(50);
}


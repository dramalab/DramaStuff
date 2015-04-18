/*
 * DramaLab_LCD_HelloDramaLab: Displays a text message and 
 * the elapsed time since startup on a 16x2 character LCD.
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 18.04.2015   
 *
 * LCD --> Arduino
 * RS --> 12
 * E --> 11
 * D4 --> 5
 * D5 --> 4
 * D6 --> 3
 * D7 --> 2
 * RW pin to ground
 * V0 --> 10K Poti
 * K --> GND
 * A --> 5V
 * VSS --> GND
 * VDD --> 5V
 */
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello, DramaLab!");
}

void loop() {
  for(int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayLeft(); 
    delay(450);
  }

  for(int positionCounter = 0; positionCounter < 32; positionCounter++) {
    lcd.scrollDisplayRight(); 
    delay(450);
  }
  
 for(int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayLeft(); 
    delay(450);
  }

  delay(1000);
}

/* DramaLab_MMA8452Q: 
 * Arduino  --> MMA8452Q
 * 3.3V     --> 3.3V
 * GND      --> GND
 * A4 --> 330 Ohm --> SDA
 * A5 --> 330 Ohm --> SCL
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 14.03.2015
 */
#include <Wire.h>
#include <SFE_MMA8452Q.h>

MMA8452Q accel;

void setup()
{
  Serial.begin(9600);
  Serial.println("MMA8452Q Demo!");
  accel.init();
}

void loop()
{
  if (accel.available())
  {
    accel.read();
    printCalculatedAccels();
    printOrientation();
    Serial.println();
  }
  delay(500);
}

void printCalculatedAccels()
{ 
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
}

void printOrientation()
{
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}


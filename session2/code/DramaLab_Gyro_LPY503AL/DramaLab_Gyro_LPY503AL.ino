/* DramaLab_Gyro_LPY503AL: 
 * Measure dual axis motion (x and z) using the LPY503AL sensor 
 * sensor: https://www.sparkfun.com/products/9424
 *
 * Wiring: Sensor --> Arduino
 *            GND --> GND
 *           3.3V --> 3.3V
 *           X x1 --> A4
 *           Z x1 --> A5
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 12.04.2014
 *
 */

int xPin = A4;
int zPin = A5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valX = analogRead(xPin);
  int valZ = analogRead(zPin);
  Serial.print("x: ");
  Serial.print(valX);
  Serial.print(" z: ");
  Serial.println(valZ);
  delay(1000);
}

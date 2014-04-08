/* DramaLab_Joystick: 
 * Simple way to use the joystick, without an additional library
*
 * Wiring: Sensor --> Arduino
 *            GND --> GND
 *            +5V --> 5V
 *            VRx --> A4
 *            VRy --> A5
 *             SW --> nothing
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 12.04.2014
 *
 */

int xPin = 4;
int yPin = 5;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("X: ");
  Serial.print(analogRead(xPin));
  Serial.print("  Y: ");
  Serial.print(analogRead(yPin));
  delay(100);
}

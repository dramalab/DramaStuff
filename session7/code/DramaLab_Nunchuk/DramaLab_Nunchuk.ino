/* DramaLab_Nunchuk: 
 * Use a Nintendo Nunchuk controller with the Arduino using the
 * ArduinoNunchuk library.
 * 
 * Wiring: Sensor --> Arduino
 *          -   --> GND
 *          +  --> 3,3V
 *          d  --> A4
 *          c   --> A5
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 13.12.2014
 *
 */

#include <Wire.h>
#include <ArduinoNunchuk.h>

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup()
{
  Serial.begin(9600);
  nunchuk.init();
}

void loop()
{
  nunchuk.update();
  Serial.print(nunchuk.analogX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.cButton, DEC);
  delay(1000);
}


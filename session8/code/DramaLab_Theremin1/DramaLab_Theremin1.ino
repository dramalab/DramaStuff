/* DramaLab_Theremin1: 
 * 
 * Wiring: Sensor --> Arduino
 *          VCC   --> 5V
 *          Trig  --> D2
 *          Echo  --> D3
 *          GND   --> GND
 *
 * Speaker: D1 and GND
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 14.03.2015
 */


#include "Ultrasonic.h"
Ultrasonic ultrasonic(2,3);

void setup() {
  Serial.begin(9600);
}

void loop()
{
  int sensorReading = ultrasonic.Ranging(CM);
  Serial.print(sensorReading); Serial.println("cm");
  float frequency = map(sensorReading, 5, 60, 10, 200);
  tone(1, frequency, 10);
}

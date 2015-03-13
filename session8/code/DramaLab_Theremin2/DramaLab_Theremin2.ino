/* DramaLab_Theremin2: 
 * 
 * Wiring: Sensor1 --> Arduino
 *          VCC   --> 5V
 *          Trig  --> D2
 *          Echo  --> D3
 *          GND   --> GND
 * Sensor2 --> Arduino
 *          VCC   --> 5V
 *          Trig  --> D4
 *          Echo  --> D5
 *          GND   --> GND
 *
 * Speaker: D1 and GND
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 14.03.2015
 */


#include "Ultrasonic.h"
Ultrasonic pitch(2,3);
Ultrasonic duration(4,5);

void setup() {
  Serial.begin(9600);
}

void loop()
{
  int sensorReadingPitch = pitch.Ranging(CM);
  int sensorReadingDuration = duration.Ranging(CM);
  float frequency = map(sensorReadingPitch, 5, 60, 10, 200);
  float duration = map(sensorReadingDuration, 5, 60, 10, 500);
  tone(1, (int)frequency, (int)duration);
  delay((int)duration+30);
}

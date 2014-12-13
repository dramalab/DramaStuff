/* DramaLab_Ultrasonic: 
 * Measure distances with a HC_SR04 ultrasonic sensor and display 
 * them on the Serial Monitor.
 * 
 * Wiring: Sensor --> Arduino
 *          VCC   --> 5V
 *          Trig  --> D2
 *          Echo  --> D3
 *          GND   --> GND
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 12.04.2014
 *
 */

#include <SoftwareSerial.h>
#include "Ultrasonic.h"
Ultrasonic ultrasonic(3);

void setup() {
  Serial.begin(9600);
}

void loop()
{
  ultrasonic.MeasureInCentimeters();
  Serial.print(ultrasonic.RangeInCentimeters);
  Serial.println("cm");
    
  delay(1000);
}





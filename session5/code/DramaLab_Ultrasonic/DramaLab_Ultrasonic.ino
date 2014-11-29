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
 * Max Stricker, 29.11.2014
 *
 */


#include "Ultrasonic.h"
Ultrasonic ultrasonic(2,3);

void setup() {
  Serial.begin(9600);
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // change to INC for inch insteat of cm
  Serial.println("cm");
    
  delay(1000);
}





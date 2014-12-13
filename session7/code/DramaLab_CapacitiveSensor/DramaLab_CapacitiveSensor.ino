/* DramaLab_CapacitiveSensor: 
 * Example to create a capacitive sensor (touch-sensitive input)
 * without additionaly sensors or hardware.
 *
 * Wiring: Arduino Pin 2 ----- 10M Resistor ----- Arduino Pin 4
 *              |
 *              |
 *              | cable or aluminium foil as touch sensor
 *
 * It basically calculates the time that is needed for Pin2 to change from LOW to HIGH
 * state; this time is influenced by the human body capacitance (= ability to store electric charge).
 *
 * more information here: http://www.capacitive-sensing.com/
 *
 *
 * You should see an output like this:
 * 0
 * 0
 * 30
 * 779
 * 1033
 * 155
 * 40
 * 31
 * high values indicate a sensed touch
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 13.12.2014
 *
 */

#include <CapacitiveSensor.h>


CapacitiveSensor   capSensor = CapacitiveSensor(4,2);

void setup(){
   Serial.begin(9600);
}

void loop(){
    long sensedValue =  capSensor.capacitiveSensor(30);
    Serial.println(sensedValue);

    delay(1000);
}

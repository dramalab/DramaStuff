/* ServoSweep: 
 * Simple way to use a Servo, move it left and right to about 180 degrees
*
 * Wiring: Servo --> Arduino
 *            GND --> GND
 *            +5V --> 5V
 *            Signal --> D9 (PWM Pin)
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 25.11.2014
 *
 */

#include <Servo.h> 
 
Servo myservo; // servo object
int pos = 0; // servo position 
 
void setup() 
{ 
  myservo.attach(9); // servo attached on pin 9
} 
 
void loop() 
{ 
  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {
    myservo.write(pos); // tell servo to go to position in variable 'pos' 
    delay(5); // waits 5ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)
  {                                
    myservo.write(pos);
    delay(5);
  } 
} 


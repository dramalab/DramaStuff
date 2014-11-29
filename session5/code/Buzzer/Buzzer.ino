/* Buzzer: 
 * Play random tones for one second
*
 * Wiring: Buzzer --> Arduino
 *       S (right) --> D2
 *         VCC --> 5V
 *      - (right) --> GND
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 29.11.2014
 */

int buzzerPin =  2;
void setup(){         
  pinMode(buzzerPin, OUTPUT);      
} 

void loop(){ 
  int frequency = random(100,4000);
  tone(1000, frequency);
  delay(2000);    
}

void tone(long duration, int freq){
  duration *= 1000;
  int period = (1.0 / freq) * 1000000;
  long elapsed_time = 0;
  while (elapsed_time < duration){
    digitalWrite(buzzerPin,HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(period / 2);
    elapsed_time += (period);
  }
}

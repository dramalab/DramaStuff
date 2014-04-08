/* DramaLab_LDR: 
 * Measure light intensity using a voltage divider with a 
 * light dependent resistor (photoresistor).
 * 
 * Wiring: 5V ---> R1 | ---> LDR ---> GND
 *                    |
 *            Arduino A1
 *
 * will result in high values for dark situations, to change behaviour 
 * exchange positions of R1 and LDR
 *
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 12.04.2014
 *
 */

int sensorPin = A1;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(500);
}

/* DramaLab_Serial: 
 * Reads data from the serial monitor and writes it back to it.
 *
 * more information here: http://arduino.cc/en/reference/serial
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 12.04.2014
 *
 */

void setup() {
  Serial.begin(9600);
  Serial.print("Arduino is ");
  Serial.print("currently executing ");
  Serial.println("the setup method.");
}

void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();
    Serial.print("Arduino received ");
    Serial.println(incomingChar);
  }
}

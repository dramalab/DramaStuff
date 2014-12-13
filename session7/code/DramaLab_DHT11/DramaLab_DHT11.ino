/* DramaLab_DHT11: 
 * Measure temperature and humidity values using a DHT11 sensor
*
 * Wiring: Sensor --> Arduino
 *       S (left) --> D2
 *         middle --> 5V
 *      - (right) --> GND
 *  10k resistor between D2 and 5V
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 12.04.2014
 *
 */

#include "DHT.h"

int sensorPin = 2;

DHT dht(sensorPin, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if values are valid,
  //if they are NaN (not a number) then something went wrong
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" C");
  }
  delay(2000);
}

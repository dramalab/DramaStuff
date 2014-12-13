/* PIRSensor: 
 * Use a PIR (= passive infrared) sensor to detect motion
 * 
 * Wiring: Sensor --> Arduino
 *          left   --> GND
 *          middle  --> 5V
 *          right  --> D2
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 13.12.2014
 *
 */
 
//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;        

int pirPin = 2;    //the digital pin connected to the PIR sensor's output
int ledPin = 13;

void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);

  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }

void loop(){
  if(digitalRead(pirPin) == HIGH){
     digitalWrite(ledPin, HIGH);
   }

   if(digitalRead(pirPin) == LOW){       
     digitalWrite(ledPin, LOW);
   }  
}

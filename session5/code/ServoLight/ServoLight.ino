#include <Servo.h> 
 
Servo myservo;
int sensorPin1 = A8;
int sensorPin2 = A9;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  int sensorValue1 = analogRead(sensorPin1);
  int sensorValue2 = analogRead(sensorPin2);
  Serial.println(sensorValue1);
  Serial.println(sensorValue2);
  Serial.println("========");
  if(sensorValue1>sensorValue2){
    myservo.write(45);
    delay(300);
  }else{
    myservo.write(120);
    delay(300);
  }
  delay(500);
}


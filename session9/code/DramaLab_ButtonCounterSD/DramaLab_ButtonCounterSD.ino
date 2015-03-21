#include <SD.h>

int PIN_MOSI = 11;
int PIN_MISO = 12;
int PIN_CLK = 13;
int PIN_CS = 4;

void setup(){
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(PIN_CS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void loop(){
  if(digitalRead(2)==HIGH){//checking if the button is pressed
    //button is pressed
    digitalWrite(3,HIGH); //switch on LED on Pin 3
    
    //write to sd card
    File buttonCounter = SD.open("button.txt",FILE_WRITE);
    if(buttonCounter){
      buttonCounter.print("Button has been pressed...  ");
      buttonCounter.println(millis());
      buttonCounter.close();
    }
  }else{
    //button is not pressed
    digitalWrite(3,LOW); //switch off LED on Pin 3
  }

}

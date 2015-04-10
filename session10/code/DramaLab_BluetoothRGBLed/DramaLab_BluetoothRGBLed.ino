/*
 * DramaLab_BluetoothRGBLed: Control Led on Pin 13 using bluetooth, send H for HIGH, L for LOW
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 11.04.2015	 
 */
int ledpinR = 13;
int ledpinG = 12;
int ledpinB = 11;

void setup() 
{
   Serial.begin(9600);
   pinMode(ledpinR,OUTPUT);
   pinMode(ledpinG,OUTPUT);
   pinMode(ledpinB,OUTPUT);
   Serial.println("DramaLab_BluetoothRGBLed ready!");
}

void loop()
{
  if(Serial.available()){
    String on = Serial.readStringUntil('|');
    String red = Serial.readStringUntil('|');
    String green = Serial.readStringUntil('|');
    String blue = Serial.readStringUntil('\n');
    int onVal = on.toInt();
    int redVal = red.toInt();
    int greenVal = green.toInt();
    int blueVal = blue.toInt();
    Serial.println(on);
    Serial.println(redVal);
    Serial.println(greenVal);
    Serial.println(blueVal);
   
    //TODO set the right color to the RGB Led or switch it off if onVal=0 
  }
  
  delay(100);
}

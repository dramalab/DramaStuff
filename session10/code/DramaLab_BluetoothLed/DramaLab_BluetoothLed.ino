/*
 * DramaLab_BluetoothLed: Control Led on Pin 13 using bluetooth, send H for HIGH, L for LOW
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 11.04.2015	 
 */
char val;
int ledpin = 13;

void setup() 
{
   Serial.begin(9600);
   pinMode(ledpin,OUTPUT);
}

void loop()
{
  if(Serial.available()){
    val = Serial.read();
  }
  if(val=='H'){
    digitalWrite(ledpin, HIGH);
  }else if(val=='L'){ 
    digitalWrite(ledpin, LOW);
  }
  delay(100);
}

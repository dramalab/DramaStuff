/* DramaLab_ToneProcessing: 
 * 
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 14.03.2015
 */
void setup() {
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0){
    int frequency = Serial.parseInt();
    tone(8, frequency, 200);
  }
}

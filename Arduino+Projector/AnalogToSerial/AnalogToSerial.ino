
void setup() {
  Serial.begin(9600);
  Serial.println("ready");
}

void loop() {
  Serial.println(analogRead(A0));
  delay(500);
}

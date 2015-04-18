/*
 * DramaLab_RemoteSender
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 18.04.2015   
 */
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

RF24 radio(8,7);

void setup(void) {
 
  Serial.begin(57600);
  randomSeed(analogRead(0));
  printf_begin();
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(70);
  radio.enableDynamicPayloads();
  radio.setRetries(15,1);
  radio.setCRCLength(RF24_CRC_16);
  radio.openWritingPipe(0xDEDEDEDEE9LL);
  radio.setAutoAck(true);
  radio.powerUp();
  radio.printDetails();

  Serial.println();
  Serial.println("DramaLab RemoteDataSender ready!");    
  delay(500);
}

void loop(void) {
  uint16_t sensorValue = random(140);
  Serial.println(sensorValue);
  bool ok = radio.write(&sensorValue,sizeof(uint16_t));
  Serial.println("done");
  if(!ok) Serial.println("transmit failed");
  delay(1000);
}




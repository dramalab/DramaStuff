/*
 * DramaLab_RemoteReceiver
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
  printf_begin();
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(70);
  radio.enableDynamicPayloads();
  radio.setRetries(15,15);
  radio.setCRCLength(RF24_CRC_16);
  radio.openReadingPipe(1, 0xDEDEDEDEE9LL);
  radio.startListening();
  radio.setAutoAck(true);
  radio.powerUp();
  radio.printDetails();
  
  Serial.println();
  Serial.println("DramaLab RemoteReceiver ready!");    
  delay(500);
}

void loop(void) {
  if (radio.available()){
    uint16_t data;
    radio.read(&data, sizeof(uint16_t));
    Serial.println(data);
  }
  delay(1000);
}

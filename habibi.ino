#include "LoRa_E32.h"
#include <SoftwareSerial.h>

SoftwareSerial lora(8, 9);
LoRa_E32 e32ttl(&lora);

void setup() {
  Serial.begin(9600); 
  e32ttl.begin();
}

void loop() {
  if (Serial.available()) {
      String input = Serial.readString();
      e32ttl.sendFixedMessage(0, 1, 38, input);
      Serial.println("Message Sent!");
  }
}

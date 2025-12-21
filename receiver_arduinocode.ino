#include "LoRa_E32.h"
#include <SoftwareSerial.h>

SoftwareSerial lora(8, 9);
LoRa_E32 e32ttl(&lora);

void setup() {
  Serial.begin(9600); 

  e32ttl.begin();
}

void loop() {
  if (e32ttl.available()) {
    ResponseContainer rc = e32ttl.receiveMessage();
    if (rc.status.code != 1){
      rc.status.getResponseDescription();
    } else {
      Serial.println(rc.data);
    }
  }
}

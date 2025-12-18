#include "LoRa_E32.h"
#include <SoftwareSerial.h>

SoftwareSerial lora(8, 9);
LoRa_E32 e32ttl(&lora);

void setup() {
  Serial.begin(9600); 

  e32ttl.begin();

  ResponseStatus rs = e32ttl.sendMessage("Hello, LoRa!");

  Serial.println(rs.getResponseDescription());

  Serial.println("READY");
}

void loop() {
    // If something available
  if (e32ttl.available()>1) {
      // read the String message
    ResponseContainer rc = e32ttl.receiveMessage();
    // Is something goes wrong print error
    if (rc.status.code!=1){
        Serial.println(rc.status.getResponseDescription());
    }else{
        // Print the data received
        Serial.println(rc.data);
    }
  }
  if (Serial.available()) {
      String input = Serial.readString();
      e32ttl.sendMessage(input);
      Serial.println("Message Sent!");
  }
}

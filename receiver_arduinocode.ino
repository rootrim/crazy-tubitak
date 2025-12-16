// Literal CODE
// What do you think habibi

#include <SoftwareSerial.h>

SoftwareSerial lora(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);      
  lora.begin(9600);        
}

void loop() {
  if (lora.available()) {
    Serial.write(lora.read());
  }

  if (Serial.available()) {
    lora.write(Serial.read());
  }
}

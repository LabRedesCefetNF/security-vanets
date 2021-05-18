#include "asciiHex.h"
#include "securino.h"
#include "Javino.h"

// RECIEVER

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Javino j;
  Securino s;
  j.enableRF(12,11);
  if(j.availableMsgRF()){
    Serial.println(j.getMsg());
  }
}

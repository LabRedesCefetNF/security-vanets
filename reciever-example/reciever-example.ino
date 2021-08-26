#include "Javino.h"
void setup() {
  Serial.begin(9600);
  enableRF(12,11);
  setKey("0000000000000000");
}

void loop() {

  if(receiver()){
    Serial.println(getPlainTxt());
  }

}

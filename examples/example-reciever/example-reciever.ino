#include "Javino.h" /*import library from https://github.com/LabRedesCefetNF/security-vanets/releases/download/1.0.0/securityvanets.zip*/
void setup() {
  Serial.begin(9600);
  enableRF(12,11);
  setKey("0123456789abcdef");
}

void loop() {

  if(receiver()){
    Serial.println(getPlainTxt());
  }

}

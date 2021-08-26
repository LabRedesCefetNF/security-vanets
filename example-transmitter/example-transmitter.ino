void setup(){
  Serial.begin(9600);
  enableRF(12,11);
  setKey("0000000000000011");
}

void loop() {
  trasmiter("0123456789abcdef");
  delay(1000);
}

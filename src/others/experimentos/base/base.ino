void setup(){
  Serial.begin(9600);
  enableRF(12,11);
  setKey("0123456789abcdef");
}

void loop() {
  String cmd="command=go ahead";
  Serial.print("Send:");
  Serial.println(cmd);
  trasmiter(cmd);
  delay(5000);
  
  cmd="command=stop now";
  Serial.print("Send:");
  Serial.println(cmd);
  trasmiter(cmd);
  delay(5000);
}

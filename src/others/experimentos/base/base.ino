void setup(){
  Serial.begin(9600);
  enableRF(12,11);
  setKey("0123456789abcdef");
}

void loop() {
  String cmd="command=go ahead";
  comm(cmd);
  delay(1000);
  cmd="command=stop now";
  comm(cmd);
  delay(1000);
}

void comm(String str){
  Serial.print("Send:");
  Serial.print(str);
  trasmiter(str);
  Serial.println("   [OK]");
}

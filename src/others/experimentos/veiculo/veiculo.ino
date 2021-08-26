void setup() {
  Serial.begin(9600);
  enableRF(12,11);
  setKey("0123456789abcdef");
}

void loop() {
  if(receiver()){
    Serial.print("Rcpt:");
    Serial.print(getPlainTxt());
    action(getPlainTxt());
  }
}

void action(String act){
  if(act=="command=go ahead"){
    Serial.println("  (Start [OK])");
  }else if(act=="command=stop now"){
    Serial.println("  (Stop  [OK])");
  }else{
    Serial.println(" (CMD [ERROR])");
  }
}

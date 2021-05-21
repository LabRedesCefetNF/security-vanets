#include "securino.h"
#include "Javino.h"
#include "Konverter.h"
Javino javino;
Securino securino;
Konverter konverter;

String strMsg;
byte * byteMsg;

void setup() {
  Serial.begin(9600);
    javino.enableRF(12,11);
}

void loop() {
  if(javino.availableMsgRF()){
    strMsg = javino.getMsg();
    Serial.println(strMsg);
    konverter.strB64toByte(strMsg,byteMsg);
    Serial.print("CIFRADA: ");
    exibe(byteMsg,16);
  }
  
}



/*****Auxiliar *****/
void exibe(byte * in, int x){
  for(int i=0; i < x; i++){  
      Serial.print(in[i],HEX);
      Serial.print(" ");  
   }
   Serial.println();  
}

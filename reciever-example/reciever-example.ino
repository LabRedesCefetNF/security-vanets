#include "securino.h"
#include "Javino.h"
#include "Konverter.h"
Javino javino;
Securino securino;
Konverter konverter;

String strMsg;
//byte * byteMsg;
byte byteMsg[32];

void setup() {
  Serial.begin(9600);
    javino.enableRF(12,11);
}

void loop() {
  if(javino.availableMsgRF()){
    strMsg = javino.getMsg();
    Serial.print("Recebi: ");
    konverter.strB64toByte(strMsg,byteMsg);
    Serial.print("CIFRADA: ");
    exibe(byteMsg,32);
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

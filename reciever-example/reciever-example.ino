#include "securino.h"
#include "Javino.h"
#include "Konverter.h"
Javino javino;
Securino securino;
Konverter konverter;

String  strB64;
byte    byteMsgCifrada[32];
byte *  byteMsg;
byte    byteChave[16]  =  {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};  
String  strClaro;

void setup() {
  Serial.begin(9600);
    javino.enableRF(12,11);
}

void loop() {
  if(javino.availableMsgRF()){
    strB64 = javino.getMsg();
    Serial.print("Recebi: ");
    Serial.println(strB64);
    konverter.strB64toByte(strB64,byteMsgCifrada);
    Serial.print("CIFRADA: ");
    exibe(byteMsgCifrada,32);
     //Cifrando Mensagem com AES 128 CBC
    byteMsg = securino.decript("aes-128-cbc", byteMsgCifrada, byteChave);
    Serial.print("EM Claro: ");
    exibe(byteMsg,16);
    strClaro = konverter.byteArray2String(byteMsg);
    Serial.println(strClaro);
    
    
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

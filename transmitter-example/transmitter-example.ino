#include "securino.h"
#include "Javino.h"
#include "Konverter.h"

Javino javino;
Securino securino;
Konverter konverter;

  byte * byteMsg;
  byte * byteMsgCifrada;
  byte byteChave[16]  =  {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};  


void setup() {
  Serial.begin(9600);
  javino.enableRF(12,11);
}

void loop() {
  /*Mensagem a ser enviada*/
    String strMsg = "0123456789abcdef";
 
  /*Enviano String em claro*/
    javino.sendMsgRF(strMsg);
    delay(1000);
  /****************************/

  /*Convertendo de String para Array de Bytes*/
  byte byteMsg[strMsg.length()];
  konverter.string2byteArray(strMsg, byteMsg);   //<<<<<------ aqui é que ocorre
  Serial.print("EM CLARO: ");
  exibe(byteMsg,strMsg.length());
  /*****************************************/

 /*Cifrando Mensagem com AES 128 CBC*/
  byteMsgCifrada = securino.encript("aes-128-cbc", byteMsg, byteChave);
  Serial.print("CBC: ");
  exibe(byteMsgCifrada,32);
  /****************************************/
  
  /*Convertendo a Mensagem Cifrada para String Base64*/
  String strMsgCifradaB64 = konverter.byte2strB64(byteMsgCifrada,32);
  Serial.print("CODIFICADA: ");
  Serial.println(strMsgCifradaB64);
  /**************************************/

  /*Enviano String Cifrada representada em Base64*/
    javino.sendMsgRF(strMsgCifradaB64);
    delay(1000);
  /****************************/
   Serial.println();  
}

/*****Auxiliar *****/
void exibe(byte * in, int x){
  for(int i=0; i < x; i++){  
      Serial.print(in[i],HEX);
      Serial.print(" ");  
   }
   Serial.println();  
}

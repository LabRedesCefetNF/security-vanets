#include "Base64.h"
#include "asciiHex.h"
#include "securino.h"
#include "Javino.h"

Javino javino;
AsciiHex ah;
Securino securino;

  byte byteMsg[] = {0x4d,0x65,0x20,0x61,0x6a,0x75,0x64,0x61,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
  byte byteChave[] = {0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
  byte * byteCifrado;
  byte * charDecifrado;


void setup() {
  Serial.begin(9600);
  javino.enableRF(12,11);
}

void loop() {
    delay(3000);
  String strMsg = "segredo";
  /*Enviano mensagem em claro*/
    javino.sendMsgRF(strMsg);
    delay(1000);
  /****************************/
  
  Serial.print("PLAIN:");
  exibe(byteMsg,16);
  
  byteCifrado = securino.encript("aes-128-ecb", byteMsg, byteChave);
  Serial.print("ECB: ");
  exibe(byteCifrado,16);
  delay(3000);

  byteCifrado = securino.encript("aes-128-cbc", byteMsg, byteChave);
  Serial.print("CBC: ");
  exibe(byteCifrado,32);
  


  
//  Serial.println(byteCifrado);

 // decifrado = securino.decript("aes-128-cbc", cifrado, chave);

 // securino.show("Chave ", chave);
 // Serial.println();
//  securino.show("Cifrado ", cifrado);
 // Serial.println();
//  securino.show("Decifrado ", decifrado);
  
/*
  char msg[] = "Bom dia, Patrick"; //16 bytes
  char enviar[] = "                ";
  byte hex[] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
  
  char encoded[BASE64::encodeLength(16)];

  byte * cifrado;
  byte * decifrado;

  Serial.print("Mensagem original (ascii): ");
  Serial.println(msg);
  
  ah.ascii2hex(msg, hex); //lança mensagem traduzida para hexadecimal na variável hex

  sec.show("Mensagem original (hex): ", hex);
  
  cifrado = sec.encript("aes-128-cbc", hex, chave); //criptografa mensagem
  
  sec.show("Mensagem cifrada (hex): ", cifrado);

  BASE64::encode((const byte*)cifrado, 16, encoded); //codifica mensagem cifrada para base64
  
  Serial.print("Mensagem cifrada (base64): ");
  Serial.println(encoded);
  Serial.println();
/*  */
}

void exibe(byte * in, int x){
  for(int i=0; i < x; i++){
      Serial.print(in[i], HEX);
      Serial.print(" ");  
   }
   Serial.println();  
}

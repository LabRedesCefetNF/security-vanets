#include "securino.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Securino securino;
  
  byte hex[] = {0x4d,0x65,0x20,0x61,0x6a,0x75,0x64,0x61,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
  byte chave[] = {0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
  byte * cifrado;
  byte * decifrado;

  cifrado = securino.encript("aes-128-cbc", hex, chave);
  decifrado = securino.decript("aes-128-cbc", cifrado, chave);

  securino.show("Chave ", chave);
  Serial.println();
  securino.show("Cifrado ", cifrado);
  Serial.println();
  securino.show("Decifrado ", decifrado);
}

void loop() {
  // put your main code here, to run repeatedly:

}

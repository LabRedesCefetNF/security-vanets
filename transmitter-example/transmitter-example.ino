#include "asciiHex.h"
#include "securino.h"
#include "Javino.h"

// TRANSMITTER

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  AsciiHex ah;
  Securino sec;
  Javino jav;

  jav.enableRF(12,11);
  jav.sendMsgRF("teste1");
  delay(500);

  char msg[] = "Bom dia, Patrick"; //16 bytes
  char enviar[] = "                ";
  byte hex[] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
  byte chave[] = {0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};

  byte * cifrado;
  byte * decifrado;

  Serial.print("Mensagem original (ascii): ");
  Serial.println(msg);
  Serial.println();
  
  ah.ascii2hex(msg, hex); //lança mensagem traduzida para hexadecimal na variável hex

  sec.show("Mensagem original (hex): ", hex);
  Serial.println();
  
  // cifrado = sec.encript("aes-128-cbc", hex, chave); //criptografa mensagem

  sec.show("Mensagem cifrada (hex): ", cifrado);

  ah.hex2ascii(cifrado, enviar);

  Serial.print("Mensagem cifrada (ascii): ");
  Serial.println(enviar);
  Serial.println();

  jav.sendMsgRF("teste2");
  delay(500);
}

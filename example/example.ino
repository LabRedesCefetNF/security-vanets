#include "asciiHex.h"
#include "securino.h"
#include "Javino.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  AsciiHex translator;
  Securino security;

  char msg[] = "Bom dia, Patrick"; //16 bytes
  char recebido[] = "                ";
  byte hex[] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
  byte chave[] = {0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};

  byte * cifrado;
  byte * decifrado;

  Serial.print("Mensagem plantext: ");
  Serial.println(msg);
  Serial.println();
  
  translator.ascii2hex(msg, hex); //lança mensagem traduzida para hexadecimal na variável hex

  security.show("Mensagem hex: ", hex);
  Serial.println();
  
  cifrado = security.encript("aes-128-cbc", hex, chave); //criptografa mensagem

  security.show("Mensagem cifrada: ", cifrado);

  // TODO - Envio da mensagem para outro dispositivo

  decifrado = security.decript("aes-128-cbc", cifrado, chave); //decriptografa mensagem

  security.show("Mensagem decifrada: ", decifrado);

  translator.hex2ascii(decifrado, recebido);
  
  Serial.print("Mensagem plantext: ");
  Serial.println(recebido);
  Serial.println();

  
  
/*  
  // Hexadecimal para ASCII
  byte hex[] = {0x4d,0x65,0x20,0x61,0x6a,0x75,0x64,0x61,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
  char texto[] = "                "; //16 bytes
  translator.hex2ascii(hex, texto);
  Serial.println(texto);

  // ASCII para Hexadecimal
  char ascii[] = "Bom dia, Patrick";
  byte converted[] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
  translator.ascii2hex(ascii, converted);
  for(byte i = 0; i < 16; i++){
    Serial.print(converted[i], HEX);
  }
*/
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

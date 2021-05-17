#include "asciiHex.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  AsciiHex translator;
  
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
}

void loop() {
  // put your main code here, to run repeatedly:

}

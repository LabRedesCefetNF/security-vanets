#include "Arduino.h"
#include "asciiHex.h"

// Hexadecimal to ASCII conversion
void AsciiHex::hex2ascii(byte * hex, char * ascii){
  for(byte i = 0; i < 16; i++){
    if(hex[i] > 0x1f){ //tratativa para caracteres não imprimíveis serem ignorados
      ascii[i] = char(hex[i]);
    }
  }
}

// ASCII to Hexadecimal conversion
void AsciiHex::ascii2hex(char * ascii, byte * hex){
  for(byte i = 0; i < 16; i++){
    if(byte(ascii[i]) < 0x7f){ //tratativa para caracteres além da ASCII serem ignorados
      hex[i] = byte(ascii[i]);
    }
  }
}
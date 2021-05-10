// Hexadecimal to ASCII conversion
void hex2ascii(char * hex, char * ascii){
  for(byte i = 0; i < 16; i++){
    if(hex[i] > 0x1f){ //tratativa para caracteres não imprimíveis serem ignorados
      ascii[i] = char(hex[i]);
    }
  }
}

// ASCII to Hexadecimal conversion
void ascii2hex(char * ascii, char * hex){
  for(byte i = 0; i < 16; i++){
    if(byte(ascii[i]) < 0x7f){ //tratativa para caracteres além da ASCII serem ignorados
      hex[i] = byte(ascii[i]);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // Hexadecimal para ASCII
  byte hex[] = {0x4d,0x65,0x20,0x61,0x6a,0x75,0x64,0x61,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
  char texto[] = "                "; //16 bytes
  hex2ascii(hex, texto);
  Serial.println(texto);

  // ASCII para Hexadecimal
  char ascii[] = "Bom dia, Patrick";
  byte converted[] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
  ascii2hex(ascii, converted);
  for(byte i = 0; i < 16; i++){
    Serial.print(converted[i], HEX);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

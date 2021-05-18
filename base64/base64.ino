#include <Base64.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  const byte rawData[] = {0x42, 0x6f, 0x6d, 0x20, 0x64, 0x69, 0x61, 0x2c, 0x20, 0x50, 0x61, 0x74, 0x72, 0x69, 0x63, 0x6b};
  size_t rawLength = strlen(rawData);
  
  char encoded[BASE64::encodeLength(rawLength)];
  BASE64::encode((const byte*)rawData, rawLength, encoded);
  
  Serial.println(encoded);


  byte raw[BASE64::decodeLength(encoded)];
  BASE64::decode(encoded, raw);
  
  Serial.println((char*)raw);
}

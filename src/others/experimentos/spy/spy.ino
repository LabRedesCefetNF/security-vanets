#include <VirtualWire.h>
void setup(){
    Serial.begin(9600);
    vw_set_rx_pin(11);
    vw_setup(2048); 
    vw_rx_start();
}

void loop(){
    String m;
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)){ 
      for (int i=0; i < buflen; i++){
        m=m+String((char)buf[i]);
    }
    Serial.println(m);
    }
}

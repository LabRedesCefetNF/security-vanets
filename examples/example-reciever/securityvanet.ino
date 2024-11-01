#include "securino.h" /*import library from https://github.com/LabRedesCefetNF/security-vanets/releases/download/1.0.0/securityvanets.zip*/
#include "Javino.h"
#include "Konverter.h"
Javino javino;
Securino securino;
Konverter konverter;

byte * byteMsgCifrada;
byte byteChave[16];
String strMsgCifradaB64;
String strMsgPlain;

byte    byteMsgCifradaRecebida[32];
byte *  byteMsg;
String  strClaro;


void enableRF(int iTX, int iRX){
    javino.enableRF(iTX,iRX);
}

void setKey(String strKey){
  konverter.string2byteArray(strKey,byteChave);
}

void setPlainTxt(String strMsg){
  byte byteMsg[strMsg.length()];
  konverter.string2byteArray(strMsg, byteMsg); 
  byteMsgCifrada = securino.encript("aes-128-cbc", byteMsg, byteChave);
  strMsgCifradaB64 = konverter.byte2strB64(byteMsgCifrada,32);
}

String getCipherTxt(){
  return strMsgCifradaB64;
}

void trasmiter(String strMsg){
  setPlainTxt(strMsg);
  javino.sendMsgRF(getCipherTxt());
}

void transmiter(){
  javino.sendMsgRF(getCipherTxt());
}

String getPlainTxt(){
  return strMsgPlain;
}

void setCipherTxt(String strIN){
    konverter.strB64toByte(strIN,byteMsgCifradaRecebida);
    byteMsg = securino.decript("aes-128-cbc", byteMsgCifradaRecebida, byteChave);
    strMsgPlain = konverter.byteArray2String(byteMsg);
}

boolean receiver(){
  if(javino.availableMsgRF()){
    setCipherTxt(javino.getMsg());
    return true;
  }
  return false;
}

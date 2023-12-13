
void SendData(){
//[CMD S0]:0|0|0|0|0|0|0|0|0|0|0|0|0
String CSA;
int spins = sizeof(vsp) / sizeof(vsp[0]);
for (int i=0; i<spins; i++){
  CSA = CSA + digitalRead(vsp[i]);
  }
Serial.println ("[CMD " + CMDName + "]:" + CSA);
client.print ("[CMD " + CMDName + "]:" + CSA);
}


void onDataSend(){
  if (client.connected()){
      SendData();
    }
}

void onDataReceived(){
  if (client.available() > 0) {
    String cData = client.readString();
    //RevData(cData);
    //delay(100);
    }
}

String xData;
void SendData(){
//[CMD S0]:0|0|0|0|0|0|0|0|0|0|0|0|0
int CSA;
int spins = sizeof(vsp) / sizeof(vsp[0]);
for (int i=0; i<spins; i++){
  CSA = digitalRead(vsp[i]);
  }

xData = "";
while (Serial.available()){
  char c = Serial.read();
  if (c == '\n'){
    break;
    }
    xData += c;
    delayMicroseconds(100);
}

Serial.print ("[CMD " + CMDName + "]:" + xData + "|" + String(CSA));
client.print ("[CMD " + CMDName + "]:" + xData + "|" + String(CSA));
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

void splitString(String str, char delimiter, String *arr, int size){
  int i = 0;
  char* ptr;
  ptr = strtok((char*)str.c_str(), &delimiter);

  while (ptr != NULL && i < size){
    arr[i] = ptr;
    i++;
    ptr = strtok(NULL, &delimiter);
    }
}

void RevData(String vData){
//Serial.println(vData);
//[CMD P0]:255|255|255|255
//Validate
if (vData.indexOf("[CMD "+ CMDName) != -1){
String vID = vData.substring(vData.lastIndexOf("[CMD " + CMDName+ "-")+8,vData.lastIndexOf("]") );
String vSt = vData.substring(vData.lastIndexOf("]:")+2,vData.length());
Serial.println(vSt);
String PID[3];
splitString(vSt, '|', PID,4);
int spins = sizeof(PID) / sizeof(PID[0]);
//Fx
for (int i=0; i<=spins; i++){
   Serial.println(PID[i]);
   analogWrite(vsp[i], PID[i].toInt());
  }

 }
}

void onDataReceived(){
  if (client.available() > 0) {
    String cData = client.readString();
    RevData(cData);
    //delay(100);
    }
}


void SendData(){
//[CMD P0]:0|0|0|0|0|0|0|0|0|0|0|0|0
}


void onDataSend(){
  if (client.connected()){
      SendData();
    }
}

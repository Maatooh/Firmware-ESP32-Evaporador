
void RevData(String vData){
//Serial.println(vData);
//[CMD V0]:00000000000000000000
//Validate
if (vData.indexOf("[CMD "+ CMDName) != -1){
String vID = vData.substring(vData.lastIndexOf("[CMD " + CMDName+ "-")+8,vData.lastIndexOf("]") );
String vSt = vData.substring(vData.lastIndexOf("]:")+2,vData.length());
//Serial.println(vSt);
int PiS[20];
PiS[0] = vSt.substring(0,1).toInt();
PiS[1] = vSt.substring(1,2).toInt();
PiS[2] = vSt.substring(2,3).toInt();
PiS[3] = vSt.substring(3,4).toInt();
PiS[4] = vSt.substring(4,5).toInt();
PiS[5] = vSt.substring(5,6).toInt();
PiS[6] = vSt.substring(6,7).toInt();
PiS[7] = vSt.substring(7,8).toInt();
PiS[8] = vSt.substring(8,9).toInt();
PiS[9] = vSt.substring(9,10).toInt();
PiS[10] = vSt.substring(10,11).toInt();
PiS[11] = vSt.substring(11,12).toInt();
PiS[12] = vSt.substring(12,13).toInt();
PiS[13] = vSt.substring(13,14).toInt();
PiS[14] = vSt.substring(14,15).toInt();
PiS[15] = vSt.substring(15,16).toInt();
PiS[16] = vSt.substring(16,17).toInt();
PiS[17] = vSt.substring(17,18).toInt();
PiS[18] = vSt.substring(18,19).toInt();
PiS[19] = vSt.substring(19,20).toInt();
int spins = sizeof(PiS) / sizeof(PiS[0]);
//Fx
for (int i=0; i<spins; i++){
   if (PiS[i] == 1){digitalWrite(vsp[i], LOW);}
   if (PiS[i] == 0){digitalWrite(vsp[i], HIGH);}
  }

 }
}

void onDataReceived() {
  if (client.available() > 0) {
    String cData = client.readString();
    RevData(cData);
    //delay(100);
    }
}

int vsp[] = {14,27,26,25,33,32,35,34,39,36,15,4};
String SData;

void setup()
{
  Serial.begin(115200); 
  #include "SetPins.h"
}

long analogReadFx(int PinRead){
  double PinVal = 0;
  for (int i = 0; i < 64; i++) {
    PinVal += analogRead(PinRead);
  }
  return long(PinVal / 64);
}

void loop(){
  SData = String(NULL);
  int npins = sizeof(vsp) / sizeof(vsp[0]);
  for (int i=0; i < npins; i++){
  SData = SData + String(analogReadFx(vsp[i])) + "|";
  }
  SData = SData.substring(0,SData.length()-1);
  Serial.print("[Ri]"+SData);
  delay(600);
}

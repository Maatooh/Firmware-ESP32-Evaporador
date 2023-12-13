//-----------Set Pins----------//
int npins = sizeof(vsp) / sizeof(vsp[0]);
for (int i=0; i < npins; i++){
  pinMode(vsp[i], OUTPUT);
}
//-------------------------------//

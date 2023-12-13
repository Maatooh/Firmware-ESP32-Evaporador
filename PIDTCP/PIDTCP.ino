#include <WiFi.h>
#include <WiFiClient.h>
TaskHandle_t Task2;
const char* ssid = "XiContreras";
const char* password =  "wk5Xxhhmnjsx@";
const uint16_t port = 5225;
const char * host = "192.168.31.10"; //"192.168.21.175";
String deviceName = "PDev0";
String CMDName = "P0";
int vsp[] = {14,27,26,25};
WiFiClient client;
#include "RvData.h"
#include "WifiFix.h"

void loop2( void * pvParameters ){
  while (1){
  reconnectWifi();
  reconnectTCP();
  rPing();
  delay(300);
  //Serial.print("Task1 running on core ");
  //Serial.println(xPortGetCoreID());
  } 
}

void setup()
{
  Serial.begin(115200, SERIAL_8N1, 16, 17);
//-----------Set Pins----------//
#include "SetPins.h"
//-------------------------------//
  WiFi.setHostname((String("ESP32-") + deviceName).c_str());
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
  reconnectTCP();
    Serial.println("Connected to server successful!");
    client.print(deviceName+ " - connected");
    xTaskCreatePinnedToCore(loop2, "Task2", 10000, NULL, 1, &Task2, 0);        
    delay(500); 
}

void loop(){
  onDataReceived();
  delay(600);
  //Serial.print("Task1 running on core ");
  //Serial.println(xPortGetCoreID());
}

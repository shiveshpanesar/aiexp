#include <Arduino.h>
#include "KuriousWifi.h"
kuriousWifi AIexplorer;
String receiveDataFromServer;
String sendSensorDataToServer = "noData";
bool autoRefresh = false;
void setup()
{
  Serial.begin(9600);
  AIexplorer.sensorServer("ssid", "led.html", &sendSensorDataToServer, &receiveDataFromServer, &autoRefresh);
  pinMode(23, OUTPUT);
}

void loop()
{
  AIexplorer.runServer();
  Serial.println("sensorData:  " + sendSensorDataToServer + " data:  " + receiveDataFromServer);
  if (receiveDataFromServer == "ledOn")
  {
    sendSensorDataToServer = "\"led On\"";
    digitalWrite(23, HIGH);
  }
  else
  {
    sendSensorDataToServer = "\"led Off\"";
    digitalWrite(23, LOW);
  }
}

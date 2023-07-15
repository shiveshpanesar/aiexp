#include <Arduino.h>
#include "KuriousWifi.h"
kuriousWifi AIexplorer;
String receiveDataFromServer;
String sendSensorDataToServer = "noData";
void setup()
{
  Serial.begin(9600);
  AIexplorer.sensorServer("Kblox AI Beginner", "gas.html", &sendSensorDataToServer, &receiveDataFromServer);
  pinMode(33, INPUT);
}

void loop()
{
  AIexplorer.runServer();
  int sMin = 0;
  int sMax = 250;
  uint64_t mq135Value = 0;
  Serial.println(analogRead(33));
  for (int i = 0; i < 100; i++)
    mq135Value += analogRead(33);
  mq135Value = mq135Value / 100;
  mq135Value = map(mq135Value, sMin, sMax, 0, 999);
  sendSensorDataToServer = String(mq135Value);
  Serial.println("sensorData:  " + sendSensorDataToServer + " data:  " + receiveDataFromServer);
}

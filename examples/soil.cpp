#include <Arduino.h>
#include "KuriousWifi.h"
// kuriousWifi AIexplorer;
String receiveDataFromServer;
String sendSensorDataToServer = "noData";
bool autoRefresh = true;
void setup()
{
    Serial.begin(9600);
    AIexplorer.sensorServer("Kblox AI Beginner", "1234567890", &sendSensorDataToServer, &receiveDataFromServer, &autoRefresh);
    pinMode(33, INPUT);
}

void loop()
{
    AIexplorer.runServer();
    int sMin = 0;
    int sMax = 4096;
    uint64_t soilSensor = 0;
    Serial.println(analogRead(33));
    for (int i = 0; i < 100; i++)
        soilSensor += analogRead(33);
    soilSensor = soilSensor / 100;
    soilSensor = map(soilSensor, sMin, sMax, 0, 999);
    sendSensorDataToServer = String(soilSensor);
    Serial.println("sensorData:  " + sendSensorDataToServer + " data:  " + receiveDataFromServer);
}

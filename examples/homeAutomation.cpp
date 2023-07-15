#include <Arduino.h>
#include "KuriousWifi.h"
kuriousWifi AIexplorer;
String receiveDataFromServer;
String sendSensorDataToServer = "noData";
void setup()
{
    Serial.begin(9600);
    AIexplorer.sensorServer("Kblox AI Beginner", "homeAutomation.html", &sendSensorDataToServer, &receiveDataFromServer);
    pinMode(23, OUTPUT);
    digitalWrite(23, LOW);
}

void loop()
{
    AIexplorer.runServer();
    Serial.println("sensorData:  " + sendSensorDataToServer + " data:  " + receiveDataFromServer);
    if (receiveDataFromServer == "relayOn")
    {
        sendSensorDataToServer = "\"relay On\"";
        digitalWrite(23, HIGH);
    }
    else
    {
        sendSensorDataToServer = "\"relay Off\"";
        digitalWrite(23, LOW);
    }
}

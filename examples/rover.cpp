#include <Arduino.h>
#include "KuriousWifi.h"
kuriousWifi AIexplorer;
String receiveDataFromServer;
String sendSensorDataToServer = "noData";
void setup()
{
    Serial.begin(9600);
    AIexplorer.sensorServer("Kurious AI Beginner", "rover.html", &sendSensorDataToServer, &receiveDataFromServer);
}

void loop()
{
    AIexplorer.runServer();
    Serial.println("sensorData:  " + sendSensorDataToServer + " data:  " + receiveDataFromServer);
    if (receiveDataFromServer == "f")
    {
        sendSensorDataToServer = "\"forward\"";
        AIexplorer.forward();
    }
    else if (receiveDataFromServer == "b")
    {
        sendSensorDataToServer = "\"backward\"";
        AIexplorer.backward();
    }
    else if (receiveDataFromServer == "r")
    {
        sendSensorDataToServer = "\"right\"";
        AIexplorer.rightward();
    }
    else if (receiveDataFromServer == "l")
    {
        sendSensorDataToServer = "\"left\"";
        AIexplorer.leftward();
    }
    else if (receiveDataFromServer == "s")
    {
        sendSensorDataToServer = "\"stop\"";
        AIexplorer.stop();
    }

    if (receiveDataFromServer == "greenD")
        AIexplorer.buzzer(true);
    if (receiveDataFromServer == "greenU")
        AIexplorer.buzzer(false);
    // if(receiveDataFromServer)
}

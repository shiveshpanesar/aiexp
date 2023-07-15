#include <Arduino.h>
#include "KuriousWifi.h"
#include "dht11.h"
kuriousWifi AIexplorer;
String receiveDataFromServer;
String sendSensorDataToServer = "noData";
DHT11 dht(23);
void setup()
{
    Serial.begin(9600);
    AIexplorer.sensorServer("Kblox AI Beginner", "dht.html", &sendSensorDataToServer, &receiveDataFromServer);
}

void loop()
{
    AIexplorer.runServer();
    dht.updateData();
    // sendSensorDataToServer = "\"" + String(dht.temperature) + " *C / " + String(dht.humidity) + "\"";
    sendSensorDataToServer = String(dht.temperature);

    Serial.println("sensorData:  " + sendSensorDataToServer + " data:  " + receiveDataFromServer);
}

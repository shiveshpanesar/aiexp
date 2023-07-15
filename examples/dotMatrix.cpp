#include <Arduino.h>
#include "KuriousWifi.h"
#include "dotMatrix.h"
kuriousWifi AIexplorer;
String receiveDataFromServer;
String sendSensorDataToServer = "noData";
dotMatrix display(14, 12, 13);

void parseStringToArray(String input);

int dataArray[64];
int dataArraySize = sizeof(dataArray) / sizeof(dataArray[0]);

void setup()
{
  Serial.begin(9600);
  AIexplorer.sensorServer("Kblox AI Beginner", "dotMatrix.html", &sendSensorDataToServer, &receiveDataFromServer);
  pinMode(33, INPUT);
  display.begin();
}

void loop()
{
  AIexplorer.runServer();
  parseStringToArray(receiveDataFromServer);
  display.display();
  for (int i = 0; i < 8; i++)
    display.data[i] = 0b00000000;
  Serial.println("sensorData:  " + sendSensorDataToServer + " data:  " + receiveDataFromServer);
}

void parseStringToArray(String input)
{
  for (int i = 0; i < dataArraySize; i++)
    dataArray[i] = 0;
  char charArray[input.length() + 1];
  input.toCharArray(charArray, sizeof(charArray));

  char *token = strtok(charArray, ",");
  int index = 0;

  while (token != NULL && index < dataArraySize)
  {
    dataArray[index] = atoi(token);
    index++;
    token = strtok(NULL, ",");
  }

  for (int i = 0; i < dataArraySize; i++)
    if (dataArray[i] != 0)
    {
      int row = dataArray[i] / 10;
      int col = dataArray[i] % 10;
      row--;
      byte input = 0b11111111;
      byte out = (input << (col - 1)) & (input >> (8 - col));

      display.data[row] |= out;
      Serial.println(display.data[row], BIN);
    }
}
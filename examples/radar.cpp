#include <Arduino.h>
#include "KuriousWifi.h"
#include "servo.h"
#include "ultraSonic.h"
servo Servo(23);
kuriousWifi AIexplorer;
ultraSonic us(22, 21);
long duration;
int distance;
int calculateDistance();
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for (int i = 15; i <= 165; i++)
  {
    Servo.moveServoTo(i);
    distance = us.getDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  for (int i = 165; i > 15; i--)
  {
    Servo.moveServoTo(i);
    distance = us.getDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

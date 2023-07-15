#include <Arduino.h>
#include "KuriousWifi.h"
kuriousWifi AIexplorer;
ultraSonic us(23, 22);
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println(us.getDistance());
    if (us.getDistance() < 20)
        AIexplorer.leftward();
    else
        AIexplorer.forward();
}

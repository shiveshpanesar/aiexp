#include <Arduino.h>
#include "KuriousWifi.h"
kuriousWifi AIexplorer;
void setup()
{
    Serial.begin(9600);
}

void loop()
{

    if (AIexplorer.getLeftIR() == AIexplorer.getRightIR())
        AIexplorer.forward();
    else if (AIexplorer.getLeftIR() > AIexplorer.getRightIR())
        AIexplorer.leftward();
    else if (AIexplorer.getLeftIR() < AIexplorer.getRightIR())
        AIexplorer.rightward();
}

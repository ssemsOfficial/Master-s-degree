#include "SoilMoitureImp.h"


void SoilMoitureImp::init(/* args */)
{
    pinMode(sensorPin, INPUT);
}

float SoilMoitureImp::moisturePourcentage()
{

    return ( 100 - ( (analogRead(sensorPin)/1023.00) * 100 ) );
}

#include"HandleSoilMoiture.h"

float HandleSoilMoiture::getMoistureData()
{
    return soilMoistureSensor->moisturePourcentage();
}
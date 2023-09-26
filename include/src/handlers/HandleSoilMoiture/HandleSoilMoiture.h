#ifndef HANDLESOILMOITURE
#define HANDLESOILMOITURE

#include<src/components/soilMoiture/ISoilMoiture.h>
#include<src/components/soilMoiture/SoilMoitureImp.h>

class HandleSoilMoiture
{
private:
    ISoilMoiture *soilMoistureSensor;   
public:
    HandleSoilMoiture()
    {}
    HandleSoilMoiture(ISoilMoiture* soilMoistureSensor):
     soilMoistureSensor(soilMoistureSensor)
    {} 
    ~HandleSoilMoiture()
    {
        delete soilMoistureSensor;
    }

    float getMoistureData();
};





#endif
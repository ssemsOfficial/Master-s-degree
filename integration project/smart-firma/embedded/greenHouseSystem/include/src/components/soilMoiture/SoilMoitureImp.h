#ifndef SOILMOITUREIMP_H
#define SOILMOITUREIMP_H

#ifdef UNIT_TEST
    #include <test/ArduinoNativeTest/ArduinoNativeTest.h>
        using namespace ArduinoUnitTest;
#else
        #include <test/ArduinoNativeTest/ArduinoNativeTest.h>
        using namespace ArduinoUnitTest;
#endif


#include <src/components/soilMoiture/ISoilMoiture.h>


class SoilMoitureImp : public ISoilMoiture 
{
private:
    int sensorPin;
public:
    SoilMoitureImp(int sensorPin):
      sensorPin(sensorPin)
    {}  
    ~SoilMoitureImp()
    {}

    void init() override;
    float moisturePourcentage() override;
};

#endif
#ifndef STEPPERMOTORDRIVERIMP_H
#define STEPPERMOTORDRIVERIMP_H

#ifdef UNIT_TEST
    #include <test/ArduinoNativeTest/ArduinoNativeTest.h>
        using namespace ArduinoUnitTest;
#else
        #include <test/ArduinoNativeTest/ArduinoNativeTest.h>
        using namespace ArduinoUnitTest;
#endif


#include "src/components/stepperMotorDriver/IStepperMotorDriver.h"


#define RELAY_ON 1
#define RELAY_OFF 0


class StepperMotorDriverImp : public IStepperMotorDriver
{
private:
    int StepPin;
    int DirPin;
public:
    StepperMotorDriverImp(int StepPin, int DirPin):
    StepPin(StepPin), DirPin(DirPin)
    {

    }
    ~StepperMotorDriverImp()
    {
        
    }
    void init() override;
    void setMotor(int steps, int direction) override;
    
};

#endif
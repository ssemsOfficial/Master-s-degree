#ifndef STEPPERMOTORIMP_H
#define STEPPERMOTORIMP_H

#include "src/components/stepperMotor/IStepperMotor.h"
#include "src/components/stepperMotorDriver/IStepperMotorDriver.h"
#include "src/components/stepperMotorDriver/StepperMotorDriverImp.h"

class StepperMotorImp :  public IStepperMotor
{
private:
    IStepperMotorDriver* stepperMotorDriver;
public:
    /*StepperMotorImp(int stepPin, int dirPin) = default;*/
    StepperMotorImp() :
        stepperMotorDriver(nullptr)
    {}
    StepperMotorImp(IStepperMotorDriver* driver):
       stepperMotorDriver(driver)
    {}
    StepperMotorImp(int stepPin, int dirPin) :
        stepperMotorDriver(new StepperMotorDriverImp(stepPin, dirPin))
    {}
    ~StepperMotorImp()
    {
       delete stepperMotorDriver;
    }

    void init() override;
    void setStepperPosition(int steps, int direction) override;
    void setMotorDriver(IStepperMotorDriver* driver){
        stepperMotorDriver = driver;
    }
};

#endif
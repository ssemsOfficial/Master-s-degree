#include "src/components/stepperMotor/StepperMotorImp.h"

void StepperMotorImp::init(){
    Serial.println("init in Stepper done");
    stepperMotorDriver->init();
}

void StepperMotorImp::setStepperPosition(int steps, int direction){
    stepperMotorDriver->setMotor( steps, direction );
}


















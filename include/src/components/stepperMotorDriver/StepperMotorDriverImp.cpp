#include "src/components/stepperMotorDriver/StepperMotorDriverImp.h"

void StepperMotorDriverImp:: init(){
    pinMode(StepPin, OUTPUT);
    pinMode(DirPin, OUTPUT);    
}

void StepperMotorDriverImp:: setMotor(int steps, int direction){
   digitalWrite(DirPin, direction); 
   for(int ind = 0; ind < steps; ind++)
   {
        digitalWrite(StepPin, HIGH);
        delayMicroseconds(2000);
        digitalWrite(StepPin, LOW);
        delayMicroseconds(2000);
   }
}

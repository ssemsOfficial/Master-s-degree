#ifndef ISTEPPERMOTOR_H
#define ISTEPPERMOTOR_H

class IStepperMotor
{
   
 public:
    ~IStepperMotor(){};
    virtual void init() = 0;
    virtual void setStepperPosition(int steps, int direction) = 0;
};

#endif
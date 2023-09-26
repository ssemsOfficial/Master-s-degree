#ifndef ISTEPPERMOTORDRIVER_H
#define ISTEPPERMOTORDRIVER_H

#ifdef UNIT_TEST
    #include <test/ArduinoNativeTest/ArduinoNativeTest.h>
#else
    #include <test/ArduinoNativeTest/ArduinoNativeTest.h>
#endif

#define RELAY_ON 1
#define RELAY_OFF 0


class IStepperMotorDriver 
{

public:
    IStepperMotorDriver(){}
    virtual ~IStepperMotorDriver() = default; 
    virtual void init() = 0;
    virtual void setMotor(int steps, int direction) = 0;
    
};

#endif
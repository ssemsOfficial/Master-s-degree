#ifndef MOTORIMP_H
#define MOTORIMP_H

#include <src/components/motor/IMotor.h>
#include <src/components/relay/IRelay.h>
#include <src/components/relay/RelayImp.h>

class MotorImp : public IMotor
{
private:
    IRelay* motorRelay;
public:
    MotorImp() 
    {}
    MotorImp(IRelay* relay) 
    : motorRelay(relay)
    {}
    MotorImp(int pin) 
    : motorRelay(new RelayImp(pin))
    {}
    ~MotorImp()
    {
        delete motorRelay;
    }

    void init() override;
    void turnOn() override;
    void turnOff() override;
};

#endif
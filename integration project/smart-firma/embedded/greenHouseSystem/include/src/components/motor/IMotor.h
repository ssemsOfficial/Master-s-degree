#ifndef IMOTOR_H
#define IMOTOR_H

class IMotor
{
   
public:
    virtual ~IMotor(){};
    virtual void init() = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

};

#endif
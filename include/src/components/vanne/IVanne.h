#ifndef IVANNE_H
#define IVANNE_H

class IVanne
{
   
public:
    ~IVanne(){} = default;
    virtual void init();
    virtual void turnOn();
    virtual void turnOff();

};

#endif
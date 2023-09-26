#ifndef VANNEIMP.H
#define VANNEIMP.H

#include <src/components/vanne/IVanne.h>
#include <src/components/relay/IRelay.h>
#include <src/components/relay/RelayImp.h>

class VanneImp : public IVanne
{
private:
    IRelay *vanneRelay;
public:
    VanneImp()
    {}
    VanneImp(int pin) 
    : vanneRelay(new VanneImp(pin))
    {}
    VanneImp(IRelay *vanneRelay)
    : vanneRelay(vanneRelay)
    ~VanneImp()
    {
        vanneRelay->~IRelay();
    }

    void init() override;
    void turnOn() override;
    void turnOff() override;
};

#endif




#ifndef RELAYIMP_H
#define RELAYIMP_H

#include <src/components/relay/IRelay.h>


class RelayImp : public IRelay{
private:
    int pin;

public: 
    
    RelayImp(int pin):
        pin(pin)
    {}
    ~RelayImp()
    {}
        
    void init() override;
        
    void on() override;
        
    void off() override;
};

#endif 
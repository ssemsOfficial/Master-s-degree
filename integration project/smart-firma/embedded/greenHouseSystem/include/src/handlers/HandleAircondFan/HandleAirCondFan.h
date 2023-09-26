#ifndef HANDLEAIRCONDFAN_H
#define HANDLEAIRCONDFAN_H

#include "src/components/motor/IMotor.h"

#define FAN_IS_TURNNED_ON true
#define FAN_IS_TURNNED_OFF false

class HandleAirCondFan
{
 private:
    IMotor* fanMotor;
    bool fanStatus;
 public:
    HandleAirCondFan()
    {}
    HandleAirCondFan(IMotor* fanMotor):
     fanMotor(fanMotor)
    {}
    ~HandleAirCondFan()
    {
        delete fanMotor;
    }
    bool getFanStatus();
    void setFanStatus(bool fanStatus);
    void turnOnFan();
    void turnOffFan();
};


#endif


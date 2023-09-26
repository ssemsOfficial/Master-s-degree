#include"HandleAirCondFan.h"

bool  HandleAirCondFan::getFanStatus(){
    return fanStatus;   
}

void HandleAirCondFan::setFanStatus(bool fanStatus){
    this->fanStatus = fanStatus;
}

void  HandleAirCondFan::turnOnFan(){
    fanMotor->turnOn();
    setFanStatus(FAN_IS_TURNNED_ON);
}

void HandleAirCondFan::turnOffFan(){
    fanMotor->turnOff();
    setFanStatus(FAN_IS_TURNNED_OFF);
}
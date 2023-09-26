#include "MotorImp.h"

void MotorImp::init(){
    motorRelay->init();
}

void MotorImp::turnOn(){
    motorRelay->on();
}

void MotorImp::turnOff(){
    motorRelay->off();
}

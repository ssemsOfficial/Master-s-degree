#include"HandleVanneControl.h"

bool  HandleVanneControl::getVanneStatus(){
    return vanneStatus;   
}

void HandleVanneControl::setVanneStatus(bool vanneStatus){
    this->vanneStatus = vanneStatus;
}

void  HandleVanneControl::turnVanneOn(){
    vanne->turnOn();
    setVanneStatus(VANNE_IS_OPENED);
}

void HandleVanneControl::turnVanneOff(){
    vanne->turnOff();
    setVanneStatus(VANNE_IS_CLOSED);
}
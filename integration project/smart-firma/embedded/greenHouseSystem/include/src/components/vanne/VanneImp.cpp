#include "VanneImp.h"

void VanneImp::init(){
    vanneRelay->init();
}

void VanneImp::turnOn(){
    vanneRelay->on();
}

void VanneImp::turnOff(){
    vanneRelay->off();
}

#include <src/components/relay/RelayImp.h>

void RelayImp::init(){
    pinMode(pin, OUTPUT);
}

void RelayImp::on(){

    digitalWrite(pin, RELAY_ON);

}

void RelayImp::off(){

    digitalWrite(pin, RELAY_OFF);

}




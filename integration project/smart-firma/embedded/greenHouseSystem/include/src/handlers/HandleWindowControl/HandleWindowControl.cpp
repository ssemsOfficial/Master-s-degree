#include"HandleWindowControl.h"

bool  HandleWindowControl::getWindowStatus(){
    return windowStatus;   
}

void HandleWindowControl::setWindowStatus(bool windowStatus){
    this->windowStatus = windowStatus;
}

void  HandleWindowControl::openWindow(){
    stepperMotor->setStepperPosition(OPEN_WINDOW_STEPS ,OPEN_WINDOW_DIRECTION);
    setWindowStatus(WINDOW_IS_OPENED);
}

void HandleWindowControl::closeWindow(){
    stepperMotor->setStepperPosition(CLOSE_WINDOW_STEPS, CLOSE_WINDOW_DIRECTION);
    setWindowStatus(WINDOW_IS_CLOSED);
}
#ifndef HANDLEWINDOWCONTROL_H
#define HANDLEWINDOWCONTROL_H

#include "src/components/stepperMotor/IStepperMotor.h"

#define WINDOW_IS_OPENED true
#define WINDOW_IS_NOT_OPENED false
#define WINDOW_IS_CLOSED false
#define WINDOW_IS_NOT_CLOSED false
#define OPEN_WINDOW_STEPS 90
#define OPEN_WINDOW_DIRECTION 1
#define CLOSE_WINDOW_STEPS 90
#define CLOSE_WINDOW_DIRECTION 0

class HandleWindowControl
{
 private:
    IStepperMotor* stepperMotor;
    bool windowStatus;
    
 public:
    HandleWindowControl()
    {}
    HandleWindowControl(IStepperMotor* stepperMotor):
     stepperMotor(stepperMotor)
    {}
    ~HandleWindowControl()
    {
        delete stepperMotor;
    }
    bool getWindowStatus();
    void setWindowStatus(bool WindowStatus);
    void openWindow();
    void closeWindow();
};


#endif


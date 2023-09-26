#ifndef AIRCONDITIONINGSYSTEM_H
#define AIRCONDITIONINGSYSTEM_H

//handlers
#include "handlers/HandleWindowControl/HandleWindowControl.h"
#include "handlers/HandleAircondFan/HandleAirCondFan.h"

//components
#include"src/components/stepperMotor/IStepperMotor.h"
#include"src/components/stepperMotor/StepperMotorImp.h"
#include"src/components/motor/IMotor.h"
#include"src/components/motor/MotorImp.h"


class AirConditioningSystem
{
private:
    struct SystemEvents
    {
        bool OnFanTurnedOn = false;
        bool OnFanTurnedOff = false;
        bool OnWindowOpened = false;
        bool OnWindowClosed = false;
        bool OnGetOverTemperature = false;
        bool OnGetTargetTemperature = false;
        bool OnGetUnderTemperture = false;
        
    };
    SystemEvents events;

    enum SystemModes  
    {
        MODE_AUTOMATIC,
        MODE_MANUAL
    };
    SystemModes systemMode = MODE_AUTOMATIC;  

    enum SystemStates  
    {
        DEFUALT_STATE,
        AMBIANT_ENVIRONMENT,
        WINDOW_OPENED,
        WINDOW_OPENING,
        WINDOW_CLOSED,
        WINDOW_CLOSING,
        FAN_TURNED_ON,
        FAN_TURNING_ON,
        FAN_TURNED_OFF,
        FAN_TURNING_OFF,
    };
    SystemStates systemState = DEFUALT_STATE;  

    struct SystemActions  // les sorties de systeme
    {
        bool turnOnFan = false;
        bool turnOffFan = false;
        bool openWindow = false;
        bool closeWindow = false;
        bool getTemperatureState = false;
    };
    SystemActions actions;
    
    IStepperMotor* window;
    HandleWindowControl windowHandler;
    
    IMotor* fan;
    HandleAirCondFan fanHandler;

public:
    AirConditioningSystem(int windowStepPin, int windowDirPin, int fanPin):
     window(new StepperMotorImp(windowStepPin, windowDirPin)),
     windowHandler(window),
     fan(new MotorImp(fanPin)),
     fanHandler(fan)   
    { }
    ~AirConditioningSystem()
    {
        windowHandler.~HandleWindowControl();
        fanHandler.~HandleAirCondFan();
    }
    void init();
    void updateEvents();
    void FSM_IrrigationSystem();
    void updateActions();
};

#endif
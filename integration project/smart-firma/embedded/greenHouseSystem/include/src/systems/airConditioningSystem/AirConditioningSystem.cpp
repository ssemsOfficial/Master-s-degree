#include "AirConditioningSystem.h"

void AirConditioningSystem::init(){
    window->init();
    fan->init();
}

void AirConditioningSystem::updateEvents()
{


}

void AirConditioningSystem::FSM_AirConditioningSystem()
{
    switch (systemMode) {

        case MODE_AUTOMATIC:
            if (events.OnManModeBtnClicked == is_man_mode_btn_clicked){
                systemMode = MODE_MANUAL;
            }
            switch (systemState) {
                //////////////////////
                case WINDOW_OPENING:
                    if (events.OnWindowClosed) {
                        //ACTIONS
                        actions.openWindow = false;
                        actions.closeWindow = true;
                        //NEXT STATE
                        systemState = WINDOW_CLOSED;
                    }
                break;

                case WINDOW_OPENED :
                    if (events.OnGetTargetTemperature) {
                        
                        actions.turnOnFan = false;
                        actions.turnOffFan = true;
                        
                        systemState = FAN_TURNING_OFF;
                    }
                    else if (events.OnGetOverTemperature)
                    {
                        actions.turnOnFan = false;
                        actions.turnOffFan = true;
                        
                        systemState = FAN_TURNING_OFF;
                    }
                    else if (events.OnGetUnderTemperture)
                    {
                        //NO ACTIONS
                        actions.openWindow = true;
                        actions.closeWindow = false;
                        //NEXT STATE
                        systemState = WINDOW_CLOSING;
                    }
                    
                break;
                ////////////////////////
                case WINDOW_CLOSING:
                    if (events.OnWindowClosed) {
                        //ACTIONS
                        actions.openWindow = false;
                        actions.closeWindow = true;
                        //NEXT STATE
                        systemState = WINDOW_CLOSED;
                    }
                break;

                case WINDOW_CLOSED :
                    if (events.OnGetTargetTemperature) {
                        
                        actions.turnOnFan = false;
                        actions.turnOffFan = true;
                        
                        systemState = FAN_TURNING_OFF;
                    }
                    else if (events.OnGetOverTemperature)
                    {
                        actions.turnOnFan = false;
                        actions.turnOffFan = true;
                        
                        systemState = FAN_TURNING_OFF;
                    }
                    else if (events.OnGetUnderTemperture)
                    {
                        //ACITONS 
                        actions.turnOnFan = true;
                        actions.turnOffFan = false;
                        //NEXT STATE
                        systemState = FAN_TURNING_ON;
                    }
                break;
                ///////////////////////
                case FAN_TURNING_ON:
                    if (events.OnFanTurnedOn) {
                        //ACITONS 
                        actions.turnOnFan = false;
                        actions.turnOffFan = false;
                        //NEXT STATE
                        systemState = FAN_TURNED_ON;
                    }
                break;

                case FAN_TURNED_ON:
                    if (events.OnGetTargetTemperature && events.OnWindowOpened) {
                        actions.openWindow = false;
                        actions.closeWindow = true;
                        systemState = WINDOW_CLOSING;
                    }
                    else if (events.OnGetTargetTemperature && events.OnWindowClosed)
                    {
                        actions.turnOnFan = false;
                        actions.turnOffFan = true;
                        systemState = FAN_TURNING_OFF;
                    }
                    
                break;
                ////////////////////////////////
                case FAN_TURNING_OFF:
                    if (events.OnFanTurnedOff) {
                        //ACITON 
                        actions.turnOnFan = false;
                        actions.turnOffFan = false;
                        //NEXT STATE
                        systemState = FAN_TURNED_OFF;
                    }
                break;

                case FAN_TURNED_OFF:
                    if (events.OnGetTargetTemperature && events.OnWindowOpened) {
                        actions.openWindow = false;
                        actions.closeWindow = true;
                        systemState = WINDOW_CLOSING;
                    }
                    else if (events.OnGetTargetTemperature && events.OnWindowClosed)
                    {
                        //ACTIONS
                        actions.turnOnFan = false;
                        actions.turnOffFan = true;
                        //NEXT STATE
                        systemState = AMBIANT_ENVIRONMENT;
                    }
                break;
                //////////////////////////////
                case AMBIANT_ENVIRONMENT:
                    if (events.OnGetTargetTemperature && events.OnWindowOpened) {
                        actions.openWindow = false;
                        actions.closeWindow = true;
                        systemState = WINDOW_CLOSING;
                    }
                    else if (events.OnGetTargetTemperature && events.OnWindowClosed)
                    {
                        //ACTIONS
                        actions.turnOnFan = false;
                        actions.turnOffFan = true;
                        //NEXT STATE
                        systemState = AMBIANT_ENVIRONMENT;
                    }
                break;
                
            }

        break;

        case MODE_MANUAL:
            Serial.println("you're in the manual mode ");
            if(events.OnAutoModeBtnClicked == is_auto_mode_btn_clicked)   systemMode = MODE_AUTOMATIC;
            Serial.println(vanneHandler.getVanneStatus());
            if (events.OnOpenVanneBtnClicked){
                actions.OpenVanne = true;
                actions.CloseVanne = false;
                Serial.println("vanne Is oN ");
            }     
            else if (events.OnCloseVanneBtnClicked){
                actions.OpenVanne = false;
                actions.CloseVanne = true;
                Serial.println("vanne Is oFF ");
            }    
        
        break;
    }    
}

void AirConditioningSystem::updateActions()
{
    
}

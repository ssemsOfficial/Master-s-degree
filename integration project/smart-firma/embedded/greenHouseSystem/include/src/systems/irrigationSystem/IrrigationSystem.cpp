#include<Arduino.h>
#include"IrrigationSystem.h"


void IrrigationSystem::init(){
    vanne->init();
    soilMoisture->init();
}

void IrrigationSystem::updateEvents(){
    events.soilMoistureValue = soilMoistureHandler.getMoistureData();
    if(events.soilMoistureValue <= SOIL_DRIED_VALUE){
        events.OnSoilDried = true;
        events.OnSoilHumidified = false;
    }
    else if(events.soilMoistureValue >= SOIL_HUMIDIFIED_VALUE)
    {
        events.OnSoilDried = false;
        events.OnSoilHumidified = true;
    }
    if(vanneHandler.getVanneStatus() == VANNE_IS_OPENED){
        events.OnVanneOpened = true;
        events.OnVanneClosed = false;
    }
    else if(vanneHandler.getVanneStatus() == VANNE_IS_CLOSED){
        events.OnVanneOpened = false;
        events.OnVanneClosed = true;
    }
    if(digitalRead(13) == 1){
        events.OnManModeBtnClicked = true;
        events.OnAutoModeBtnClicked = false;
    }
    else if(digitalRead(13) == 0){
        events.OnManModeBtnClicked = false;
        events.OnAutoModeBtnClicked = true;
    }
    if(digitalRead(12) == HIGH){
        Serial.println("open event is cliced right now_ ");
        events.OnOpenVanneBtnClicked = true;
        events.OnCloseVanneBtnClicked = false;
    }
    else if(digitalRead(14) == HIGH){
        Serial.println("close event is cliced right now_ ");
        events.OnOpenVanneBtnClicked = false;
        events.OnCloseVanneBtnClicked = true;
    }
}

void IrrigationSystem::FSM_IrrigationSystem(){
    switch (systemMode) {

        case MODE_AUTOMATIC:
            Serial.println("you're in the automatic mode ");
            if (events.OnManModeBtnClicked == is_man_mode_btn_clicked){
                systemMode = MODE_MANUAL;
            }
            switch (systemState) {

                case SOIL_HUMIDING:
                    Serial.println("soil is humiding ");
                    if (events.OnSoilHumidified) {
                        actions.OpenVanne = false;
                        actions.CloseVanne = true;
                        systemState = SOIL_HUMIDIFIED;
                    }
                break;

                case SOIL_HUMIDIFIED:
                    Serial.println("soil is humidified ");
                    if (events.OnSoilHumidified) {
                        actions.OpenVanne = false;
                        actions.CloseVanne = true;
                        systemState = SOIL_DRYING;
                    }
                break;

                case SOIL_DRYING:
                    Serial.println("soil is drying ");
                    if (events.OnSoilDried) {
                        actions.OpenVanne = true;
                        actions.CloseVanne = false;
                        systemState = SOIL_DRYED;
                    }
                break;

                case SOIL_DRYED:
                    Serial.println("soil is dried ");
                    if (events.OnSoilDried) {
                        actions.OpenVanne = true;
                        actions.CloseVanne = false;
                        systemState = SOIL_HUMIDING;
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

void IrrigationSystem::updateActions(){
    if(actions.OpenVanne == true){
        vanneHandler.turnVanneOn();
    }
    else if(actions.CloseVanne == true){
        vanneHandler.turnVanneOff();
    }
}



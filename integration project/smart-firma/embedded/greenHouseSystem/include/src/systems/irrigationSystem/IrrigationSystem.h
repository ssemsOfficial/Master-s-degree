#ifndef IRRIGATIONSYSTEM_H
#define IRRIGATIONSYSTEM_H

//handlers
#include <src/handlers/HandleVanneControl/HandleVanneControl.h>
#include <src/handlers/HandleSoilMoiture/HandleSoilMoiture.h">

//components
#include <src/components/vanne/IVanne.h>
#include <src/components/vanne/VanneImp.h>
#include <src/components/soilMoiture/ISoilMoiture.h>
#include <src/components/soilMoiture/SoilMoitureImp.h>


#define IRRIGATION_SYSTEM_MODE_AUTO true
#define IRRIGATION_SYSTEM_MODE_MAN false
#define SOIL_DRIED_VALUE 10
#define SOIL_IS_DRIED true
#define SOIL_IS_NOT_DRIED false
#define SOIL_IS_HUMIDIFIED true
#define SOIL_IS_NOT_HUMIDIFIED false
#define SOIL_HUMIDIFIED_VALUE 100
#define is_man_mode_btn_clicked true
#define is_auto_mode_btn_clicked true


class IrrigationSystem
{
private:

    struct SystemEvents
    {
        bool OnSoilDried = false;
        bool OnSoilHumidified = false;
        bool OnVanneOpened = false;
        bool OnVanneClosed = false;
        bool OnOpenVanneBtnClicked = false;
        bool OnCloseVanneBtnClicked = false;
        bool OnManModeBtnClicked = false;
        bool OnAutoModeBtnClicked = false;
        int soilMoistureValue = 0;
        int prevSoilMoistureValue = 0;
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
        SOIL_DRYED,
        SOIL_DRYING,
        SOIL_HUMIDIFIED,
        SOIL_HUMIDING,
        VANNE_OPENED,
        VANNE_CLOSED
    };
    SystemStates systemState = SOIL_HUMIDIFIED;  

    struct SystemActions  // les sorties de systeme
    {
        bool OpenVanne = 0;
        bool CloseVanne = 0;
    };
    SystemActions actions;

    
    IVanne* vanne;
    HandleVanneControl vanneHandler;

    ISoilMoiture* soilMoisture;
    HandleSoilMoiture soilMoistureHandler;

public:
    IrrigationSystem(int vannePin, int soilMoisturePin):
      vanne(new VanneImp(vannePin)),
      vanneHandler(vanne),
      soilMoisture(new SoilMoitureImp(soilMoisturePin)),
      soilMoistureHandler(soilMoisture)
    {   }
    ~IrrigationSystem()
    {
       vanneHandler.~HandleVanneControl();
       soilMoistureHandler.~HandleSoilMoiture(); 
    }
    void init();
    void updateEvents();
    void FSM_IrrigationSystem();
    void updateActions();
};

#endif
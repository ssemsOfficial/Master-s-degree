#ifndef HANDLEVANNECONTROL.H
#define HANDLEVANNECONTROL.H

#include "components/vanne/IVanne.h"

#define VANNE_IS_OPENED true
#define VANNE_IS_NOT_OPENED false
#define VANNE_IS_CLOSED false
#define VANNE_IS_NOT_CLOSED false

class HandleVanneControl
{
private:
    IVanne* vanne;
    /* IVanne* vanne = new VanneImp(VANNE_PIN);*/
    bool vanneStatus;
public:
    HandleVanneControl()
    {}
    HandleVanneControl(IVanne* vanne):
     vanne(vanne)
    {}
    ~HandleVanneControl()
    {
        delete vanne;
    }
    bool getVanneStatus();
    void setVanneStatus(bool vanneStatus);
    void turnVanneOn();
    void turnVanneOff();
};


#endif












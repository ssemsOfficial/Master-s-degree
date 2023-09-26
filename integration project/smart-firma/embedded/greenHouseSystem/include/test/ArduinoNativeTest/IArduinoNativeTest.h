#ifndef IArduinoNativeTest
#define IArduinoNativeTest

class IArduinoNativeTest
{
private:
    /* data */
public:
    
    virtual void pinMode(int pin, int mode)=0;

    virtual void digitalWrite(int pin, int value)=0;
    
    virtual void delayMicroseconds(int delay)=0;
    
    virtual int digitalRead(int pin)=0;

};





#endif
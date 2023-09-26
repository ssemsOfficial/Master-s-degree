
#ifndef IRELAY_H
#define IRELAY_H

#ifdef UNIT_TEST
    #include <test/ArduinoNativeTest/ArduinoNativeTest.h>
#else
    #include <test/ArduinoNativeTest/ArduinoNativeTest.h>
#endif

class IRelay {
public: 
         IRelay(){}    
virtual ~IRelay() = default;
    
virtual void init() = 0;
    
virtual void on() = 0;
    
virtual void off() = 0;
};

#endif 
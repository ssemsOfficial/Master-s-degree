
#ifndef ARDUINONATIVETEST_H
#define ARDUINONATIVETEST_H

#include<stdint.h>
#include<string.h>
using namespace std;

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define INPUT_PULLDOWN 0x3

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define IS_CALLED true
#define IS_NOT_CALLED false

namespace ArduinoUnitTest{

    struct ArduinoFuncHandler{
        //
        bool isPinModeCalled = IS_NOT_CALLED;
        int countIsPinModeCalled = 0;
        void pinModeCall(){
            isPinModeCalled = IS_CALLED;
            countIsPinModeCalled++;
        }
        
        bool isDigitalWriteCalled = IS_NOT_CALLED;
        int countIsDigitalWriteCalled = 0;
        void DigitalWriteCall(){
            isDigitalWriteCalled = IS_CALLED;
            countIsDigitalWriteCalled++;
        }

        bool isDigitalReadCalled = IS_NOT_CALLED;
        int countIsDigitalReadCalled = 0;
        void DigitalReadCall(){
            isDigitalReadCalled = IS_CALLED;
            countIsDigitalReadCalled++;
        }

        bool isDelayCalled = IS_NOT_CALLED;
        int countIsDelayCalled = 0;
        void DelayCall(){
            isDelayCalled = IS_CALLED;
            countIsDelayCalled++;
        }

        
        bool isDelayMicrosecondsCalled = IS_NOT_CALLED;
        int countIsDelayMicrosecondsCalled = 0;
        void DelayMicrosecondsCall(){
            isDelayMicrosecondsCalled = IS_CALLED;
            countIsDelayMicrosecondsCalled++;
        }
        
        void Reset(){
            isPinModeCalled = IS_NOT_CALLED;
            countIsPinModeCalled = 0;
            isDigitalWriteCalled = IS_NOT_CALLED;
            countIsDigitalWriteCalled = 0;
            isDigitalReadCalled = IS_NOT_CALLED;
            countIsDigitalReadCalled = 0;
            isDelayCalled = IS_NOT_CALLED;
            countIsDelayCalled = 0;
            isDelayMicrosecondsCalled = IS_NOT_CALLED;
            countIsDelayMicrosecondsCalled = 0;
        }
    };
    ArduinoFuncHandler arduinoFuncHandler;

    struct ArduinoStates{
        uint8_t digitalPinState[128];
        uint8_t digitalPinMode[128];
        int delayMicrosecondsValue = 0;
        int delayValue = 0;
    };
    ArduinoStates arduinoStates;
    
    class FakeSerial
    {
    private:
        int baud;
    public:
        FakeSerial(){}
        ~FakeSerial(){}
        
        void begin(int baud){
            this->baud = baud;
        }
        int getBaud(){
            return baud;
        } 
        void println(string text){

        }

    };
    FakeSerial Serial;

    void  pinMode(int pin, int mode){
        
        arduinoStates.digitalPinMode[pin] = mode;
        arduinoFuncHandler.pinModeCall();
    }
    int getPinMode(int pin){
        return arduinoStates.digitalPinMode[pin];
    }
    void delay(int delay) {
        arduinoStates.delayValue = delay;
        arduinoFuncHandler.DelayCall();     
    }
    int getDelay(int delay){
        return arduinoStates.delayValue;   
    } 
    void delayMicroseconds(int delay){
        arduinoStates.delayMicrosecondsValue = delay;
        arduinoFuncHandler.DelayMicrosecondsCall();
    } 
    int getDelayMicroseconds(){
        return arduinoStates.delayMicrosecondsValue;
    }
    int  digitalRead(int pin) {
        arduinoFuncHandler.DigitalReadCall();
        return arduinoStates.digitalPinState[pin];
    } 
    void digitalWrite(int pin, int value){
        arduinoStates.digitalPinState[pin] = value;
        arduinoFuncHandler.DigitalWriteCall();
    }

}
#endif

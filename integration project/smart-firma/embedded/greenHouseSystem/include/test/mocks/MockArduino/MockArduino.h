

#ifndef MOCKARDUINO_H
#define MOCKARDUINO_H
#include <stdint.h>
#include <iostream>
#include <gmock/gmock.h>

#include <test/ArduinoNativeTest/ArduinoNativeTest.h>


//Mock class for Arduino functions
class MockArduino  : public ArduinoNativeTest{
public:

    MOCK_METHOD(void, pinMode, (int, int));
    MOCK_METHOD(void, digitalWrite, (int, int));
    MOCK_METHOD(void, delayMicroseconds, (unsigned int));

};


#endif
#ifndef RELAY_TEST_H
#define RELAY_TEST_H


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <src/components/relay/RelayImp.cpp>

/********************* TEST IRelay  *******************************/
class MockIRelay : public IRelay {
public:
    
    MOCK_METHOD(void, init, (), (override));
    MOCK_METHOD(void, on, (), (override));
    MOCK_METHOD(void, off, (), (override));

};

class IRelayTest : public ::testing::Test {
protected:
    MockIRelay mockIRelay;
    
};

TEST_F(IRelayTest, InitTest) {
    EXPECT_CALL(mockIRelay, init()); // Expect that init will be called

    mockIRelay.init();
}

TEST_F(IRelayTest, onTest) {
    EXPECT_CALL(mockIRelay, on()); // Expect setStepperPosition call
    
    mockIRelay.on();
}

TEST_F(IRelayTest, offTest) {
    int steps = 10;
    int direction = HIGH;
    
    EXPECT_CALL(mockIRelay, off()); // Expect setStepperPosition call
    mockIRelay.off();
}


/********************* TEST RelayImpTest  *******************************/
class RelayImpTest : public ::testing::Test {
protected:
    int pin = 1 ;
    RelayImp relayImp{pin};

};

TEST_F(RelayImpTest, initTest) {
  //action
  relayImp.init();
  //assert
  ASSERT_EQ(getPinMode(pin), OUTPUT);
  ASSERT_TRUE(arduinoFuncHandler.isPinModeCalled);
  ASSERT_EQ(arduinoFuncHandler.countIsPinModeCalled, 1);
  
  //reset
  arduinoFuncHandler.Reset();

}

TEST_F(RelayImpTest, onTest){
  relayImp.on();
  
  ASSERT_TRUE(arduinoFuncHandler.isDigitalWriteCalled);
  ASSERT_EQ(arduinoFuncHandler.countIsDigitalWriteCalled, 1);
  ASSERT_EQ(digitalRead(pin), RELAY_ON);

  arduinoFuncHandler.Reset();
  
}

TEST_F(RelayImpTest, offTest){
  relayImp.off();
  
  ASSERT_TRUE(arduinoFuncHandler.isDigitalWriteCalled);
  ASSERT_EQ(arduinoFuncHandler.countIsDigitalWriteCalled, 1);
  ASSERT_EQ(digitalRead(pin), RELAY_OFF);
  
  arduinoFuncHandler.Reset();
  
}



#endif
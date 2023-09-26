#ifndef STEPPERMOTORDRIVER_test_H
#define STEPPERMOTORDRIVER_test_H


#include <gtest/gtest.h>
#include <gmock/gmock.h>



#include "src/components/stepperMotorDriver/IStepperMotorDriver.h"
#include "src/components/stepperMotorDriver/StepperMotorDriverImp.cpp"


/********************* TEST IStepperMotorDriver  *******************************/
class MockStepperMotorDriver : public IStepperMotorDriver {
public:
    MockStepperMotorDriver():
        IStepperMotorDriver()    
    {}
    MOCK_METHOD(void, init, (), (override));
    MOCK_METHOD(void, setMotor, (int steps, int direction), (override));
};

class IStepperMotorDriverTest : public ::testing::Test {
protected:
    MockStepperMotorDriver mockStepperMotorDriver;
    
};

TEST_F(IStepperMotorDriverTest, InitTest) {
    EXPECT_CALL(mockStepperMotorDriver, init()); // Expect that init will be called

    mockStepperMotorDriver.init();
}

TEST_F(IStepperMotorDriverTest, SetStepperPositionTest) {
    int steps = 10;
    int direction = HIGH;
    
    EXPECT_CALL(mockStepperMotorDriver, setMotor(steps, direction)); // Expect setStepperPosition call
    mockStepperMotorDriver.setMotor(steps, direction);
}


/********************* TEST StepperMotorDriverTest  *******************************/
class StepperMotorDriverTest : public ::testing::Test {
protected:
    StepperMotorDriverImp motor{12, 13};

};

TEST_F(StepperMotorDriverTest, initTest) {
  //action
  motor.init();
  //assert
  ASSERT_EQ(getPinMode(12), OUTPUT);
  ASSERT_EQ(getPinMode(13), OUTPUT);
  ASSERT_TRUE(arduinoFuncHandler.isPinModeCalled);
  ASSERT_EQ(arduinoFuncHandler.countIsPinModeCalled, 2);
  
  //reset
  arduinoFuncHandler.Reset();

}

TEST_F(StepperMotorDriverTest, setMotorTest){
  
  int expected_delay = 2000;
  int dirPin = 13;
  int stepPin = 12;
  
  //first sense

  motor.setMotor(10, HIGH);
  
  ASSERT_TRUE(arduinoFuncHandler.isDigitalWriteCalled);
  ASSERT_EQ(arduinoFuncHandler.countIsDigitalWriteCalled, 21);
  ASSERT_EQ(digitalRead(stepPin), LOW);
  ASSERT_EQ(digitalRead(dirPin), HIGH);
  ASSERT_TRUE(arduinoFuncHandler.isDelayMicrosecondsCalled);
  ASSERT_EQ(arduinoFuncHandler.countIsDelayMicrosecondsCalled, 20);
  ASSERT_EQ(getDelayMicroseconds(), expected_delay);
  
  
  arduinoFuncHandler.Reset();
  
  //first sense

  motor.setMotor(10, LOW);
  
  ASSERT_TRUE(arduinoFuncHandler.isDigitalWriteCalled);
  ASSERT_EQ(arduinoFuncHandler.countIsDigitalWriteCalled, 21);
  ASSERT_EQ(digitalRead(stepPin), LOW);
  ASSERT_EQ(digitalRead(dirPin), LOW);
  ASSERT_TRUE(arduinoFuncHandler.isDelayMicrosecondsCalled);
  ASSERT_EQ(arduinoFuncHandler.countIsDelayMicrosecondsCalled, 20);
  ASSERT_EQ(getDelayMicroseconds(), expected_delay);
  
  arduinoFuncHandler.Reset();
}



#endif
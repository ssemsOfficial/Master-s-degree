#ifndef MOTOR_test_H
#define MOTOR_test_H


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <src/components/motor/IMotor.h>
#include <src/components/motor/MotorImp.cpp>


/************************ TEST IMotor **************************/
class MockIMotor : public IMotor {
public:
    
    MOCK_METHOD(void, init, (), (override));
    MOCK_METHOD(void, turnOn, (), (override));
    MOCK_METHOD(void, turnOff, (), (override));
};

class IMotorTest : public ::testing::Test {
protected:
    MockIMotor mockIMotor;
};

TEST_F(IMotorTest, InitTest) {
    EXPECT_CALL(mockIMotor, init());
    mockIMotor.init();
}

TEST_F(IMotorTest, turnOnTest) {
    
    EXPECT_CALL(mockIMotor, turnOn()); 
    mockIMotor.turnOn();
}

TEST_F(IMotorTest, turnOffTest) {
    
    EXPECT_CALL(mockIMotor, turnOff());
    mockIMotor.turnOff();
}

/************************ TEST StepperMotorImp **************************/
struct RelayMockStates{
    bool initSuccessState = false;
    bool turnOnSuccessState = false;
    bool turnOffSuccessState = false;
};
RelayMockStates relayMockStates; 

class RelayMock : public IRelay
{
private:
    
public:
    RelayMock(){}
    ~RelayMock(){}
    
    void init() override { relayMockStates.initSuccessState = true; }
    void on() override { relayMockStates.turnOnSuccessState = true;}
    void off() override { relayMockStates.turnOffSuccessState = true;}
};
class MotorImpTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST(MotorImpTest, InitTest) {
    IRelay* relayMock = new RelayMock();
    MotorImp motorImp(relayMock);
    motorImp.init();
    ASSERT_EQ(relayMockStates.initSuccessState, true);
}
TEST(MotorImpTest, turnOnTest) {
    IRelay* relayMock = new RelayMock();
    MotorImp motorImp(relayMock);
    motorImp.turnOn();
    ASSERT_EQ(relayMockStates.turnOnSuccessState, true);
}
TEST(MotorImpTest, turnOffTest) {
    IRelay* relayMock = new RelayMock();
    MotorImp motorImp(relayMock);
    motorImp.turnOff();
    ASSERT_EQ(relayMockStates.turnOffSuccessState, true);
}

#endif
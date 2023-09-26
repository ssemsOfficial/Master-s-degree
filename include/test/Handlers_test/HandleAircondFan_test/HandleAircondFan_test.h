#ifndef HANDLEAIRCONDFAN_TEST_H
#define HANDLEAIRCONDFAN_TEST_H

// Include necessary headers for your test framework (e.g., gtest/gmock)
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "src/handlers/HandleAircondFan/HandleAirCondFan.cpp" // Replace with the actual path


struct MotorMockStates {
    bool initState = false;
    bool turnOnState = false;
    bool turnOffState = false;
};

MotorMockStates motorMockStates;

class MotorMock : public IMotor {
public:
    MotorMock() {}
    ~MotorMock() {}

    void init() override { motorMockStates.initState = true; }
    void turnOn() override { motorMockStates.turnOnState = true; }
    void turnOff() override { motorMockStates.turnOffState = true; }
};

TEST(HandleAirCondFanTest, get_set_FanStatus) {
    IMotor* motorMock = new MotorMock();
    HandleAirCondFan handleAirCondFan(motorMock);

    bool result;

    handleAirCondFan.setFanStatus(FAN_IS_TURNNED_ON);
    result = handleAirCondFan.getFanStatus();
    ASSERT_EQ(result, FAN_IS_TURNNED_ON);

    handleAirCondFan.setFanStatus(FAN_IS_TURNNED_OFF);
    result = handleAirCondFan.getFanStatus();
    ASSERT_EQ(result, FAN_IS_TURNNED_OFF);

}
TEST(HandleAirCondFanTest, TurnOnFanTest) {
    IMotor* motorMock = new MotorMock();
    HandleAirCondFan handleAirCondFan(motorMock);

    bool resultFanStatus;
    handleAirCondFan.turnOnFan();
    resultFanStatus = handleAirCondFan.getFanStatus();

    ASSERT_EQ(resultFanStatus, FAN_IS_TURNNED_ON);
    ASSERT_EQ(motorMockStates.turnOnState, true);
}


TEST(HandleAirCondFanTest, TurnOffFanTest) {
    IMotor* motorMock = new MotorMock();
    HandleAirCondFan handleAirCondFan(motorMock);

    bool resultFanStatus;
    handleAirCondFan.turnOffFan();
    resultFanStatus = handleAirCondFan.getFanStatus();

    ASSERT_EQ(resultFanStatus, FAN_IS_TURNNED_OFF);
    ASSERT_EQ(motorMockStates.turnOffState, true);
}


#endif
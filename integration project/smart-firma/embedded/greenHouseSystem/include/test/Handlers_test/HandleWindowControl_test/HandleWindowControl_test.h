#ifndef HANDLEWINDOWCONTROL_TEST_H
#define HANDLEWINDOWCONTROL_TEST_H


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <src/handlers/HandleWindowControl/HandleWindowControl.cpp>


struct StepperMotorMockStates{
    bool initState = false;
    bool setStepperPositionState = false;
};
StepperMotorMockStates stepperMotorMockStates; 

class StepperMotorMock : public IStepperMotor
{
private:
    
public:
    StepperMotorMock(){}
    ~StepperMotorMock(){}
    
    void init() override { stepperMotorMockStates.initState = true; }
    void setStepperPosition(int steps, int direction) override { stepperMotorMockStates.setStepperPositionState = true;}
};

TEST(HandleWindowControlTest, get_set_WindowStatus) {
    IStepperMotor* stepperMotorMock = new StepperMotorMock();
    HandleWindowControl handleWindowControl(stepperMotorMock);
    
    bool result;

    handleWindowControl.setWindowStatus(WINDOW_IS_OPENED);
    result = handleWindowControl.getWindowStatus();
    ASSERT_EQ(result, WINDOW_IS_OPENED);

    handleWindowControl.setWindowStatus(WINDOW_IS_CLOSED);
    result = handleWindowControl.getWindowStatus();
    ASSERT_EQ(result, WINDOW_IS_CLOSED);
}


TEST(HandleWindowControlTest, OpenWindowTest) {
    IStepperMotor* stepperMotorMock = new StepperMotorMock();
    HandleWindowControl handleWindowControl(stepperMotorMock);
    
    bool resultWindowStatus;
    handleWindowControl.openWindow();
    resultWindowStatus = handleWindowControl.getWindowStatus();
    
    ASSERT_EQ(resultWindowStatus, WINDOW_IS_OPENED);
    ASSERT_EQ(stepperMotorMockStates.setStepperPositionState, true);
}


TEST(HandleWindowControlTest, CloseWindowTest) {
    IStepperMotor* stepperMotorMock = new StepperMotorMock();
    HandleWindowControl handleWindowControl(stepperMotorMock);
    
    bool resultWindowStatus;
    handleWindowControl.closeWindow();
    resultWindowStatus = handleWindowControl.getWindowStatus();
    
    ASSERT_EQ(resultWindowStatus, WINDOW_IS_CLOSED);
    ASSERT_EQ(stepperMotorMockStates.setStepperPositionState, true);
}


#endif

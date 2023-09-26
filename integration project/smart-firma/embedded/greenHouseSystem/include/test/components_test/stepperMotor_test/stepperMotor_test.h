#ifndef STEPPERMOTOR_test_H
#define STEPPERMOTOR_test_H


#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include <src/components/stepperMotor/StepperMotorImp.cpp>



/*

TEST(IStepperMotorDriverTest, SetStepperPositionTest) {
    Mock<IStepperMotorDriver> mock;
    IStepperMotorDriver* mock = ArduinoFakeMock(IStepperMotorDriver);
    When(Method(mock, init)).AlwaysReturn();
    StepperMotorImp motor(mock);
    
    motor.init();


}

*/



/************************ TEST IStepperMotor **************************/
class MockIStepperMotor : public IStepperMotor {
public:
    
    MOCK_METHOD(void, init, (), (override));
    MOCK_METHOD(void, setStepperPosition, (int steps, int direction), (override));
};

class IStepperMotorTest : public ::testing::Test {
protected:
    MockIStepperMotor mockIStepperMotor;

};

TEST_F(IStepperMotorTest, InitTest) {
    EXPECT_CALL(mockIStepperMotor, init()); // Expect that init will be called
    mockIStepperMotor.init();
}

TEST_F(IStepperMotorTest, SetStepperPositionTest) {
    int steps = 10;
    int direction = HIGH;
    
    EXPECT_CALL(mockIStepperMotor, setStepperPosition(steps, direction)); // Expect setStepperPosition call
    mockIStepperMotor.setStepperPosition(steps, direction);
}

/************************ TEST StepperMotorImp **************************/

struct StepperMotorDriverMockStates{
    bool initSuccessState = false;
    bool setMotorSuccessState = false;
};
StepperMotorDriverMockStates stepperMotorDriverMockStates; 

class StepperMotorDriverMock : public IStepperMotorDriver
{
private:
    
public:
    StepperMotorDriverMock(){}
    ~StepperMotorDriverMock(){}
    
    void init() override { stepperMotorDriverMockStates.initSuccessState = true; }
    void setMotor(int steps, int direction) override { stepperMotorDriverMockStates.setMotorSuccessState = true;}
};
 


class StepperMotorImpTest : public ::testing::Test {
protected:
    int hell;
    //StepperMotorImp stepperMotorImp = stepperMotorImpPtr;
    void SetUp() override {
            
    }

    void TearDown() override {
        
    }
};

TEST(StepperMotorImpTest, InitTest) {
    IStepperMotorDriver* stepperMotorDriverMock = new StepperMotorDriverMock();
    StepperMotorImp stepperMotorImp(stepperMotorDriverMock);
    stepperMotorImp.init();
    ASSERT_EQ(stepperMotorDriverMockStates.initSuccessState, true);
}

TEST(StepperMotorImpTest, SetStepperPositionTest) {
    IStepperMotorDriver* stepperMotorDriverMock = new StepperMotorDriverMock();
    StepperMotorImp stepperMotorImp(stepperMotorDriverMock);
    stepperMotorImp.setStepperPosition(10, HIGH);
    ASSERT_EQ(stepperMotorDriverMockStates.setMotorSuccessState, true);
}
/*
TEST(StepperMotorImpTest, SetStepperTest) {
    IStepperMotorDriver* stepperMotorDriverMock = new StepperMotorDriverMock();
    StepperMotorImp stepperMotorImp(stepperMotorDriverMock);
    stepperMotorImp.setStepperPosition(10, HIGH);
    ASSERT_EQ(stepperMotorDriverMockStates.setMotorSuccessState, true);
}
*/

/*
TEST_F(StepperMotorImpTest, SetStepperPositionTest) {
    int steps = 10;
    int direction = HIGH;
    
    EXPECT_CALL(mockIStepperMotor, setStepperPosition(steps, direction)); // Expect setStepperPosition call
    mockIStepperMotor.setStepperPosition(steps, direction);
}
*/

/*
TEST_F(IStepperMotorTest, Testability){
    MockStepperMotorDriver mockDriver;
    MockStepperMotorDriver* mockDriverPtr = &mockDriver ;
    IStepperMotorDriver* MockStepperMotorDriverPtr = mockDriverPtr;
    StepperMotorImp stepperMotorUnderTest{MockStepperMotorDriverPtr};
    //StepperMotorImp stepperMotorUnderTest2{12,13};
    //EXPECT_CALL(mockDriver, init());
    stepperMotorUnderTest.init();

    //stepperMotorUnderTest2.init();  
    //ASSERT_EQ(fakeArduino.getPinMode(12), OUTPUT);
    //ASSERT_EQ(fakeArduino.getPinMode(13), OUTPUT);
  
    ASSERT_EQ("",""); 
}
*/


/*
TEST(StepperMotorImpTest, InitTest) {
    MockStepperMotorDriver mockDriver;
    StepperMotorImp stepperMotorUnderTest{&mockDriver};
    
    EXPECT_CALL(mockDriver, init()); // Expect that init will be called on the mock driver
    //stepperMotorUnderTest.init();
    //stepperMotorUnderTest.init();
}
TEST_F(StepperMotorImpTest, SetStepperPositionTest) {
    int steps = 10;
    int direction = HIGH;

    EXPECT_CALL(mockDriver, setMotor(steps, direction)); // Expect setMotor call on the mock driver
    stepperMotorUnderTest.setStepperPosition(steps, direction);
}
*/

/*class MockStepperMotorDriver : public StepperMotorDriverImp {
 public:
    MOCK_METHOD(void, init, ());
    MOCK_METHOD(void, setMotor, (int, int));
};

class StepperMotorImpTest : public ::testing::Test {
 protected:
    MockStepperMotorDriver mockStepperMotorDriver(); 
    StepperMotorImp stepperMotor;
    StepperMotorImp(&mockStepperMotorDriver);
    ArduinoNativeTest fakeArduino;


    StepperMotorImpTest()
    {}

};

TEST_F(StepperMotorImpTest, InitTest){
    
    //EXPECT_CALL(mockStepperMotorDriver, init());
    
    //stepperMotor.init();
    ASSERT_EQ("","");
}
*/


/*
TEST_F(StepperMotorImpTest, InittTest) {

    stepperMotorImp.init();
}
*/
/*
class MockStepperMotorDriver : public StepperMotorDriver {
public:
    MOCK_METHOD(void, init, ());
    MOCK_METHOD(void, setMotor, (int, int));
};


TEST_F(StepperMotorImpTest, InitTest) {
    EXPECT_CALL(mockStepperMotorDriver, init()); // Expect that init will be called
    stepperMotorImp.init();
}
*/



#endif
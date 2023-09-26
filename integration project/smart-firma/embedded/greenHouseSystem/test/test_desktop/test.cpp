#include <gtest/gtest.h>
//#include <gmock/gmock.h>
//#include <fakeit/DefaultFakeit.hpp>
//using namespace fakeit;

#include <test/components_test/stepperMotorDriver/StepperMotorDriver_test.h>
#include <test/components_test/stepperMotor_test/stepperMotor_test.h>
#include <test/components_test/relay_test/relay_test.h>
#include <test/components_test/motor_test/motor_test.h>

#include <test/Handlers_test/HandleWindowControl_test/HandleWindowControl_test.h>
#include <test/Handlers_test/HandleAircondFan_test/HandleAircondFan_test.h>

int main(int argc, char** argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}




#ifdef UNIT_TEST
    #include "ArduinoFake.h"
#else
    #include "Arduino.h"
#endif

//#include "components/stepperMotor/IStepperMotor.h"
//#include "components/stepperMotor/StepperMotorImp.h"


#define STEP_PIN 2
#define DIR_PIN 15


void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop(){
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_BUILTIN, HIGH);
    // wait for a second
    delay(100);
    // turn the LED off by making the voltage LOW
    digitalWrite(LED_BUILTIN, LOW);
     // wait for a second
    delay(100);
  /**irrigationSystem.updateEvents();**/
  /*airConditioningSystem.updateEvents  **/
    

  /**irrigationSystem.FSM_IrrigationSystem();*/
  /*airConditioningSystem.FSM_AirConditioningSystem  **/
    
    
  /*irrigationSystem.updateActions();*/
  /*airConditioningSystem.updateActions **/
}


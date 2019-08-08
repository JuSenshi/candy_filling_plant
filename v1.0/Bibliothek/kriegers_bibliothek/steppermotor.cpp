 /* steppermotor.cpp
 * Part of the library "krieger"
 * steppermotor.h and steppermotor.cpp include methods to control a stepper motor
 * Created by Julian Krieger
 */

 #include <Arduino.h>
 #include "steppermotor.h"
 #include <SPI.h>

 const int motor_state[4] = {0b00000101, 0b00001001, 0b00001010, 0b00000110};
 const int motor_delay = 2;
int _L1;
int _L2;
int _L3;
int _L4;

// L3 and L2 are swapped intentionally. Most of the cables are swapped on hardware
// Parameter (IN1, IN2, IN3, IN4)
 void steppermotor::initialize(int L1, int L3, int L2, int L4){
	 pinMode(L1, OUTPUT);
	 pinMode(L2, OUTPUT);
	 pinMode(L3, OUTPUT);
	 pinMode(L4, OUTPUT);
	 _L1 = L1;
	 _L2 = L2;
	 _L3 = L3;
	 _L4 = L4;
	}

   void steppermotor::motor_steps(uint8_t value, int _L1, int _L2, int _L3, int _L4){
	digitalWrite(_L1, value & 0b00000001);
	digitalWrite(_L2, value & 0b00000010);
	digitalWrite(_L3, value & 0b00000100);
	digitalWrite(_L4, value & 0b00001000);
 }
 void steppermotor::forward(){
	 for (int i = 0; i < 4; i++){
		motor_steps(motor_state[i], _L1, _L2, _L3, _L4);
		delay(motor_delay);
	 }
 }

 void steppermotor::backward(){
	 for(int i = 3; i >= 0; i--){
		motor_steps(motor_state[i], _L1, _L2, _L3, _L4);
		delay(motor_delay);
	 }
 }

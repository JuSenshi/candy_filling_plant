 /* steppermotor.cpp
 * Part of the library "krieger"
 * steppermotor.h and steppermotor.cpp include methods to control a stepper motor
 * Created by Julian Krieger
 */
 
 #ifndef steppermotor_h
 #define steppermotor_h
 #include "Arduino.h"
 
 
 
 class steppermotor{
	 public:
		///Declares needed PINs for the hardware
		///Parameters: Arduino PINs (digital) in following order: IN1, IN2, IN3, IN4
		static void initialize(int L1, int L2, int L3, int L4);
		
		///Moves the motor clockwise("forward")
		static void forward(); 
		
		///Moves the motor counter clockwise ("backward")
		static void backward();	
		
		///Used in forward/backward methods to actually control the PINs
		static void motor_steps(uint8_t value, int L1, int L2, int L3, int L4);
 };
 #endif
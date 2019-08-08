/* ultrasonic.cpp
 * Part of the library "krieger"
 * ultrasonic.h and ultrasonic.cpp include methods for a ultrasonic arduino module
 * Created by Julian Krieger
 */
 
 #include <Arduino.h>
 #include "ultrasonic.h"

 uint8_t _trigger;
 uint8_t _echo;
 float pulse;
 
 void ultrasonic::initialize(uint8_t trigger, uint8_t echo){
	 pinMode(trigger, OUTPUT);
	 pinMode(echo, INPUT);
	 _trigger = trigger;
	 _echo = echo;

	}
	
   void ultrasonic::burst(){
	digitalWrite(_trigger, LOW); 
	delay(5); 
	digitalWrite(_trigger, HIGH); 
	delay(10);
	digitalWrite(_trigger, LOW);
 }
 void ultrasonic::read(){
	pulse = pulseIn(_echo, HIGH); 
 }
 float ultrasonic::convert(){
	 float distance = (pulse/2) * 0.03432;
	 return distance;
 }
 float ultrasonic::measure(){
	 ultrasonic::burst();
	 ultrasonic::read();
	 float measurement = ultrasonic::convert();
	 return measurement;
 }
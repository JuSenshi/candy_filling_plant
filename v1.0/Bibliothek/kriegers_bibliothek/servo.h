/* servo.h
 * Part of the library "krieger"
 * servo.h and servo.cpp include methods for the controls of a servo motor
 * Created by Julian Krieger
 */
 
 #ifndef servo_h
 #define servo_h
 #include "Arduino.h"
 
 
 
 class servo{
	 public:
	 
    /* Moves the motor to a position 
	Parameters: 
	1. Degree of Movement,
	2. Pin of the motor 
	3. Depends on Motor (Value of the loop) 
	*/
	static void move(byte angle_degree, uint8_t motor_pin, byte repeater);			
 };
 #endif

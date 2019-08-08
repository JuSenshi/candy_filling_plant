/* ultrasonic.h
 * Part of the library "krieger"
 * ultrasonic.h and ultrasonic.cpp include methods for a ultrasonic arduino module
 * Created by Julian Krieger
 */
 
 #ifndef ultrasonic_h
 #define ultrasonic_h
 #include "Arduino.h"
 
 
 
 class ultrasonic{
	public:
	 
	///Initializes the ultrasonic module 
	///Parameters: 1. trigger PIN, 2. echo PIN
	static void initialize(uint8_t trigger,uint8_t echo);
	
	///Sends the ultrasonic burst
	static void burst(); 
	
	///Measures the incoming echo and gives back the measured value
	static void read();
	
	///Converts the in measured echo from "read()" to a cm value and gives back this value
	static float convert();
	
	///Does "burst()", "read()" and "convert()" all in once and gives back the distance in cm
	static float measure();
 };
 #endif
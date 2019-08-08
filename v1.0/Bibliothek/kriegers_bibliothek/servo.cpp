/* servo.h
 * Part of the library "krieger"
 * servo.h and servo.cpp include methods for the controls of a servo motor
 * Created by Julian Krieger
 */

 #include <Arduino.h>
 #include "servo.h"

  void servo::move(byte angle_degree, uint8_t motor_pin, byte repeater){

    pinMode(motor_pin, OUTPUT);                       //Declares given pin of the servo as output
    int time = (angle_degree/180.0 * 1925) + 425;     //Calculates degree time for a SV-90
    int delaytime = 20000-time;
    for(int i = 0; i<repeater; i++){
      digitalWrite(motor_pin, HIGH);
		  delayMicroseconds(time);
		  digitalWrite(motor_pin, LOW);
		  delayMicroseconds(delaytime);
	  }
  }

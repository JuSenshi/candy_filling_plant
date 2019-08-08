/* 
 *  This code is essential for the clsoing mechanism. 
 * Copyright by Julian Krieger, Dennis Domagala, Pascal Gläß
 */

#include <servo.h>

const int top_motor = 2;
const int bottom_motor = 3;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A0, INPUT);
  servo::move(20, top_motor, 100);    // Ausgangsstellung
  servo::move(20, bottom_motor, 100);    // Ausgangsstellung
}

void loop() {
if (analogRead(A0) > 600){
  digitalWrite(A5, HIGH);
  schliessen();
  delay(100);
  digitalWrite(A5, LOW);
  while(analogRead(A0) > 600);
  }
}

void schliessen(){

  servo::move(150, top_motor, 100);   // Top Servo runter
  delay(500);
  servo::move(20, top_motor, 100);    // Top Servo zurück
  delay(500);
  servo::move(60, bottom_motor, 100);   // Side Servo runter
  delay(500);
  servo::move(20, bottom_motor, 100);    // Side Servo hoch
}

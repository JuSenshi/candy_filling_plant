/* 
 *  This code is essential for the clsoing mechanism. 
 * Copyright by Julian Krieger, Dennis Domagala, Pascal Gläß
 */


const int top_motor = 2;
const int bottom_motor = 3;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A0, INPUT);
  servo_move(20, top_motor, 100);    // Ausgangsstellung
  servo_move(20, bottom_motor, 100);    // Ausgangsstellung
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

  servo_move(150, top_motor, 100);   // Top Servo runter
  delay(500);
  servo_move(20, top_motor, 100);    // Top Servo zurück
  delay(500);
  servo_move(60, bottom_motor, 100);   // Side Servo runter
  delay(500);
  servo_move(20, bottom_motor, 100);    // Side Servo hoch
}


void servo_move(byte angle_degree, uint8_t motor_pin, byte repeater){

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

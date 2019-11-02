// Lieferroboter

//Pins deklarieren
const int forward_left = 3;
const int forward_right = 4;   
const int backward_left = 2;
const int backward_right = 5;  
const int sensor_left = A0;
const int sensor_right = A1;

//Richtung deklarieren
const int backward = 0b1100;
const int forward = 0b0011;
const int right = 0b1001;
const int left = 0b0110;
const int stop = 0b1111;

//Werte deklarieren
const int sensor_limit = 100;

void setup() {
  pinMode(forward_left,OUTPUT);
  pinMode(forward_right,OUTPUT);
  pinMode(backward_left,OUTPUT);
  pinMode(backward_right,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  //Beide über Grenzwert -> Vorwärts
  while(analogRead(sensor_left) <= sensor_limit && analogRead(sensor_right) <= sensor_limit){
    for(int i = 0; i<1; i++) 
      fahren(0b0000);
    fahren(forward);
    
  }
  //Links unter Grenzwert, rechts über Grenzwert -> Links
  while(analogRead(sensor_left) <= sensor_limit && analogRead(sensor_right) >= sensor_limit){
    for(int i = 0; i<1; i++) 
      fahren(0b0000);
      fahren(right);
  }
  //Links über Grenzwert, rechts unter Grenzwert -> Rechts
  while(analogRead(sensor_left) >= sensor_limit && analogRead(sensor_right) <= sensor_limit){
    for(int i = 0; i<1; i++) 
      fahren(0b0000);
    fahren(left);
  }
}

void fahren(uint8_t value){
 digitalWrite(backward_right, value&0b1000); 
 digitalWrite(backward_left, value&0b0100);
 digitalWrite(forward_right, value&0b0010);
 digitalWrite(forward_left, value&0b0001);   
  }

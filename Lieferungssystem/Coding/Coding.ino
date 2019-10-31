// Lieferroboter

//Pins deklarieren
const int links_vorwaerts = 3;
const int rechts_vorwaerts = 4;   
const int links_rueckwaerts = 2;
const int rechts_rueckwaerts = 5;  
const int sensor_links = A0;
const int sensor_rechts = A1;

//Richtung deklarieren
const int nachHinten = 0b1100;
const int nachVorne = 0b0011;
const int nachRechts = 0b1001;
const int nachLinks = 0b0110;
const int stoppen = 0b1111;

//Werte deklarieren
const int sensor_grenzwert = 100;



void setup() {
  pinMode(links_vorwaerts,OUTPUT);
  pinMode(rechts_vorwaerts,OUTPUT);
  pinMode(links_rueckwaerts,OUTPUT);
  pinMode(rechts_rueckwaerts,OUTPUT);
  Serial.begin(9600);
}
//Auf Linie = Unter Grenzwert
//Nicht auf Linie = Über Grenzwert
void loop() {
  
  //Beide über Grenzwert -> Vorwärts
  while(analogRead(sensor_links) <= sensor_grenzwert && analogRead(sensor_rechts) <= sensor_grenzwert){
    for(int i = 0; i<1; i++) 
      fahren(0b0000);
    fahren(nachVorne);
    
  }
  //Links unter Grenzwert, rechts über Grenzwert -> Links
  while(analogRead(sensor_links) <= sensor_grenzwert && analogRead(sensor_rechts) >= sensor_grenzwert){
    for(int i = 0; i<1; i++) 
      fahren(0b0000);
      fahren(nachRechts);
  }
  //Links über Grenzwert, rechts unter Grenzwert -> Rechts
  while(analogRead(sensor_links) >= sensor_grenzwert && analogRead(sensor_rechts) <= sensor_grenzwert){
    for(int i = 0; i<1; i++) 
      fahren(0b0000);
    fahren(nachLinks);
  }
}

void fahren(uint8_t value){
 digitalWrite(rechts_rueckwaerts, value&0b1000); 
 digitalWrite(links_rueckwaerts, value&0b0100);
 digitalWrite(rechts_vorwaerts, value&0b0010);
 digitalWrite(links_vorwaerts, value&0b0001);   
  }

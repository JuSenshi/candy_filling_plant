#include <SPI.h>                           // Integrates the SPI library for RFID pin support
#include <MFRC522.h>                       // Integrates RFID library for 15.44MHz NFC support
#define SS_PIN 10                          // Pin definition for the RFID library
#define RST_PIN 9                          // Pin definition for the RFID library
MFRC522 mfrc522(SS_PIN, RST_PIN);          // Applys given pins to library
MFRC522::MIFARE_Key key; // access key

#include <steppermotor.h>
#include <servo.h>

uint8_t dataSize = 18;  //Size of all needed data in bytes: commandbyte + addressbyte + 16 data bytes | Anmerkung: Stimmt net
byte trailerBlock = 7;    // the trailer block that holds our security data (used for blocks 4/5/6)

const int motor[4] = {0b00000101, 0b00001001, 0b00001010, 0b00000110};
const int box_length = 1600;
const int red_motor = 6;
const int blue_motor = 7;
const int green_motor = 8;

void setup() {
  pinMode(red_motor, OUTPUT);
  pinMode(blue_motor, OUTPUT);
  pinMode(green_motor, OUTPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  steppermotor::initialize(4,5,2,3);

}

void loop() {
  while (digitalRead(A0) == HIGH) {
    //Nüscht
  }
  if (analogRead(A5) < 900) {
    steppermotor::forward();
  }
  else {
    delay(100);
    mfrc522.PCD_Init();     // Initializes library for the RFID modul
    delay(100);
    
    for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {       //For key size:
      key.keyByte[i] = 0xFF;                                //Type key as OxFF
    }
    if (mfrc522.PICC_IsNewCardPresent()) {
      mfrc522.PICC_ReadCardSerial();
      mfrc522.PCD_Authenticate
      (MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));

      char chipInput_block4[16];                    //Array for information on block 4
      char chipInput_block5[16];                    //Array for information on block 5

      mfrc522.MIFARE_Read(4, chipInput_block4, &dataSize);
      mfrc522.MIFARE_Read(5, chipInput_block5, &dataSize);
      //Sector 4: 5, 13 | Sector 5: 7

      int bonbons = chipInput_block4[5] - 0x30;   //New int variable that is the size of the wanted bonbonbs
      for (int i = 0; i < bonbons; i++) {         //For number of bonbonbs
        servo::move(0, red_motor, 100);
        delay(100);
        servo::move(30, red_motor, 100);
        delay(100);
      }

      bonbons = chipInput_block4[13] - 0x30;    //Variable is number of wanted bonbons
      for (int i = 0; i < bonbons; i++) {
        servo::move(0, blue_motor, 100);
        delay(100);
        servo::move(50, blue_motor, 100);
        delay(100);
      }

      bonbons = chipInput_block5[7] - 0x30;
      for (int i = 0; i < bonbons; i++) {
        servo::move(50, green_motor, 100);
        delay(100);
        servo::move(0, green_motor, 100);
        delay(100);
      }

      while (analogRead(A5) > 900) {
        steppermotor::forward();

      }
    }
  }
}

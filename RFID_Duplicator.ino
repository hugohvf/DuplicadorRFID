#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10 // SDA pin
#define RST_PIN 9 // Reset pin

MFRC522 rfid(SS_PIN, RST_PIN); // Configuration of pins

MFRC522::MIFARE_Key key; 

byte nuid[4]; // This variable will store the ID number from the card

#define ledRed 8 // Chooses the pin of the LEDs
#define ledBlue 7

int readandwrite = 0; // 0 to read and 1 to write

void setup() {
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 

  pinMode(ledRed,OUTPUT);
  pinMode(ledBlue,OUTPUT);
  
  for (byte i = 0; i < 6; i++) { // Set the key for reading and writing the card
    key.keyByte[i] = 0xFF;
  }
    
  digitalWrite(ledBlue,HIGH);
}

void loop() {
  // Verify if the Card is present
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;
  // Select if its time to read or to write
  if(readandwrite == 0){  
  readuid();
  } else {
  writeuid();  
  }
  
    
}

void readuid(){
   // Read UID
   for (byte i = 0; i < 4; i++) {
      nuid[i] = rfid.uid.uidByte[i];
    }
    // Blue Led blinking
    for (int i=0;i<7;i++){
    digitalWrite(ledBlue,LOW);
    delay(300);
    digitalWrite(ledBlue,HIGH);
    delay(300);
    }
    digitalWrite(ledBlue,LOW);
    digitalWrite(ledRed,HIGH);
    readandwrite = 1; // Change the state
}

void writeuid(){
    // Write UID read to the card
    if ( rfid.MIFARE_SetUid(nuid, (byte)4, true) ) {
    Serial.println(F("Wrote new UID to card."));
    } 
    // Print UID to serial
    rfid.PICC_DumpToSerial(&(rfid.uid));
    // Blink the Red LED
    for (int i=0;i<7;i++){
    digitalWrite(ledRed,LOW);
    delay(300);
    digitalWrite(ledRed,HIGH);
    delay(300);
    }
    digitalWrite(ledRed,LOW);
    digitalWrite(ledBlue,HIGH);
    readandwrite = 0; // Change the state
}

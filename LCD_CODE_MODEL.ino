#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
 int total = 0;
 int temp = 0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);

  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "7B 66 7C 36") //change here the UID of the card/cards that you want to give access
  {
     Serial.println(" Biscuit ");
    Serial.println("Price : 10");
    total += 10;
    temp = 1;
    Serial.println(total);
  }
  if (content.substring(1) == "9A B7 4C 19" ) //change here the UID of the card/cards that you want to give access
  {
     Serial.println(" Chocolate ");
    Serial.println("Price : 20");
    total += 20;
    temp = 2;
    Serial.println(total);
  }
  if (content.substring(1) == "9C 2E 3E 2F" && temp == 1) //change here the UID of the card/cards that you want to give access
  {
     Serial.println(" bis ");
    Serial.println("Price : 10---");
    total -= 10;
   
    Serial.println(total);
  }
  if (content.substring(1) == "9C 2E 3E 2F" && temp == 2) //change here the UID of the card/cards that you want to give access
  {
     Serial.println(" cholate ");
    Serial.println("Price : 20---");
    total -= 20;
    Serial.println(total);
  }
  delay(2000);
}

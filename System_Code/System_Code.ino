#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#define SS_PIN 53
#define RST_PIN 5
#define Buzzer 24 
#define LED_R 28 
#define LED_G 32 
MFRC522 mfrc522(SS_PIN,RST_PIN); 
Servo myservo; 
void setup ()
{
  Serial.begin(9600); 
  SPI.begin(); 
  mfrc522.PCD_Init(); 
  myservo.attach(7); 
  myservo.write(0); 
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(Buzzer,OUTPUT);
  noTone(Buzzer);
  Serial.println("Put the RFID card/tag to the reader");
  Serial.println();
}
void loop()
{
  
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  
   if ( ! mfrc522.PICC_ReadCardSerial())
   {
    return;
   }
  
  Serial.print("UID tage: ");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ?" 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message: ");
  content.toUpperCase(); 
  if (content.substring(1)=="C7 BA 77 53")
  {
  Serial.println("Access Granted");
  Serial.println();
  delay (500);
  digitalWrite(LED_G,HIGH);
  tone(Buzzer, 300);
  delay(200);
  noTone(Buzzer);
  myservo.write(180);
  delay(3000);
  myservo.write(0);
  digitalWrite(LED_G,LOW);
}

else {
  Serial.println("Access Denied");
  digitalWrite(LED_R,HIGH);
  tone(Buzzer, 300);
  delay(1000);
  digitalWrite(LED_R,LOW);
  noTone(Buzzer);
}
}

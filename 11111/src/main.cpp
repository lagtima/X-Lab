#include <Arduino.h>


const int ledPin2 = 2;
void setup() {
  // put your setup code here, to run once:
  

  
  pinMode(ledPin2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() {
  digitalWrite(ledPin2,HIGH);
  delay(1000);
  digitalWrite(ledPin2,LOW);
  delay(1000);
  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(4,LOW);
  delay(1000);
  digitalWrite(15,HIGH);
  delay(1000);
  digitalWrite(15,LOW);
  delay(1000);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  
    
}

// put function definitions here:

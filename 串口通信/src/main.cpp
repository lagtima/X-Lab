#include <Arduino.h>

// put function declarations here:
#define led_pin 2

void setup() {
  Serial.begin(115200);
  pinMode(led_pin,OUTPUT);
}
void loop() {
  if(Serial.available()>0){
    char read=Serial.read();
    if(read=='1'){
      digitalWrite(led_pin,HIGH);
      Serial.println("LED点亮");
    }
    else if (read=='0'){
      digitalWrite(led_pin,LOW);
      Serial.println("LED关闭");
    }
    
    
  }
}

// put function definitions here:

#include <Arduino.h>

const int pin1 = 18;  // IN1接ESP32的GPIO18
const int pin2 = 19;  // IN2接ESP32的GPIO19
const int pin3 = 21;  // IN3接ESP32的GPIO21
const int pin4 = 22;  // IN4接ESP32的GPIO22

// 步进电机的步数
const int stepsPerRevolution = 2048;  

// 旋转速度（延迟时间，单位：毫秒）
int rotationSpeed = 2;  // 设置全局变量旋转速度

// 初始化电机控制引脚
void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  Serial.begin(115200);
  Serial.println("步进电机控制初始化完成");
}

// 步进电机控制函数
void stepMotor(int step) {
  switch (step) {
    case 0:  // 0011
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, HIGH);
      break;
    case 1:  // 0110
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
      break;
    case 2:  // 1100
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      break;
    case 3:  // 1001
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
      break;
  }
}

// 顺时针旋转指定步数
void rotateClockwise(int steps) {
  for (int i = 0; i < steps; i++) {
    stepMotor(i % 4);
    delay(rotationSpeed);  // 使用全局变量控制旋转速度
  }
}

// 逆时针旋转指定步数
void rotateCounterClockwise(int steps) {
  for (int i = 0; i < steps; i++) {
    stepMotor((3 - (i % 4)));  // 反向控制顺序
    delay(rotationSpeed);  // 使用全局变量控制旋转速度
  }
}




// 主循环
void loop() {
  rotateClockwise(stepsPerRevolution);
  delay(1000);


  rotateCounterClockwise(stepsPerRevolution);
  delay(1000);


}

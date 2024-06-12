#include <SoftwareSerial.h>    

int motor_1 = 8;
int motor_2 = 7;

int motor_pwm = 9;

int vec = 0;

SoftwareSerial BTSerial(3,4);

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  digitalWrite(motor_1, HIGH);
  digitalWrite(motor_2, LOW);
  pinMode(motor_pwm, OUTPUT);
  analogWrite(motor_pwm, 0);

  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(BTSerial.available())               // 블루투스 시리얼 통신으로 문자가 들어오면
  {
    char c = BTSerial.read();
    if (c == 'a') {
    analogWrite(motor_pwm, 0);
    }
    if (c == 'b') {
    analogWrite(motor_pwm, 125);
    }
    if (c == 'c') {
    analogWrite(motor_pwm, 150);
    }
    if (c == 'd') {
    analogWrite(motor_pwm, 175);
    }
    if (c == 'e') {
    analogWrite(motor_pwm, 225);
    }
  }
}

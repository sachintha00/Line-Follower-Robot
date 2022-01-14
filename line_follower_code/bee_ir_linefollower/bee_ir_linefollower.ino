#include <BeeLineSensorPro.h>

//define motors
#define rightMotor_ena 5
#define rightMotor_R 6
#define rightMotor_L 7
#define leftMotor_R 9
#define leftMotor_L 8
#define leftMotor_enb 10

BeeLineSensorPro sensor = BeeLineSensorPro(
(unsigned char[]) {
  A0, A1, A2, A3, A4, A5
},
LINE_BLACK);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void motorControl(int motorSpeed) {
  if (motorSpeed > 0) {
    if (motorSpeed > 255) {
      motorSpeed = 255;
    }
    digitalWrite(rightMotor_R, HIGH);
    digitalWrite(rightMotor_L,LOW);
    analogWrite(rightMotor_ena, 255 - M1);
  }
  else {
    if (motorSpeed < -255) {
      motorSpeed = -255;
    }
    digitalWrite(leftMotor_R, LOW);
    digitalWrite(leftMotor_L, HIGH);
    analogWrite(leftMotor_enb, M1 * -1);
  }
}

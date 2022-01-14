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

void motorControl(int motor1, int motor2) {
  if (motor1 > 0) {
    if (motor1 > 255) {
      motor1 = 255;
    }
    digitalWrite(M1, HIGH);
    analogWrite(M1pwm, 255 - M1);
  }
  else {
    if (motor1 < -255) {
      motor1 = -255;
    }
    digitalWrite(M1, LOW);
    analogWrite(M1pwm, M1 * -1);
  }
}

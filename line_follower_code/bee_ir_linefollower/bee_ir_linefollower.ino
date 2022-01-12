#include <BeeLineSensorPro.h>

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
  }
  else {
    if (motor1 < -255) {
      motor1 = 255;
    }
  }
}

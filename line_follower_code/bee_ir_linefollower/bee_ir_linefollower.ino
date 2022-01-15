#include <BeeLineSensorPro.h>

//define motors
#define rightMotor_ena 5
#define rightMotor_R 6
#define rightMotor_L 7
#define leftMotor_R 9
#define leftMotor_L 8
#define leftMotor_enb 10

int initMotorSpeed = 50;

//pid constants
float kp = 25;
float ki = 0;
float kd = 15;

float error = 0 , p = 0, i = 0, d = 0, pidValue = 0;
float previousError = 0, previousI = 0;

BeeLineSensorPro sensor = BeeLineSensorPro(
(unsigned char[]) {
  A0, A1, A2, A3, A4, A5
},
LINE_BLACK);



void setup() {

  Serial.begin(9600);

  pinMode(rightMotor_ena, OUTPUT);
  pinMode(rightMotor_R, OUTPUT);
  pinMode(rightMotor_L, OUTPUT);
  pinMode(leftMotor_R, OUTPUT);
  pinMode(leftMotor_L, OUTPUT);
  pinMode(leftMotor_enb, OUTPUT);

  for (int i = 0; i < 300; i++) {
    sensor.calibrate();
    delay(10);
  }
}

void loop() {
  error = sensor.readSensor();
    for(int i=0; i<6; i++){
      Serial.print(sensor.values[i]);
      Serial.print("\t");
    }
  Serial.println(error);
//  motorControl();
}

void motorControl() {
  //  if (motorSpeed > 0) {
  //    if (motorSpeed > 255) {
  //      motorSpeed = 255;
  //    }
  //    digitalWrite(rightMotor_R, HIGH);
  //    digitalWrite(rightMotor_L, LOW);
  //    analogWrite(rightMotor_ena, 255 - motorSpeed);
  //  }
  //  else {
  //    if (motorSpeed < -255) {
  //      motorSpeed = -255;
  //    }
  //    digitalWrite(leftMotor_R, LOW);
  //    digitalWrite(leftMotor_L, HIGH);
  //    analogWrite(leftMotor_enb, motorSpeed * -1);
  //  }

  int leftMotorSpeed = initMotorSpeed - pidValue;
  int rightMotorSpeed = initMotorSpeed + pidValue;

  leftMotorSpeed = constrain(leftMotorSpeed, 0, 255);
  rightMotorSpeed = constrain(rightMotorSpeed, 0, 255);

  analogWrite(leftMotor_enb, leftMotorSpeed - 30);
  analogWrite(rightMotor_ena, rightMotorSpeed);
  forward();
}

void forward() {
  digitalWrite(leftMotor_R, HIGH);
  digitalWrite(leftMotor_L, LOW);

  digitalWrite(rightMotor_R, HIGH);
  digitalWrite(rightMotor_L, LOW);
}

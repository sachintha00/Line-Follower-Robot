//define 6 ir sensor
#define sensor1  A0
#define sensor2  A1
#define sensor3  A2
#define sensor4  A3
#define sensor5  A4
#define sensor6  A5

//define motors
#define rightMotor_ena 5
#define rightMotor_R 6
#define rightMotor_L 7
#define leftMotor_R 9
#define leftMotor_L 8
#define leftMotor_enb 10

//motor speed
int initMotorSpeed = 140;

//for sensors values
int senvalues[6] = {0, 0, 0, 0, 0, 0};

//pid constants
float kp = 25;
float ki = 0;
float kd = 15;

float error = 0 , p = 0, i = 0, d = 0, pidValue = 0;
float previousError = 0, previousI = 0;

void setup() {
  //  for reading analog inputs
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);

  pinMode(rightMotor_ena, OUTPUT);
  pinMode(rightMotor_R, OUTPUT);
  pinMode(rightMotor_L, OUTPUT);
  pinMode(leftMotor_R, OUTPUT);
  pinMode(leftMotor_L, OUTPUT);
  pinMode(leftMotor_enb, OUTPUT);

  pinMode(13, OUTPUT);

}

void loop() {
  readSensorValue();
  Serial.println(error);
}

void readSensorValue() {
  senvalues[0] = digitalRead(sensor1);
  senvalues[1] = digitalRead(sensor2);
  senvalues[2] = digitalRead(sensor3);
  senvalues[3] = digitalRead(sensor4);
  senvalues[4] = digitalRead(sensor5);
  senvalues[5] = digitalRead(sensor6);

  //white color = 0
  //black color = 1

  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 0 0 0 0 0 --> ERROR = 100
    error = 100;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 1) {    //0 0 0 0 0 1 --> ERROR = 5
    error = 5;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 1 && senvalues[5] == 1) {    //0 0 0 0 1 1 --> ERROR = 4
    error = 4;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 1 && senvalues[5] == 0) {    //0 0 0 0 1 0 --> ERROR = 3
    error = 3;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 1 && senvalues[4] == 1 && senvalues[5] == 0) {    //0 0 0 1 1 0 --> ERROR = 2
    error = 2;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 1 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 0 0 1 0 0 --> ERROR = 1
    error = 1;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 1 &&
      senvalues[3] == 1 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 0 1 1 0 0 --> ERROR = 0
    error = 0;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 1 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 0 1 0 0 0 --> ERROR = -1
    error = -1;
  }
  if (senvalues[0] == 0 && senvalues[1] == 1 && senvalues[2] == 1 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 1 1 0 0 0 --> ERROR = -2
    error = -2;
  }
  if (senvalues[0] == 0 && senvalues[1] == 1 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 1 0 0 0 0 --> ERROR = -3
    error = -3;
  }
  if (senvalues[0] == 1 && senvalues[1] == 1 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //1 1 0 0 0 0 --> ERROR = -4
    error = -4;
  }
  if (senvalues[0] == 1 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //1 0 0 0 0 0 --> ERROR = -5
    error = -5;
  }
  if (senvalues[0] == 1 && senvalues[1] == 1 && senvalues[2] == 1 &&
      senvalues[3] == 1 && senvalues[4] == 1 && senvalues[5] == 1) {    //1 1 1 1 1 1 --> ERROR = -100
    error = -100;
  }
}

void pidCalculation() {
  p = error;
  i = i + previousI;
  d = error - previousError;

  pidValue = (kp * p) + (ki + i) + (kd + d);

  previousI = i;
  previousError = error;
}

void motorControl(int Speed, int lSpeed) {
  int leftMotorSpeed = initMotorSpeed - pidValue;
  int rightMotorSpeed = initMotorSpeed + pidValue;

  leftMotorSpeed = constrain(leftMotorSpeed, 0, 255);
  rightMotorSpeed = constrain(rightMotorSpeed, 0, 255);

  analogWrite(leftMotor_enb, leftMotorSpeed);
  analogWrite(rightMotor_ena, rightMotorSpeed - 30);

  digitalWrite(leftMotor_R, HIGH);
  digitalWrite(leftMotor_L, LOW);

  digitalWrite(rightMotor_R, HIGH);
  digitalWrite(rightMotor_L, LOW);
}

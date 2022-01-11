//define 4 ir sensor
#define sensor1  A0
#define sensor2  A1
#define sensor3  A2
#define sensor4  A3

//define motors
#define rightMotor_ena 5
#define rightMotor_R 6
#define rightMotor_L 7
#define leftMotor_R 9
#define leftMotor_L 8
#define leftMotor_enb 10

//for sensors values
int senvalues[6] = {0, 0, 0, 0, 0, 0};

//motor speed
int initMotorSpeed = 100;

void setup() {
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

}

void loop() {
  // put your main code here, to run repeatedly:

}

void readSensorValue() {
  senvalues[0] = digitalRead(sensor1);
  senvalues[1] = digitalRead(sensor2);
  senvalues[2] = digitalRead(sensor3);
  senvalues[3] = digitalRead(sensor4);

  //white color = 0
  //black color = 1

  if (senvalues[0] == 1 && senvalues[1] == 0
      && senvalues[2] == 0 && senvalues[3] == 0 ) {    //1 0 0 0 --> ERROR = 3
    error = 3;
  }
  if (senvalues[0] == 1 && senvalues[1] == 1
      && senvalues[2] == 0 && senvalues[3] == 0) {    //1 1 0 0 --> ERROR = 2
    error = 2;
  }
  if (senvalues[0] == 0 && senvalues[1] == 1
      && senvalues[2] == 0 && senvalues[3] == 0) {    //0 1 0 0 --> ERROR = 1
    error = 1;
  }
  if (senvalues[0] == 0 && senvalues[1] == 1
      && senvalues[2] == 1 && senvalues[3] == 0) {    //0 1 1 0 --> ERROR = 0
    error = 0;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0
      && senvalues[2] == 1 && senvalues[3] == 0) {    //0 0 1 0 --> ERROR = -1
    error = -1;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0
      && senvalues[2] == 1 && senvalues[3] == 1) {    //0 0 1 1 --> ERROR = -2
    error = -2;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0
      && senvalues[2] == 0 && senvalues[3] == 1) {    //0 0 0 1 --> ERROR = -3
    error = -3;
  }
  if (senvalues[0] == 1 && senvalues[1] == 1
      && senvalues[2] == 1 && senvalues[3] == 0) {    //1 1 1 0 --> ERROR = 100
    error = 100;
  }
  if (senvalues[0] == 0 && senvalues[1] == 1
      && senvalues[2] == 1 && senvalues[3] == 1) {    //0 1 1 1 --> ERROR = 101
    error = 101;
  }
  if (senvalues[0] == 0 && senvalues[1] == 0
      && senvalues[2] == 0 && senvalues[3] == 0) {    //0 0 0 0 --> ERROR = 102
    error = 102;
  }
  if (senvalues[0] == 1 && senvalues[1] == 1
      && senvalues[2] == 1 && senvalues[3] == 1) {    //1 1 1 1 --> ERROR = 103
    error = 103;
  }
}

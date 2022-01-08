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

//for sensors values
int senvalues[6] = {0, 0, 0, 0, 0, 0};

//pid constants
float kp = 25;
float ki = 0;
float kd = 15;

float error = 0;, p =0, i = 0, d = 0, pidValue = 0;
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
  senvalues[0] = digitalRead(sensor1);
  senvalues[1] = digitalRead(sensor2);
  senvalues[2] = digitalRead(sensor3);
  senvalues[3] = digitalRead(sensor4);
  senvalues[4] = digitalRead(sensor5);
  senvalues[5] = digitalRead(sensor6);

  //white color = 0
  //black color = 1

  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 0 0 0 0 0
    motorControl(100, 100);
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 1) {    //0 0 0 0 0 1 --> ERROR = 5
    motorControl(0, 0);
  }
  
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 1 && senvalues[5] == 1) {    //0 0 0 0 1 1 --> ERROR = 4
    motorControl(0, 0);
  }
  
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 1 && senvalues[5] == 0) {    //0 0 0 0 1 0 --> ERROR = 3
    motorControl(0, 0);
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 1 && senvalues[4] == 1 && senvalues[5] == 0) {    //0 0 0 1 1 0 --> ERROR = 2
    motorControl(0, 0);
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 1 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 0 0 1 0 0 --> ERROR = 1
    motorControl(0, 0);
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 1 &&
      senvalues[3] == 1 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 0 1 1 0 0 --> ERROR = 0
    motorControl(0, 0);
  }
  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 1 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 0 1 0 0 0 --> ERROR = -1
    motorControl(0, 0);
  }
  if (senvalues[0] == 0 && senvalues[1] == 1 && senvalues[2] == 1 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 1 1 0 0 0 --> ERROR = -2
    motorControl(0, 0);
  }
  if (senvalues[0] == 0 && senvalues[1] == 1 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //0 1 0 0 0 0 --> ERROR = -3
    motorControl(0, 0);
  }
  if (senvalues[0] == 1 && senvalues[1] == 1 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //1 1 0 0 0 0 --> ERROR = -4
    motorControl(0, 0);
  }
  if (senvalues[0] == 1 && senvalues[1] == 0 && senvalues[2] == 0 &&
      senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {    //1 0 0 0 0 0 --> ERROR = -5
    motorControl(0, 0);
  }

}

void motorControl(int Speed, int lSpeed) {
  analogWrite(leftMotor_enb, Speed);
  analogWrite(rightMotor_ena, Speed);

  digitalWrite(leftMotor_R, HIGH);
  digitalWrite(leftMotor_L, LOW);

  digitalWrite(rightMotor_R, HIGH);
  digitalWrite(rightMotor_L, LOW);
}

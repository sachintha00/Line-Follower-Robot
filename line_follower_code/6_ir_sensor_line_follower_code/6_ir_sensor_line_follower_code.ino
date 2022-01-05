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
#define leftMotor_R 8
#define leftMotor_L 9
#define leftMotor_enb 10

//for sensors values
int senvalues[6] = {0, 0, 0, 0, 0, 0};

void setup() {
  //  for reading analog inputs
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);

  pinMode(13,OUTPUT);

}

void loop() {
  senvalues[0] = digitalRead(sensor1);
  senvalues[1] = digitalRead(sensor2);
  senvalues[2] = digitalRead(sensor3);
  senvalues[3] = digitalRead(sensor4);
  senvalues[4] = digitalRead(sensor5);
  senvalues[5] = digitalRead(sensor6);

  if (senvalues[0] == 0 && senvalues[1] == 0 && senvalues[2] == 0 &&
    senvalues[3] == 0 && senvalues[4] == 0 && senvalues[5] == 0) {
    Serial.println("white color");
    Serial.println(senvalues[0]); //0
    digitalWrite(13, HIGH);
  }
  else {
    Serial.println("black color");
    Serial.println(digitalRead(senvalues[0])); //1
    digitalWrite(13, LOW);
  }

}

//define 6 ir sensor
#define sensor1 = A0
#define sensor2 = A1
#define sensor3 = A2
#define sensor4 = A3
#define sensor5 = A4
#define sensor6 = A5

//define motors
#define rightMotor_ena 5
#define rightMotor_R 6
#define rightMotor_L 7
#define leftMotor_R 8
#define leftMotor_L 9
#define leftMotor_enb 10

//for sensors values
int senvalues[6]={0,0,0,0,0,0};

void setup() {
//  for reading analog inputs
  Serial.begin(9600);
  for(int i=0; i<6; i++){
    pinMode("A"+i,INPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}

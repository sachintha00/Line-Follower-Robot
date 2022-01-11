//define motors
#define rightMotor_ena 5
#define rightMotor_R 6
#define rightMotor_L 7
#define leftMotor_R 9
#define leftMotor_L 8
#define leftMotor_enb 10

void setup() {
  pinMode(rightMotor_ena, OUTPUT);
  pinMode(rightMotor_R, OUTPUT);
  pinMode(rightMotor_L, OUTPUT);
  pinMode(leftMotor_R, OUTPUT);
  pinMode(leftMotor_L, OUTPUT);
  pinMode(leftMotor_enb, OUTPUT);

}

void loop() {
  analogWrite(rightMotor_ena, 70);
  analogWrite(leftMotor_enb, 60);
  digitalWrite(leftMotor_R, HIGH);
  digitalWrite(leftMotor_L, LOW);

  digitalWrite(rightMotor_R, HIGH);
  digitalWrite(rightMotor_L, LOW);

}

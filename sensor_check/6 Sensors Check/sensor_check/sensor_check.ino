int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;

int led1 = 12;
int led2 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(led2, OUTPUT);
}
void loop() {
  if (digitalRead(sensor1) == LOW && digitalRead(sensor2) == LOW && digitalRead(sensor3) == LOW &&
      digitalRead(sensor4) == LOW && digitalRead(sensor5) == LOW && digitalRead(sensor6) == LOW) {
    Serial.println("white color");
    Serial.println(digitalRead(sensor1)); //0
    digitalWrite(led2, HIGH);
  }
  else {
    Serial.println("black color");
    Serial.println(digitalRead(sensor1)); //1
    digitalWrite(led2, LOW);
  }
}

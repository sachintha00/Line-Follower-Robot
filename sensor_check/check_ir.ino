#define sensor 3
#define check 13

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(check, OUTPUT);
}

void loop() {
  //  digitalWrite(check,HIGH);
  //  delay(1000);
  //  digitalWrite(check,LOW);
  //  delay(1000);

  if (digitalRead(sensor) == HIGH) {
    digitalWrite(check, HIGH);
//    Serial.print(digitalRead(sensor));
    Serial.println(analogRead(sensor));
  }
  else{
    digitalWrite(check,LOW);
//    Serial.print(digitalRead(sensor));
    Serial.println(analogRead(sensor));
  }

}

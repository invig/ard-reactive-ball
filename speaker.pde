int speaker;

void speakerOn() {
  digitalWrite(speakerPin, HIGH);
}

void speakerOff() {
  digitalWrite(speakerPin, LOW); 
}

void speakerTwo() {
  digitalWrite(speakerPin, HIGH);
  redLight();
  delay(200);
  digitalWrite(speakerPin, LOW);
  noLight();
  delay(200);
  digitalWrite(speakerPin, HIGH);
  redLight();
  delay(200);
  digitalWrite(speakerPin, LOW);
  noLight();
}

void speakerThree() {
  digitalWrite(speakerPin, HIGH);
    redLight();
  delay(200);
  digitalWrite(speakerPin, LOW);
    noLight();
  delay(200);
  digitalWrite(speakerPin, HIGH);
    redLight();
  delay(200);
  digitalWrite(speakerPin, LOW);
    noLight();
  delay(200);
  digitalWrite(speakerPin, HIGH);
    redLight();
  delay(200);
  digitalWrite(speakerPin, LOW);
    noLight();
}
   
void speakerFour() {
  digitalWrite(speakerPin, HIGH);
  redLight();
  delay(200);
  digitalWrite(speakerPin, LOW);
    noLight();
  delay(200);
  digitalWrite(speakerPin, HIGH);
  redLight();
  delay(200);
  digitalWrite(speakerPin, LOW);
    noLight();
  delay(200);
  digitalWrite(speakerPin, HIGH);
  redLight();
  delay(200);
  digitalWrite(speakerPin, LOW);
    noLight();
  delay(200);
  digitalWrite(speakerPin, HIGH);
  redLight();
  delay(200);
  digitalWrite(speakerPin, LOW);
    noLight();
}

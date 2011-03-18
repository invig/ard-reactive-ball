int valueR = 0;
int valueG = 0;
int valueB = 0;
int ledpinR = 9;
int ledpinG = 11;
int ledpinB = 10;

void redLight() {
  analogWrite(ledpinR, 255);
  analogWrite(ledpinG, 0);
  analogWrite(ledpinB, 0);
}

void greenLight() {
  analogWrite(ledpinR, 0);
  analogWrite(ledpinG, 255);
  analogWrite(ledpinB, 0);
}  

void blueLight() {
  analogWrite(ledpinR, 0);
  analogWrite(ledpinG, 0);
  analogWrite(ledpinB, 255);
}

void yellowLight() {
  analogWrite(ledpinR, 255);
  analogWrite(ledpinG, 255);
  analogWrite(ledpinB, 0);
}

void purpleLight() {
  analogWrite(ledpinR, 160);
  analogWrite(ledpinG, 32);
  analogWrite(ledpinB, 240);
}

void aquaLight() {
  analogWrite(ledpinR, 0);
  analogWrite(ledpinG, 255);
  analogWrite(ledpinB, 255);
}

void pinkLight() {
  analogWrite(ledpinR, 255);
  analogWrite(ledpinG, 105);
  analogWrite(ledpinB, 180);
}

void orangeLight() {
  analogWrite(ledpinR, 255);
  analogWrite(ledpinG, 69);
  analogWrite(ledpinB, 0);
}

void noLight() {
  analogWrite(ledpinR, 0);
  analogWrite(ledpinG, 0);
  analogWrite(ledpinB, 0);
}

void allLight() {
  analogWrite(ledpinR, 255);
  analogWrite(ledpinG, 255);
  analogWrite(ledpinB, 255);
}

void whiteLight() {
  analogWrite(ledpinR, 255);
  analogWrite(ledpinG, 255);
  analogWrite(ledpinB, 255);
}

void boxMaroon() {
  analogWrite(ledpinR, 183);
  analogWrite(ledpinG, 36);
  analogWrite(ledpinB, 103);
}

void boxGreen() {
  analogWrite(ledpinR, 202);
  analogWrite(ledpinG, 219);
  analogWrite(ledpinB, 42);
}

void boxBlue() {
  analogWrite(ledpinR, 109);
  analogWrite(ledpinG, 200);
  analogWrite(ledpinB, 191);
}






void rainbowLightShow() {
  for(valueR = 0 ; valueR <= 255; valueR+=1) // R up
  {
    analogWrite(ledpinR, valueR);           // sets the value (range from 0 to 255)
    analogWrite(ledpinG, 0);
    analogWrite(ledpinB, 0);
    delay(1);                            // waits for 30 milli seconds
  }
   for(valueG = 0 ; valueG <= 255; valueG+=1) // G up, R on
  {
    analogWrite(ledpinR, 255);
    analogWrite(ledpinB, 0);
    analogWrite(ledpinG, valueG);
    delay(1);
  }
   for(valueR = 255 ; valueR >= 0; valueR-=1) // R down, G on
  {
    analogWrite(ledpinG, 255);
    analogWrite(ledpinB, 0);
    analogWrite(ledpinR, valueR);
    delay(1);
  }
   for(valueB = 0 ; valueB <= 255; valueB+=1) // B up, G on
  {
    analogWrite(ledpinG, 255);
    analogWrite(ledpinR, 0);
    analogWrite(ledpinB, valueB);
    delay(1);
  }
   for(valueG = 255 ; valueG >= 0; valueG-=1) // G down, B on
  {
    analogWrite(ledpinB, 255);
    analogWrite(ledpinR, 0);
    analogWrite(ledpinG, valueG);
    delay(1);
  }
  for(valueR = 0 ; valueR <= 255; valueR+=1) // R up, B on
  {
    analogWrite(ledpinB, 255);
    analogWrite(ledpinG, 0);
    analogWrite(ledpinR, valueR);
    delay(1);
  }   
   for(valueG = 0 ; valueG <= 255; valueG+=1) // G up, all on
  {
    analogWrite(ledpinB, 255);
    analogWrite(ledpinR, 255);
    analogWrite(ledpinG, valueG);
    delay(1);
  }
 {
    analogWrite(ledpinR, 255);
    analogWrite(ledpinG, 255);
    analogWrite(ledpinB, 255);
    delay(1);
  }
}

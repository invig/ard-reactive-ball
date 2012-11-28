#include "WProgram.h"
//FINAL 2_0 NO COMMENTS - FEATURE COMPLETE, TWEAKED, AND HOPEFULLY BUG FREE.
void setup();
void initiateBall();
void gameSelection ();
void playerSelection ();
void gameOne();
void gameOneEnd();
void loop();
void readAcceleration();
void checkForCatch();
void checkForStart();
void redLight();
void greenLight();
void blueLight();
void yellowLight();
void purpleLight();
void aquaLight();
void pinkLight();
void orangeLight();
void noLight();
void allLight();
void whiteLight();
void boxMaroon();
void boxGreen();
void boxBlue();
void rainbowLightShow();
void playerSelectorTwo();
void playerSelectorThree();
void playerSelectorFour();
void speakerOn();
void speakerOff();
void speakerTwo();
void speakerThree();
void speakerFour();
int RESET = 7;
int speakerPin = 3;
long randNumber;

boolean initStatus = false;
boolean ballCatch = false;
boolean startShake = false;
boolean gameOneStatus = false;
int gameType = 0;
int numberOfPlayers = 0;
int currentPlayer = 0;
int numberOfCatches = 0;


void setup() {
  pinMode(RESET,OUTPUT);
  Serial.begin(115200);
  digitalWrite(RESET,HIGH);
  delay(10);
  digitalWrite(RESET,LOW);
  delay(2000);
  randomSeed(analogRead(5));
  pinMode(speakerPin, OUTPUT);
}

void initiateBall() {
  startShake = false;
  gameOneStatus = false;
  currentPlayer = 0;

  rainbowLightShow();
  speakerOn();
  delay (400);
  speakerOff();
  while (initStatus == false) {
    readAcceleration();
    checkForStart();
    if (startShake == true){
      greenLight();
      delay(2000);
      gameSelection();
    }
  }
}


void gameSelection () {
  boolean gameSelectionStatus = false;
  startShake = false;

  while (gameSelectionStatus == false){
    boxMaroon();
    for (int i=0; i<8000; i++){
      readAcceleration();
      checkForStart();
      if (startShake == true){
        gameType = 1;
        greenLight();
        delay(2000);
        playerSelection();
      }
    }
    boxBlue();
    for (int i=0; i<8000; i++){
      readAcceleration();
      checkForStart();
      if (startShake == true){
        gameType = 2;
        greenLight();
        delay(2000);
        playerSelection();
      }
    }
    boxGreen();
    for (int i=0; i<8000; i++){
      readAcceleration();
      checkForStart();
      if (startShake == true){
        gameType = 3;
        greenLight();
        delay(2000);
        playerSelection();
      }
    }

  }
}


void playerSelection () {
  boolean playerSelectionStatus = false;
  startShake = false;
  delay(2000);
  while (playerSelectionStatus == false){
    noLight();
    speakerTwo();
    whiteLight();
    for (int i=0; i<8000; i++){
      readAcceleration();
      checkForStart();
      if (startShake == true){
        numberOfPlayers = 2;
        greenLight();
        delay(2000);
        gameOne();
      }
    }
    noLight();
    speakerThree();
    whiteLight();
    for (int i=0; i<8000; i++){
      readAcceleration();
      checkForStart();
      if (startShake == true){
        numberOfPlayers = 3;
        greenLight();
        delay(2000);
        gameOne();
      }
    }
    noLight();
    speakerFour();
    whiteLight();
    for (int i=0; i<8000; i++){
      readAcceleration();
      checkForStart();
      if (startShake == true){
        numberOfPlayers = 4;
        greenLight();
        delay(2000);
        gameOne();
      }
    }
  }
}


void gameOne() {
  int maxCatches = 0;
  numberOfCatches = 0;
  whiteLight();
  gameOneStatus = false;
  if (gameType == 1){
    maxCatches = random(20,40);
  } else if (gameType == 2){
    maxCatches = random(10, 25);
  } else if (gameType == 3){
    maxCatches = random(5, 15);
  } else {
    gameSelection();
  }
  while (gameOneStatus == false) {
    ballCatch = 0;
    readAcceleration();
    checkForCatch();
    if (ballCatch == true) {
      if(numberOfPlayers == 2){
        playerSelectorTwo();
        numberOfCatches++;
      }
      if(numberOfPlayers == 3){
        playerSelectorThree();
        numberOfCatches++;
      }
      if(numberOfPlayers == 4){
        playerSelectorFour();
        numberOfCatches++;
      }
    }
    if (numberOfCatches == maxCatches) {
      gameOneEnd();
    }
  }
}

void gameOneEnd() {
  digitalWrite(speakerPin, HIGH);
  blueLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  redLight();
  delay(100);
  digitalWrite(speakerPin, HIGH);
  purpleLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  greenLight();
  delay(100);
  digitalWrite(speakerPin, HIGH);
  allLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  blueLight();
  delay(100);
  digitalWrite(speakerPin, HIGH);
  redLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  purpleLight();
  delay(100);
  digitalWrite(speakerPin, HIGH);
  greenLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  allLight();
  digitalWrite(speakerPin, HIGH);
  blueLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  redLight();
  delay(100);
  digitalWrite(speakerPin, HIGH);
  purpleLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  greenLight();
  delay(100);
  digitalWrite(speakerPin, HIGH);
  allLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  blueLight();
  delay(100);
  digitalWrite(speakerPin, HIGH);
  redLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  purpleLight();
  delay(100);
  digitalWrite(speakerPin, HIGH);
  greenLight();
  delay(100);
  digitalWrite(speakerPin, LOW);
  redLight();
  delay(10000);
  initiateBall();
}

void loop() {
  initiateBall();
}

int xval;
int yval;
int zval;
int xav;
int yav;
int zav;


void readAcceleration() {
xval = analogRead(0);
yval = analogRead(1);
zval = analogRead(2);
xval = xval / 4;
yval = yval / 4;
zval = zval / 4;
}

void checkForCatch() {
  if (xav > 195) {
    ballCatch = true;
  }
  else if (xval < 60) {
    ballCatch = true;
  }
  else if (xval > 195) {
    ballCatch = true;
  }
  else if (yval < 60) {
    ballCatch = true;
  }
  else if (zval > 195) {
    ballCatch = true;
  }
  else if (zval < 60) {
    ballCatch = true;
  }
}

void checkForStart() {
  if (xav > 160) {
    startShake = true;
  }
  else if (xval < 100) {
    startShake = true;
  }
  else if (xval > 160) {
    startShake = true;
  }
  else if (yval < 100) {
    startShake = true;
  }
  else if (zval > 160) {
    startShake = true;
  }
  else if (zval < 100) {
    startShake = true;
  }
}

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

void playerSelectorTwo() {
  randNumber = random(1,3);
  while (randNumber == currentPlayer){
    randNumber = random(1,3);
  }
  if (numberOfCatches == 0 && randNumber == 1){
     playerSelectorTwo();
  }
  if (randNumber == 1) {
    aquaLight();
    currentPlayer = 1;
    delay(800);
  }
  if (randNumber == 2) {
    yellowLight();
    currentPlayer = 2;
    delay(800);
  }
  if (randNumber == 3) {
    playerSelectorTwo();
  }
}

void playerSelectorThree() {
  randNumber = random(1,4);
  while (randNumber == currentPlayer){
    randNumber = random(1,4);
  }
  if (numberOfCatches == 0 && randNumber == 1){
     playerSelectorThree();
  }
  if (randNumber == 1) {
    aquaLight();
    currentPlayer = 1;
    delay(800);
  }
  if (randNumber == 2) {
    yellowLight();
    currentPlayer = 2;
    delay(800);
  }
  if (randNumber == 3) {
    pinkLight();
    currentPlayer = 3;
    delay(800);
  }
  if (randNumber == 4) {
    playerSelectorThree();
  }

}

void playerSelectorFour() {
  randNumber = random(1,5);
  while (randNumber == currentPlayer){
    randNumber = random(1,5);
  }
  if (numberOfCatches == 0 && randNumber == 1){
     playerSelectorFour();
  }
  if (randNumber == 1) {
    aquaLight();
    currentPlayer = 1;
    delay(800);
  }
  if (randNumber == 2) {
    yellowLight();
    currentPlayer = 2;
    delay(800);
  }
  if (randNumber == 3) {
    pinkLight();
    currentPlayer = 3;
    delay(800);
  }
  if (randNumber == 4) {
    orangeLight();
    currentPlayer = 4;
    delay(800);
  }
  if (randNumber == 5) {
    playerSelectorFour();
  }
}

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

int main(void)
{
	init();

	setup();

	for (;;)
		loop();

	return 0;
}


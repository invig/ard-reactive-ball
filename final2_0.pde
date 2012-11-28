//FINAL 2_0 NO COMMENTS - FEATURE COMPLETE, TWEAKED, AND HOPEFULLY BUG FREE.
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

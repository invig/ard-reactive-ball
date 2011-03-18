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

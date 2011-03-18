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

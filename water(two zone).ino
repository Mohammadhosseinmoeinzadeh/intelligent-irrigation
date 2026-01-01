#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


int setZ1 = 50;
int setZ2 = 50;


unsigned long lastSampleTime = 0;
const unsigned long sampleInterval = 250;

unsigned long lastBtnTime = 0;
const unsigned long btnDelay = 200;

float sumZ1 = 0, sumZ2 = 0;
int sampleCount = 0;

float levelZ1 = 0;
float levelZ2 = 0;

void setup() {
  analogReference(DEFAULT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  pinMode(8, INPUT_PULLUP);   // Z1 +
  pinMode(9, INPUT_PULLUP);   // Z1 -
  pinMode(12, INPUT_PULLUP);  // Z2 +
  pinMode(13, INPUT_PULLUP);  // Z2 -

  pinMode(10, OUTPUT); // buzzer / beep
  pinMode(11, OUTPUT); // valve Z1
  pinMode(0, OUTPUT);  // valve Z2

  lcd.begin(16, 2);

  for (int a = 0; a < 16; a++) {
    lcd.setCursor(4, 0);
    lcd.print("Loading");
    lcd.setCursor(a, 1);
    lcd.print("#");
    delay(150);
  }
  lcd.clear();
}

void loop() {

  unsigned long now = millis();


  if (now - lastBtnTime > btnDelay) {

    if (digitalRead(8) == LOW) {
      lastBtnTime = now;
      beep();
      setZ1 += 5;
      if (setZ1 > 100) setZ1 = 0;
    }

    if (digitalRead(9) == LOW) {
      lastBtnTime = now;
      beep();
      setZ1 -= 5;
      if (setZ1 < 0) setZ1 = 0;
    }

    if (digitalRead(12) == LOW) {
      lastBtnTime = now;
      beep();
      setZ2 += 5;
      if (setZ2 > 100) setZ2 = 0;
    }

    if (digitalRead(13) == LOW) {
      lastBtnTime = now;
      beep();
      setZ2 -= 5;
      if (setZ2 < 0) setZ2 = 0;
    }
  }


  if (now - lastSampleTime >= sampleInterval) {
    lastSampleTime = now;

    int raw1 = analogRead(A0);
    int raw2 = analogRead(A1);

    float v1 = 100.0 - (raw1 * 100.0 / 1023.0) - 8.0;
    float v2 = 100.0 - (raw2 * 100.0 / 1023.0) - 8.0;

    v1 = constrain(v1, 0, 100);
    v2 = constrain(v2, 0, 100);

    sumZ1 += v1;
    sumZ2 += v2;
    sampleCount++;

    if (sampleCount >= 20) {   
      levelZ1 = sumZ1 / sampleCount;
      levelZ2 = sumZ2 / sampleCount;

      sumZ1 = 0;
      sumZ2 = 0;
      sampleCount = 0;
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Z1=");
  lcd.print(levelZ1, 1);
  lcd.print("% ");

  lcd.print("Z2=");
  lcd.print(levelZ2, 1);
  lcd.print("% ");

  lcd.setCursor(0, 1);
  lcd.print("S1=");
  lcd.print(setZ1);
  lcd.print("% ");

  lcd.print("S2=");
  lcd.print(setZ2);
  lcd.print("% ");


  digitalWrite(11, (setZ1 > levelZ1) ? LOW : HIGH);
  digitalWrite(0,  (setZ2 > levelZ2) ? LOW : HIGH);
}


void beep() {
  digitalWrite(10, HIGH);
  delay(20);
  digitalWrite(10, LOW);
}

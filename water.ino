#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int setLevel = 50;


unsigned long lastSampleTime = 0;
const unsigned long sampleInterval = 250;   // ms
float sumSamples = 0;
int sampleCount = 0;
float waterLevel = 0;


unsigned long lastBtnTime = 0;
const unsigned long btnDelay = 200;

void setup() {
  analogReference(DEFAULT);

  pinMode(A0, INPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

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


  if (digitalRead(8) == LOW && now - lastBtnTime > btnDelay) {
    lastBtnTime = now;
    digitalWrite(10, HIGH);
    delay(20);
    digitalWrite(10, LOW);

    setLevel += 5;
    if (setLevel > 100) setLevel = 100;
  }

  
  if (digitalRead(9) == LOW && now - lastBtnTime > btnDelay) {
    lastBtnTime = now;
    digitalWrite(10, HIGH);
    delay(20);
    digitalWrite(10, LOW);

    setLevel -= 5;
    if (setLevel < 0) setLevel = 0;
  }


  if (now - lastSampleTime >= sampleInterval) {
    lastSampleTime = now;

    int raw = analogRead(A0);
    float level = 100.0 - (raw * 100.0 / 1023.0) - 8.0;

    if (level < 0) level = 0;
    if (level > 100) level = 100;

    sumSamples += level;
    sampleCount++;

    if (sampleCount >= 60) {   
      waterLevel = sumSamples / sampleCount;
      sumSamples = 0;
      sampleCount = 0;
    }
  }


  lcd.setCursor(0, 0);
  lcd.print("Water Level=");
  lcd.print(waterLevel, 1);
  lcd.print("%   ");

  lcd.setCursor(0, 1);
  lcd.print("SET Level=");
  lcd.print(setLevel);
  lcd.print("%   ");


  if (setLevel > waterLevel) {
    digitalWrite(11, LOW);
  } else {
    digitalWrite(11, HIGH);
  }
}

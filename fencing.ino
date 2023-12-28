#include <LiquidCrystal.h>
const int rs = 4,
          en =  6,
          d4 = 10,
          d5 = 11,
          d6 = 12,
          d7  = 13,
          buzzer = 5, // buzzer
          LEDred = 8, //Light for fencer 2
          LEDgreen = 3, // Light for fencer1
          fencer1Blade = 9, //Pushbutton1
          fencer2Blade = 7; //Pushbutton2

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int isFencer1Hit = 0;
int isFencer2Hit = 0;


int points1 = 0;
int points2 = 0;
int win = 5;

const byte pausePin = 2;
volatile bool toggleState = false;

void  setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(fencer1Blade, INPUT);
  pinMode(fencer2Blade, INPUT);
  pinMode(pausePin, INPUT_PULLUP);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDred, OUTPUT);
  pinMode(buzzer, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pausePin), checkSwitch, FALLING);
}
//Print the status of the fencer
void printToSerial() {
  if (isFencer1Hit == HIGH) {
    Serial.println("Fencer 1 attacks");
  }
  if (isFencer2Hit == HIGH) {
    Serial.println("Fencer 2 attacks");
  }
  else {
    Serial.println("charging...");
  }
}
// Set what should be printed on the scoreboard
void scoreBoard() {
  lcd.setCursor(0, 0);
  lcd.print("SCORE BOARD");
  lcd.setCursor(6, 1);
  lcd.print(points1);
  lcd.setCursor(7, 1);
  lcd.print(" : ");
  lcd.setCursor(10, 1);
  lcd.print(points2);
}

//Check the status of the interrupt push button
void checkSwitch() {
  if (digitalRead(pausePin) == LOW) {
    toggleState = !toggleState;
  }
}
// Timer
void timer3Mins() {
  lcd.setCursor(0, 1);
  lcd.print(1);
  lcd.setCursor(1, 1);
  lcd.print(":");
  lcd.setCursor(2, 1);
  lcd.print("00");
  delay(1000);
  for (int j = 59; j >= 0; j--) {
    if (toggleState == true) {
      lcd.setCursor(0, 1);
      lcd.print(0);
      lcd.setCursor(1, 1);
      lcd.print(":");
      if (j > 9) {
        lcd.setCursor(2, 1);
        lcd.print(j);
        delay(1000);
      }
      else {
        lcd.setCursor(2, 1);
        lcd.print("0");
        lcd.print(j);
        delay(1000);
      }
    }
  }
  lcd.clear();
}


void loop() {

  isFencer1Hit = digitalRead(fencer1Blade);
  isFencer2Hit = digitalRead(fencer2Blade);
  printToSerial();

  digitalWrite(LEDgreen, LOW);
  digitalWrite(LEDred, LOW);
  if (points1 < 5 && points2 < 5) {
    if (isFencer1Hit == LOW)
    {
      digitalWrite(LEDgreen, HIGH);

    }
    if (isFencer1Hit == HIGH)
    {
      digitalWrite(LEDgreen, LOW);
      digitalWrite(LEDred, HIGH);
      tone(buzzer, 200, 1000);
      delay(1000);
      points1++;

    }
    if (isFencer2Hit == LOW)
    {
      digitalWrite(LEDred, HIGH);

    }
    if (isFencer2Hit == HIGH)
    {
      digitalWrite(LEDred, LOW);
      delay(500);
      tone(buzzer, 200, 1000);
      points2++;
    }
    scoreBoard();
    delay(500);
  }
  else {
    if (points1 == 5) {
      lcd.setCursor(0, 0);
      lcd.print("Fencer 1 Win!");
      tone(buzzer, 800, 250);
      tone(buzzer, 400, 250);
      tone(buzzer, 800, 250);
      tone(buzzer, 400, 250);
      noTone(buzzer);
      digitalWrite(LEDred, LOW);
      digitalWrite(LEDgreen, HIGH);
      delay(250);
      digitalWrite(LEDgreen, LOW);
    }
    else {
      lcd.setCursor(0, 0);
      lcd.print("Fencer 2 Win!");
      tone(buzzer, 800, 250);
      tone(buzzer, 400, 250);
      tone(buzzer, 800, 250);
      tone(buzzer, 400, 250);
      noTone(buzzer);
      digitalWrite(LEDgreen, LOW);
      digitalWrite(LEDred, HIGH);
      delay(250);
      digitalWrite(LEDred, LOW);
    }
  }
  if (toggleState == true) {
    lcd.clear();
    timer3Mins();
  }


}

#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(22, 23, 28, 29, 30, 31);
Cytron_PS2Shield ps2(10, 11);

#define stepDir 32
#define stepEn 33

#define PWMAMP 2
#define DIRAMP 3

#define DIRA2 6
#define DIRA1 5
#define PWMA 4
#define DIRB1 8
#define DIRB2 12
#define PWMB 7

#define DIRE 28
#define PWME 29

int pwmValue = 0;

inline void right();
inline void left();
inline void reverse();
inline void forward();

int i, select = 0;

void setup()
{
  ps2.begin(115200);
  Serial.begin(115200);
  lcd.begin(16, 2);

  digitalWrite(stepEn, OUTPUT);
  pinMode(stepDir, OUTPUT);

  pinMode(PWME, OUTPUT);
  pinMode(DIRE, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(DIRA1, OUTPUT);
  pinMode(DIRB1, OUTPUT);
  pinMode(DIRA2, OUTPUT);
  pinMode(DIRB2, OUTPUT);

  pinMode(PWMAMP, OUTPUT);
  pinMode(DIRAMP, OUTPUT);

  digitalWrite(DIRAMP, HIGH);

}

void loop() {

  if (ps2.readButton(PS2_SELECT) == 0)
  { if (select == 0 || select == 2)
      select = 1;
    else if (select == 1)
      select = 2;
  }
  lcd.setCursor(0, 0);

  while (select == 1)
  { if (ps2.readButton(PS2_LEFT_1) == 0 || ps2.readButton(PS2_LEFT_2) == 0 || ps2.readButton(PS2_RIGHT_1) == 0 || ps2.readButton(PS2_RIGHT_2) == 0)
    {
      if (ps2.readButton(PS2_LEFT_1) == 0 && ps2.readButton(PS2_LEFT_2) == 1 && ps2.readButton(PS2_RIGHT_1) == 1 && ps2.readButton(PS2_RIGHT_2) == 1)
      {
        analogWrite(PWMAMP, 255);
        pwmValue = 255;
      }
      else if (ps2.readButton(PS2_LEFT_1) == 1 && ps2.readButton(PS2_LEFT_2) == 0 && ps2.readButton(PS2_RIGHT_1) == 1 && ps2.readButton(PS2_RIGHT_2) == 1)
      {
        analogWrite(PWMAMP, 200);
        pwmValue = 200;
      }
      else if (ps2.readButton(PS2_LEFT_1) == 1 && ps2.readButton(PS2_LEFT_2) == 1 && ps2.readButton(PS2_RIGHT_1) == 0 && ps2.readButton(PS2_RIGHT_2) == 1)
      {
        analogWrite(PWMAMP, 230);
        pwmValue = 230;
      }
      else if (ps2.readButton(PS2_LEFT_1) == 1 && ps2.readButton(PS2_LEFT_2) == 1 && ps2.readButton(PS2_RIGHT_1) == 1 && ps2.readButton(PS2_RIGHT_2) == 0)
      {
        analogWrite(PWMAMP, 93);
        pwmValue = 93;
      }
      lcd.print("PWM:");
      lcd.print(pwmValue);
      delay(100);

      break;
    }
  }


while (select == 2)
{
  if ((ps2.readButton( PS2_UP) == 0) || (ps2.readButton( PS2_DOWN) == 0) || (ps2.readButton( PS2_LEFT) == 0) || (ps2.readButton( PS2_RIGHT) == 0))
  {
    while (1)
    {
      if (ps2.readButton( PS2_UP) == 0)
      {
        forward();

      }
      else if (ps2.readButton( PS2_RIGHT) == 0)
      {
        right();

      }
      else if (ps2.readButton( PS2_DOWN) == 0)
      {
        reverse();
      }
      else if (ps2.readButton(  PS2_LEFT) == 0)
      {
        left();
      }

      else if ((ps2.readButton( PS2_UP) == 1) || (ps2.readButton( PS2_DOWN) == 1) || (ps2.readButton( PS2_LEFT) == 1) || (ps2.readButton( PS2_RIGHT) == 1))
      { //Serial.println("yooo");
        analogWrite(PWMA, 0);
        digitalWrite(DIRA1, HIGH);
        digitalWrite(DIRA2, HIGH);

        analogWrite(PWMB, 0);
        digitalWrite(DIRB1, HIGH);
        digitalWrite(DIRB2, HIGH);


        break;
      }
    }
  }
  else if ((ps2.readButton( PS2_TRIANGLE) == 0) || (ps2.readButton( PS2_CROSS) == 0))
  {
    while (1)
    {
      if (ps2.readButton(PS2_TRIANGLE) == 0)
      {
        analogWrite(PWME, 150);
        digitalWrite(DIRE, HIGH);
      }
      else if (ps2.readButton( PS2_CROSS) == 0)
      { analogWrite(PWME, 150);
        digitalWrite(DIRE, LOW);

      }
      else if ((ps2.readButton( PS2_TRIANGLE) == 1) || (ps2.readButton( PS2_CROSS) == 1) )
      {
        digitalWrite(PWME, 0);

        break;

      }
    }
  }

  else if ((ps2.readButton( PS2_SQUARE) == 0) || (ps2.readButton( PS2_CIRCLE) == 0))
  {

    while (1)
    {
      if (ps2.readButton( PS2_CIRCLE) == 0)
      {
        analogWrite(stepEn, 255);
        digitalWrite(stepDir, HIGH);

      }
      else if (ps2.readButton(PS2_SQUARE) == 0)
      {
        analogWrite(stepEn, 255);
        digitalWrite(stepDir, LOW);


      }
      else if ((ps2.readButton( PS2_SQUARE) == 1) || (ps2.readButton( PS2_CIRCLE) == 1))
      {

        digitalWrite(stepEn, 0);
        break;
      }
    }
  }
  else
  {
    Serial.println(pwmValue);
    Serial.println("yooo");
    analogWrite(PWMA, 0);
    digitalWrite(DIRA1, HIGH);
    digitalWrite(DIRA2, HIGH);

    analogWrite(PWMB, 0);
    digitalWrite(DIRB1, HIGH);
    digitalWrite(DIRB2, HIGH);

    digitalWrite(PWME, 0);

  }
}
}


void forward()
{
  analogWrite(PWMA, 180);
  digitalWrite(DIRA1, HIGH);
  digitalWrite(DIRA2, LOW);
  analogWrite(PWMB, 180);
  digitalWrite(DIRB1, HIGH);
  digitalWrite(DIRB2, LOW);
}


void   reverse()
{
  analogWrite(PWMA, 180);
  digitalWrite(DIRA1, LOW);
  digitalWrite(DIRA2, HIGH);
  analogWrite(PWMB, 180);
  digitalWrite(DIRB1, LOW);
  digitalWrite(DIRB2, HIGH);
}

void   right()
{
  analogWrite(PWMA, 180);
  digitalWrite(DIRA1, HIGH);
  digitalWrite(DIRA2, LOW);
  analogWrite(PWMB, 180);
  digitalWrite(DIRB1, LOW);
  digitalWrite(DIRB2, HIGH);

}

void  left()
{
  analogWrite(PWMA, 180);
  digitalWrite(DIRA1, LOW);
  digitalWrite(DIRA2, HIGH);
  analogWrite(PWMB, 180);
  digitalWrite(DIRB1, HIGH);
  digitalWrite(DIRB2, LOW);

}

#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>


Cytron_PS2Shield ps2(10,11); // SoftwareSerial: Rx and Tx pin

#define stepPul 47
#define stepDir 48
#define stepEn 49

#define PWMAMP 2
#define DIRAMP 3

#define DIRA2 6
#define DIRA1 5
#define PWMA 4
#define DIRB1 8
#define DIRB2 12
#define PWMB 7

//for ejection
#define DIRE 25
#define PWME 24

//FUNCTIONS
void FORWARDAMPFLOW();
void break1();
void right();
void left();
void reverse();
void forward();
void third();
void first();
void function();
void stepper1();
void stepper2();

int i;
int s=0;

void setup()
{
  ps2.begin(115200); // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(115200); // Set monitor baudrate to 9600

 digitalWrite(stepEn,HIGH);
 pinMode(stepPul,OUTPUT);
 pinMode(stepDir,OUTPUT);
 
  //for ejection
  pinMode(PWME,OUTPUT);
  pinMode(DIRE,OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(DIRA1, OUTPUT);
  pinMode(DIRB1, OUTPUT);
  pinMode(DIRA2, OUTPUT);
  pinMode(DIRB2, OUTPUT);

  pinMode(PWMAMP, OUTPUT);
  pinMode(DIRAMP, OUTPUT);

}

void loop()
{


while(1)
{
  //for ejection

  if(ps2.readButton(PS2_CIRCLE)==0)
  {
  analogWrite(PWME,255);
  digitalWrite(DIRE,HIGH);
  }
else if(ps2.readButton(PS2_CIRCLE)==1)
  {
  analogWrite(PWME,0);
  digitalWrite(DIRE,LOW);
  }
else if (ps2.readButton( PS2_UP) == 0)
  {
    forward();
    Serial.println("forward");
  }
else if (ps2.readButton( PS2_UP) == 1)
  { analogWrite(PWMA, 0);
  digitalWrite(DIRA1, HIGH);
  digitalWrite(DIRA2,HIGH);
  analogWrite(PWMB, 0);
  digitalWrite(DIRB1, HIGH);
  digitalWrite(DIRB2, HIGH);
   // forward();
    Serial.println("forward");
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




    else if (ps2.readButton( PS2_RIGHT) == 1)
  {
    analogWrite(PWMA, 0);
  digitalWrite(DIRA1, HIGH);
  digitalWrite(DIRA2,HIGH);
  analogWrite(PWMB, 0);
  digitalWrite(DIRB1, HIGH);
  digitalWrite(DIRB2, HIGH);

  }
  else if (ps2.readButton( PS2_DOWN) == 1)
  {
    analogWrite(PWMA, 0);
  digitalWrite(DIRA1, HIGH);
  digitalWrite(DIRA2,HIGH);
  analogWrite(PWMB, 0);
  digitalWrite(DIRB1, HIGH);
  digitalWrite(DIRB2, HIGH);
  }
  else if (ps2.readButton(  PS2_LEFT) == 1)
  {
    analogWrite(PWMA, 0);
  digitalWrite(DIRA1, HIGH);
  digitalWrite(DIRA2,HIGH);
  analogWrite(PWMB, 0);
  digitalWrite(DIRB1, HIGH);
  digitalWrite(DIRB2, HIGH);
  }

  //STEPPER MOTOR
 else if (ps2.readButton(PS2_TRIANGLE) == 0)
  {   digitalWrite(stepDir,HIGH);
       //for(i=0;i<400;i++)
      digitalWrite(stepPul,HIGH);
      delayMicroseconds(400);
      digitalWrite(stepPul,LOW);
      delayMicroseconds(400);
    
     Serial.println("forward");
    }
  else if (ps2.readButton( PS2_CROSS) == 0)
  {
   digitalWrite(stepDir,LOW);
    //  for(i=0;i<400;i++)
      digitalWrite(stepPul,HIGH);
      delayMicroseconds(400);
      digitalWrite(stepPul,LOW);
      delayMicroseconds(400);
    }

  //AMPFLOW
  else if (ps2.readButton( PS2_LEFT_1) == 0)
  {
    
    delay(1000);
    analogWrite(PWMAMP, 255);
    digitalWrite(DIRAMP, HIGH);
  }
  else if (ps2.readButton( PS2_RIGHT_2) == 0)
  {
   
    delay(1000);
    analogWrite(PWMAMP, 230);
    digitalWrite(DIRAMP, HIGH);
  }
   else if (ps2.readButton( PS2_RIGHT_1) == 0)
  {
    
    delay(1000);
    analogWrite(PWMAMP, 210);
    digitalWrite(DIRAMP, HIGH);
  }
   else if (ps2.readButton( PS2_LEFT_2) == 0)
  {
    
    delay(1000);
    analogWrite(PWMAMP, 180);
    digitalWrite(DIRAMP, HIGH);
  }




 else if (ps2.readButton( PS2_LEFT_1) == 1)
  {
    
    delay(1000);
analogWrite(PWMAMP, 180);
    digitalWrite(DIRAMP, HIGH);
  }
  else if (ps2.readButton( PS2_RIGHT_2) == 1)
  {
   
    delay(1000);
analogWrite(PWMAMP, 180);
    digitalWrite(DIRAMP, HIGH);
  }
   else if (ps2.readButton( PS2_RIGHT_1) == 1)
  {
    
    delay(1000);
 analogWrite(PWMAMP, 180);
    digitalWrite(DIRAMP, HIGH);  }
   else if (ps2.readButton( PS2_LEFT_2) == 1)
  {
    
    delay(1000);
analogWrite(PWMAMP, 180);
    digitalWrite(DIRAMP, HIGH);
  }


  else
  {
    Serial.println("yooo");
  analogWrite(PWMA, 0);
  digitalWrite(DIRA1, HIGH);
  digitalWrite(DIRA2,HIGH);
  analogWrite(PWMB, 0);
  digitalWrite(DIRB1, HIGH);
  digitalWrite(DIRB2, HIGH);

    //third(); //Function to make the servo static if the value from the joystick is not 0.
    analogWrite(PWMAMP, 180);
    digitalWrite(DIRAMP, HIGH);
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



void  break1()
{
  analogWrite(PWMA, 0);
  digitalWrite(DIRA1, LOW);
  digitalWrite(DIRA2, LOW);
  analogWrite(PWMB, 0);
  digitalWrite(DIRB1, LOW);
  digitalWrite(DIRB2, LOW);
}



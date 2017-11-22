#define u0 30
#define u1 31
#define u2 32
#define u3 33
#define u4 34
#define u5 35
#define u6 36
#define u7 37

#define ENA 13
#define IN1 11
#define IN2 12
#define IN3 9
#define IN4 10
#define ENB 8



void setup() {

  
  pinMode(u0, INPUT);
  pinMode(u1, INPUT);
  pinMode(u2, INPUT);
  pinMode(u3, INPUT);
  pinMode(u4, INPUT);
  pinMode(u5, INPUT);
  pinMode(u6, INPUT);
  pinMode(u7, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(115200);

}

void loop() {


  Serial.println("\n u0=");
  Serial.println(digitalRead(u0));

  Serial.println("\n u1=");
  Serial.println(digitalRead(u1));

  Serial.println("\n u2=");
  Serial.println(digitalRead(u2));

  Serial.println("\n u3=");
  Serial.println(digitalRead(u3));

  Serial.println("\n u4=");
  Serial.println(digitalRead(u4));

  Serial.println("\n u5=");
  Serial.println(digitalRead(u5));

  Serial.println("\n u6=");
  Serial.println(digitalRead(u6));

  Serial.println("\n u7=");
  Serial.println(digitalRead(u7));

int flagl1=0,flagr=0,flags=0,flagRev=0,flagl2=0,flagl3=0;

back:





  if ((digitalRead(u0)==0&&digitalRead(u1)==0)&&((digitalRead(u2)==1||digitalRead(u3)==1||digitalRead(u4)==1||digitalRead(u5)==1)&&digitalRead(u6)==0||digitalRead(u7)==0))
{
  flags=1;
  
 
}

else if(digitalRead(u0)==1||digitalRead(u1)==1&&(digitalRead(u2)==1&&digitalRead(u3)==1&&digitalRead(u4)==1&&digitalRead(u5)==1)&&(digitalRead(u6)==1||digitalRead(u7)==1))
{
  flagl1=1;
  
}

else if((digitalRead(u0)==1 || digitalRead(u1)==1) && digitalRead(u2)==1 && digitalRead(u3)==1 && digitalRead(u4)==1 && digitalRead(u5)==1&&(digitalRead(u6)==0 || digitalRead(u7)==0))
{
  flagl2=1;

}

else if((digitalRead(u0)==1 || digitalRead(u1)==1) || (digitalRead(u2)==0 || digitalRead(u3)==0 || digitalRead(u4)==0 || digitalRead(u5)==0)&&(digitalRead(u6)==0 || digitalRead(u7)==0))
{
  flagl3=1;
}

else if((digitalRead(u0)==0&&digitalRead(u1)==0) && (digitalRead(u2)==0&&digitalRead(u3)==0 &&digitalRead(u4)==0 || digitalRead(u5)==0) || (digitalRead(u6)==1 || digitalRead(u7)==1))
{


flagr=1;
  
}

if (flags=1)
{ 
 
  
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    Serial.println("\n Go Straight");
  
   
  }




   if(flagl1==1)
{

    analogWrite(ENA, 0);
    analogWrite(ENB, 250);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    delay(220);
    Serial.println("\n Take a Left");
  }


   if (flagl2==1)
{

     
    analogWrite(ENA, 0);
    analogWrite(ENB, 120);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);
    delay(220);
    Serial.println("\n Take a Left");
  }


   if (flagl3==1)
{  
    analogWrite(ENA, 0);
    analogWrite(ENB, 120);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    delay(90);
    Serial.println("\n Take a Left");
  }

   if (flagr==1)
{

    analogWrite(ENA, 120);
    analogWrite(ENB, 0);

    digitalWrite(IN1,HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
     delay(90);       
    Serial.println("\n Take a Short Right");
  }

   if ((digitalRead(u0)==0 && digitalRead(u1)==0 && digitalRead(u2)==0 && digitalRead(u3) ==0&& digitalRead(u4)==0 && digitalRead(u5)==0 && digitalRead(u6)==0 && digitalRead(u7)==0))
{   
      
    if(flagRev==0)
    {analogWrite(ENA, 120);
    analogWrite(ENB, 120);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    flagRev=1;
    delay(250);
    goto back;
    }
  else if(flagRev==1)
    {analogWrite(ENA,120);
    analogWrite(ENB, 0);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(500);
    Serial.println("\n Take a Short Right");
 
}
}
   

}


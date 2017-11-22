#define u0 32
#define u1 33
#define u2 34
#define u3 35
#define u4 36
#define u5 37
#define u6 38
#define u7 39

#define ENA 2
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define ENB 7  



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

  Serial.begin(9600 );

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

int flagl1=0,flagr=0,flags=0,flagl2=0,flagl3=0,flagsl=0,flagsr=0;

int l=0,r=0,s=0,sl=0,sr=0;



if ((digitalRead(u0)==0&&digitalRead(u1)==0)&&((digitalRead(u2)==1||digitalRead(u3)==1||digitalRead(u4)==1||digitalRead(u5)==1)&&digitalRead(u6)==0&&digitalRead(u7)==0))
{
  flags=1;
  s=1;
 
}


if ((digitalRead(u0)==0&&digitalRead(u1)==1)&&((digitalRead(u2)==1||digitalRead(u3)==1&&digitalRead(u4)==0&&digitalRead(u5)==0)&&digitalRead(u6)==0&&digitalRead(u7)==0))
{
  flagsl=1;
  sl=1;
 
}

if(digitalRead(u0)==1&&digitalRead(u1)==1&&(digitalRead(u2)==1&&digitalRead(u3)==1&&digitalRead(u4)==1&&digitalRead(u5)==1)&&(digitalRead(u6)==1&&digitalRead(u7)==1))
{
  flagl1=1;
  l=1;
}

if((digitalRead(u0)==1&&digitalRead(u1)==1) && digitalRead(u2)==1 && digitalRead(u3)==1 && digitalRead(u4)==1 && digitalRead(u5)==1&&(digitalRead(u6)==0&& digitalRead(u7)==0))
{
  flagl2=1;
  l=1;

}

if((digitalRead(u0)==1&&digitalRead(u1)==1)||(digitalRead(u2)==1&&digitalRead(u3)==0 &&digitalRead(u4)==0&&digitalRead(u5)==0)&&(digitalRead(u6)==0&&digitalRead(u7)==0))
{
  flagl3=1;
  l=1;
}


if((digitalRead(u0)==0&&digitalRead(u1)==0) && (digitalRead(u2)==0&&digitalRead(u3)==0 &&digitalRead(u4)==1 || digitalRead(u5)==1)&&(digitalRead(u6)==1&&digitalRead(u7)==0))
{

flagsr=1;
sr=1;
}


if((digitalRead(u0)==0&&digitalRead(u1)==0) && (digitalRead(u2)==0&&digitalRead(u3)==0 &&digitalRead(u4)==0&&digitalRead(u5)==1)||(digitalRead(u6)==1&&digitalRead(u7)==1))
{

flagr=1;
r=1;
}

//straight

if (flags=1)
{   digitalWrite(ENA, 255);
    digitalWrite(ENB, 255);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    Serial.println("\n Go Straight");
}



if(flagsl==1)
{

    analogWrite(ENA,80);
    analogWrite(ENB,100);

    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    delay(50);
    Serial.println("\n Take a short Left");
  }

if (flagsr==1)
{

    analogWrite(ENA, 100);
    analogWrite(ENB, 80);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
     delay(50);       
    Serial.println("\n Take a Short Right");
  }


//left

if(flagl1==1)
{

    digitalWrite(ENA, 250);
    digitalWrite(ENB, 250);

    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    delay(50);
    Serial.println("\n Take a Left");
  }


 if (flagl2==1)
{   digitalWrite(ENA,255);
    digitalWrite(ENB,255);

    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    delay(50);
    Serial.println("\n Take a Left");
  }


if (flagl3==1)
{  
    digitalWrite(ENA,255);
    digitalWrite(ENB,255);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    
    delay(50);
    Serial.println("\n Take a Left");
  }


//right
if (flagr==1)
{

    digitalWrite(ENA,255);
    digitalWrite(ENB, 255);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    
     delay(50);       
    Serial.println("\n Take a Right");
  }


//dead end

  if ((digitalRead(u0)==0 && digitalRead(u1)==0 && digitalRead(u2)==0 && digitalRead(u3) ==0&& digitalRead(u4)==0 && digitalRead(u5)==0 && digitalRead(u6)==0 && digitalRead(u7)==0))
 {   
      
    if(s==1||r==1)
    {digitalWrite(ENA,255);
     digitalWrite(ENB,255);
     digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
     
     delay(50);
     
     Serial.println("\n Take a Short Right");
    }
    
   if(l==1)
    {digitalWrite(ENA,255);
     digitalWrite(ENB,255);
     digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    
    delay(50);
    Serial.println("\n Take a left");
    }

  if(sl==1)
{
    analogWrite(ENA, 100);
    analogWrite(ENB,150);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    
    delay(50);
    Serial.println("\n Take a short Left");

  
}


 if(sr==1)
{
     analogWrite(ENA, 150);
    analogWrite(ENB, 100);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
     delay(50);       
    Serial.println("\n Take a Short Right");
 
}
    
  }
}


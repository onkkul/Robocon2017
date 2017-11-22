#include<SoftwareSerial.h>
#include<Cytron_PS2Shield.h>

Cytron_PS2Shield ps2(10,11);

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



  int s=0;
  int lx;
  int ly;

void setup() {
  ps2.begin(115200);
  
}
}

void loop() {

 // lx=map(ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS),0,255,-255,255);
 // ly=map(ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS),0,255,255,-255);

  if(ps2.readButton(PS2_UP)==0)
  s=1;
 else if(ps2.readButton(PS2_DOWN)==0)
  s=2;
 else if(ps2.readButton(PS2_RIGHT)==0)
  s=3;
 else if(ps2.readButton(PS2_LEFT)==0)
  s=4;
 else if(ps2.readButton(PS2_CROSS)==0)
  s=5;
 else if(ps2.readButton(PS2_TRIANGLE)==0)
  s=6;
 else if(ps2.readButton(PS2_SQUARE)==0)
  s=7;
 else if(ps2.readButton(PS2_CIRCLE)==0)
  s=8;
 else if(ps2.readButton(PS2_SLECT)==0)
  s=9;
 else if(ps2.readButton(PS2_START)==0)
  s=10;
 else
 s=0;

delay(100);
 
  switch(s)
  {case 1: forward();
           break;
   case 2:reverse();
           break;
  case 3: right();
          break;
  case 4 left();
          break; 
  case 5:  digitalWrite(stepDir,LOW);
      for(i=0;i<400;i++)
     { digitalWrite(stepPul,HIGH);
      delayMicroseconds(400);
      digitalWrite(stepPul,LOW);
      delayMicroseconds(400);
    }
    break;
 case 6:  digitalWrite(stepDir,HIGH);
       for(i=0;i<400;i++)
      {digitalWrite(stepPul,HIGH);
      delayMicroseconds(400);
      digitalWrite(stepPul,LOW);
      delayMicroseconds(400);
    }
    break;
 case 7:  analogWrite(PWME,0);
         digitalWrite(DIRE,LOW);
         break;
 case 8:  analogWrite(PWME,255);
         digitalWrite(DIRE,HIGH);
         break;
 case 9:if(amp==0)
         amp=1;
         else
         amp=0;

         if(amp==1)
         { analogWrite(PWMAMP, 155);
           digitalWrite(DIRAMP, HIGH);
         }

         break;
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



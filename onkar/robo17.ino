#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;         // number of steps the motor has taken

//amflow
#define pwm 6
#define IN 7

//straight
#define pwmA 22
#define pwmB 23
#define IN1 24
#define IN2 25
#define IN3 26
#define IN4 27

#define pulse 2
#define depulse 3

int st=4;
int ej=5;
int flag;
int count=0;

void setup() {
  pinMode(pulse,INPUT);
pinMode(depulse,INPUT);

pinMode(pwmA,OUTPUT);
pinMode(pwmB,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

pinMode(pwm,OUTPUT);
pinMode(IN,OUTPUT);

Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
 /* Serial.println(digitalRead(pulse));
  delay(100);
   Serial.println(digitalRead(depulse));*/
  // put your main code here, to run repeatedly:
int flag;
Serial.println(flag);
 if(digitalRead(pulse)==HIGH)
{
 
  count++;
  flag=0;
   delay(3000);
  
}

 if(digitalRead(depulse)==HIGH)
{
  count--;
  flag=1;
  delay(3000);
}
Serial.println(count);


if(count==1 || count==5 && flag==0)
{
 processa();
 eject();
 }
 
if(count==2 || count==4 && flag==0)
{
 processb();
 eject();
 }
 
if(count==3 && flag==0)
{
 processc();
 eject();
 }

}
void eject()
{
   if(digitalRead(ej)==HIGH)
   {
   Serial.println("throw");
   }
}
void processa()
{
   digitalWrite(pwmA,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(pwmB,HIGH);

  Serial.println("initialise");

   myStepper.step(30);                                               //stepper motor may be analog
 Serial.println("steppper ON");

  digitalWrite(pwm,50);
  digitalWrite(IN,HIGH);                                            //ampflow may be analog
  Serial.println("Ampflow ON");
  
  if(digitalRead(st)==HIGH)
 {
      digitalWrite(pwmA,LOW);
      digitalWrite(pwmB,LOW);
  
     Serial.println("stop");  
  }

 }
 void processb()
{
  
   digitalWrite(pwmA,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(pwmB,HIGH);

  Serial.println("initialise second");

   myStepper.step(50);
 Serial.println("steppper second ON");                                 //stepper motor may be analog

  digitalWrite(pwm,100);
  digitalWrite(IN,HIGH);                                                //ampflow may be analog
  Serial.println("Ampflow second ON");
  
  if(digitalRead(st)==HIGH)
 {
      digitalWrite(pwmA,LOW);
      digitalWrite(pwmB,LOW);
  
     Serial.println("stop");  
  }
 }
  void processc()
{
     digitalWrite(pwmA,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(pwmB,HIGH);

  Serial.println("initialise third");

   myStepper.step(70);                                           //stepper motor may be analog
 Serial.println("steppper third ON");

  digitalWrite(pwm,150);
  digitalWrite(IN,HIGH);                                         //ampflow may be analog
  Serial.println("Ampflow third ON");
  
  if(digitalRead(st)==HIGH)
 {
      digitalWrite(pwmA,LOW);
      digitalWrite(pwmB,LOW);
  
     Serial.println("stop");  
  }

 }

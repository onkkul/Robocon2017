#define u0 30
#define u1 31
#define u2 32
#define u3 33
#define u4 34
#define u5 35
#define u6 36
#define u7 37

#define ENA 8
#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12
#define ENB 13

int f=0;
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

  Serial.begin(19200);
}

void loop() {
  Serial.println(f);
  Serial.println(digitalRead(u0));
  Serial.println("U0=");
  Serial.println(digitalRead(u0));
  Serial.println("U1=");
  Serial.println(digitalRead(u1));
  Serial.println("U2=");
  Serial.println(digitalRead(u2));
  Serial.println("U3=");
  Serial.println(digitalRead(u3));
  Serial.println("U4=");
  Serial.println(digitalRead(u4));
  Serial.println("U5=");
  Serial.println(digitalRead(u5));
  Serial.println("U6=");
  Serial.println(digitalRead(u6));
  Serial.println("U7=");
  Serial.println(digitalRead(u7));
  Serial.println("\n\n");

  if(digitalRead(u0)==1||digitalRead(u1)==1)
  { f=1;
    analogWrite(ENA, 255);
    analogWrite(ENB, 10);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("\n TAKE a Left");
    if(digitalRead(u3)==1||digitalRead(u4)==1)
    {delay(1000);}
    }
 else if((digitalRead(u0)==0&&digitalRead(u1)==0)&&(digitalRead(u2)==1||digitalRead(u3)==1||digitalRead(u4)==1||digitalRead(u5)==1))
  {  f=0;

    if(digitalRead(u6)==1||digitalRead(u7)==1)
    {f=2;}
    
    if(digitalRead(u2)==1&&(digitalRead(u3)==0&&digitalRead(u4)==0&&digitalRead(u5)==0))
     { analogWrite(ENA, 255);
       analogWrite(ENB, 150);

       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);
       delay(300);

       Serial.println("\n TAKE a short Left");
      }
    else if ((digitalRead(u2)==0&&digitalRead(u3)==0&&digitalRead(u4)==0)&&digitalRead(u5)==1)
       {
        analogWrite(ENA, 150);
        analogWrite(ENB, 255);

        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        delay(300);
        Serial.println("\n TAKE a short Right");
        }
      else
      {analogWrite(ENA, 255);
       analogWrite(ENB, 255);

       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);

       Serial.println("\n GO Straight");
     }}
    else if (digitalRead(u6)==1||digitalRead(u7)==1)
    {f=2;
    analogWrite(ENA, 10);
    analogWrite(ENB, 200);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("\n TAKE a Right");
    }
  else if (digitalRead(u0)==0&&digitalRead(u1)==0&&digitalRead(u2)==0&&digitalRead(u3)==0&&digitalRead(u4)==0&&digitalRead(u5)==0&&digitalRead(u6)==0&&digitalRead(u7)==0)
{      
  if(f==2)  
    {analogWrite(ENA, 150);
    analogWrite(ENB, 150);
 
     digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("\n TAKE a Right");
    }
   if(f==1)
   {analogWrite(ENA, 150);
    analogWrite(ENB, 150);
 
     digitalWrite(IN1,HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("\n TAKE a LEFT");
   }
   if(f==0)
   {analogWrite(ENA, 150);
    analogWrite(ENB, 150);
 
     digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("\n TAKE a Right");
   }
 
 }
  }

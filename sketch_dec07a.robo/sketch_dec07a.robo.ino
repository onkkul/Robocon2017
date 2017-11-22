#define u0 30
#define u1 31
#define u2 32
#define u3 33
#define u4 34
#define u5 35
#define u6 36
#define u7 37

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

  Serial.begin(9600);
}

void loop() {

  Serial.println("U0= digitalRead(u0)");
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


  if (digitalRead(u0) == 1 || digitalRead(u1) == 1 && digitalRead(u2) == 0 && digitalRead(u3) == 0 && digitalRead(u4) == 0 && digitalRead(u5) == 0 && digitalRead(u6) == 0 && digitalRead(u7) == 0)

  {
    digitalWrite(ENA, 10);
    digitalWrite(ENB, 10);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    Serial.println("\n TAKE a Left");
  }

   else if ((digitalRead(u0) == 0 && digitalRead(u1) == 0 && digitalRead(u2)) == 1 || digitalRead(u3) == 1 || digitalRead(u4) == 1 || digitalRead(u5) == 1 && digitalRead(u6) == 0 && digitalRead(u7) == 0)
  {
    digitalWrite(ENA, 10);
    digitalWrite(ENB, 10);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4, LOW);

    Serial.println("\n GO Straight");
  }



  /*else if ((digitalRead(u0) || digitalRead(u1) || digitalRead(u2)) && digitalRead(u3) && digitalRead(u4) && !(digitalRead(u5) || digitalRead(u6) || digitalRead(u7)))

    {
    digitalWrite(ENA, 10);
    digitalWrite(ENB, 10);

    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);

    Serial.print("\n TAKE a Left");
    }

    else if ((digitalRead(u0) || digitalRead(u1) || digitalRead(u2)) && !(digitalRead(u3) || digitalRead(u4)) && !(digitalRead(u5) || digitalRead(u6) || digitalRead(u7)))

    {
    digitalWrite(ENA, 10);
    digitalWrite(ENB, 10);

    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);

    Serial.print("\n TAKE a Left");
    }

    else if (!(digitalRead(u0) || digitalRead(u1) || digitalRead(u2)) && (digitalRead(u3) || digitalRead(u4)) && (digitalRead(u5) || digitalRead(u6) || digitalRead(u7)))

    {
    digitalWrite(ENA, 10);
    digitalWrite(ENB, 10);

    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);

    Serial.print("\n TAKE a Short Right");
    }*/

  if (digitalRead(u0) == 0 && digitalRead(u1) == 0 && digitalRead(u2) == 0 && digitalRead(u3) == 0 && digitalRead(u4) == 0 && digitalRead(u5) == 0 && digitalRead(u6) == 1 || digitalRead(u7) == 1)

  { digitalWrite(ENA, 10);
    digitalWrite(ENB, 10);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    Serial.println("\n TAKE a Right");
  }
  if (digitalRead(u0) == 0 && digitalRead(u1) == 0 && digitalRead(u2) == 0 && digitalRead(u3) == 0 && digitalRead(u4) == 0 && digitalRead(u5) == 0 && digitalRead(u6) == 0 && digitalRead(u7) == 0)

  {
    digitalWrite(ENA, 10);
    digitalWrite(ENB, 10);
 ;
     digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    Serial.println("\n TAKE a Right");
 
  }
  

}

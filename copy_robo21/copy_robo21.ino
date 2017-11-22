#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>


Cytron_PS2Shield ps2(10, 11); // SoftwareSerial: Rx and Tx pin

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

//for ejection
#define DIRE 28
#define PWME 29

int a = 28;
int b = 29;
int c = 30;
int d = 31;
int e = 32;
int f = 33;
int g = 34;
int h = 35;


//FUNCTIONS
void right();
void left();
void reverse();
void forward();

int i;

void setup()
{
  ps2.begin(115200); // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(115200); // Set monitor baudrate to 9600


  digitalWrite(stepEn, OUTPUT);
  pinMode(stepDir, OUTPUT);

  //for ejection
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

  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);
  pinMode(d, INPUT);
  pinMode(e, INPUT);
  pinMode(f, INPUT);
  pinMode(g, INPUT);
  pinMode(h, INPUT);
  
}

void loop() {
  while (1)
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
    else if ((ps2.readButton(PS2_LEFT_1) == 0) || (ps2.readButton( PS2_LEFT_2) == 0) ||  (ps2.readButton( PS2_RIGHT_1) == 0) || (ps2.readButton( PS2_RIGHT_2) == 0))
    {
      while (1)
      {
        if (ps2.readButton(PS2_LEFT_1) == 0)
        {
          analogWrite(PWMAMP, 255);
          digitalWrite(DIRAMP, HIGH);
        }
        else if (ps2.readButton( PS2_LEFT_2) == 0)
        {

          analogWrite(PWMAMP, 200);
          digitalWrite(DIRAMP, HIGH);
        }
        else if (ps2.readButton( PS2_RIGHT_1) == 0)
        {

          analogWrite(PWMAMP, 230);
          digitalWrite(DIRAMP, HIGH);
        }
        else if (ps2.readButton(PS2_RIGHT_2) == 0)
        {

          analogWrite(PWMAMP, 93);
          digitalWrite(DIRAMP, HIGH);
        }
        else if ((ps2.readButton(PS2_LEFT_1) == 1) || (ps2.readButton( PS2_LEFT_2) == 1) ||  (ps2.readButton( PS2_RIGHT_1) == 1) || (ps2.readButton( PS2_RIGHT_2) == 1))
        {
          analogWrite(PWMAMP, 150);
          digitalWrite(DIRAMP, HIGH);
          break;
        }
      }
    }
    else if (digitalRead(a) == 0 || digitalRead(b) == 0 || digitalRead(c) == 1 || digitalRead(d) == 1 || digitalRead(e) == 1 || digitalRead(f) == 1 || digitalRead(g) == 0 || digitalRead(h) == 0 )
    {
      while(1)
      {
      if (digitalRead(a) == 0 || digitalRead(b) == 0 || digitalRead(c) == 1 || digitalRead(d) == 1 || digitalRead(e) == 1 || digitalRead(f) == 1 || digitalRead(g) == 0 || digitalRead(h) == 0 )
      {
        digitalWrite(27, HIGH);
      }
       else if (digitalRead(a) == 0 || digitalRead(b) == 0 || digitalRead(c) == 0 || digitalRead(d) == 0 || digitalRead(e) == 0 || digitalRead(f) == 0 || digitalRead(g) == 0 || digitalRead(h) == 0 )
      {
        digitalWrite(27, LOW);
        break;
      }
     }
    }
    else
    {
      Serial.println("yooo");
      analogWrite(PWMA, 0);
      digitalWrite(DIRA1, HIGH);
      digitalWrite(DIRA2, HIGH);

      analogWrite(PWMB, 0);
      digitalWrite(DIRB1, HIGH);
      digitalWrite(DIRB2, HIGH);

      analogWrite(PWMAMP, 150);
      digitalWrite(DIRAMP, HIGH);

      analogWrite(PWME, 0);

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

#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>


Cytron_PS2Shield ps2(10, 11); // SoftwareSerial: Rx and Tx pin
//amflow
#define PWMAMP 3
#define DIRAMP 2

//basemotor
#define DIRA2 50 
#define DIRA1 52
#define PWMA 4
#define DIRB1 48
#define DIRB2 46
#define PWMB 5 

//circle and sq(angle)
#define DIRE 9
#define PWME 8

//cross and tri(angle)
#define stepDir 7
#define stepEn 6

//for ejection
#define PLO 13
#define DLO 12

//FUNCTIONS
void right();
void left();
void reverse();
void forward();

int i, pwmval;

void setup()
{
  ps2.begin(115200); // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(115200); // Set monitor baudrate to 9600

  digitalWrite(stepEn, OUTPUT);  //Upper direction motor
  pinMode(stepDir, OUTPUT);      //

  pinMode(PWME, OUTPUT);     //
  pinMode(DIRE, OUTPUT);     // lower direction motor

  pinMode(PLO, OUTPUT);      // loading motor
  pinMode(DLO, OUTPUT);      //

  pinMode(PWMA, OUTPUT);     //
  pinMode(PWMB, OUTPUT);     //
  pinMode(DIRA1, OUTPUT);    //Base motor pins
  pinMode(DIRB1, OUTPUT);    //
  pinMode(DIRA2, OUTPUT);    //
  pinMode(DIRB2, OUTPUT);    //

  pinMode(DIRAMP, OUTPUT);    //ampflow motor pins
  pinMode(PWMAMP, OUTPUT);     //


  digitalWrite(DIRAMP, HIGH);
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
          left();

        }
        else if (ps2.readButton( PS2_DOWN) == 0)
        {
          
          reverse();
          Serial.println("go");
        }
        else if (ps2.readButton(  PS2_LEFT) == 0)
        {
          right();
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


    else if ((ps2.readButton( PS2_CIRCLE) == 0) || (ps2.readButton( PS2_SQUARE) == 0))
    {
      while (1)
      {
        if (ps2.readButton(PS2_CIRCLE) == 0)
        {
           analogWrite(PWME, 150);
          digitalWrite(DIRE, LOW);
         
        }

        else if (ps2.readButton( PS2_SQUARE) == 0)
        {    analogWrite(PWME, 150);
          digitalWrite(DIRE, HIGH);

        }

        else if ((ps2.readButton( PS2_CIRCLE) == 1) && (ps2.readButton( PS2_SQUARE) == 1) )

        {
          digitalWrite(PWME, 0);

          break;

        }
      }
    }
    else if ((ps2.readButton( PS2_CROSS) == 0) || (ps2.readButton( PS2_TRIANGLE) == 0))
    {

      while (1)
      {
        if (ps2.readButton( PS2_TRIANGLE) == 0)
        {
           analogWrite(stepEn, 255);
          digitalWrite(stepDir, LOW);

         
        }
        else if (ps2.readButton(PS2_CROSS) == 0)
        {
           analogWrite(stepEn, 255);
          digitalWrite(stepDir, HIGH);

         

        }
        else if ((ps2.readButton( PS2_CROSS) == 1) && (ps2.readButton( PS2_TRIANGLE) == 1))
        {

          digitalWrite(stepEn, 0);
          break;
        }
      }
    }
    else if ((ps2.readButton(PS2_START) == 0)||(ps2.readButton(PS2_SELECT) == 0)||(ps2.readButton(PS2_LEFT_1) == 0) || (ps2.readButton( PS2_LEFT_2) == 0) ||  (ps2.readButton( PS2_RIGHT_1) == 0) || (ps2.readButton( PS2_RIGHT_2) == 0))
    {
      while (1)
      {
        if (ps2.readButton(PS2_LEFT_1) == 0)
        { 
          pwmval=200;
          analogWrite(PWMAMP, 200);
        }
        else if (ps2.readButton( PS2_LEFT_2) == 0)
        { pwmval+=10;
        delay(300);
          analogWrite(PWMAMP, pwmval);
        }
        else if (ps2.readButton( PS2_RIGHT_1) == 0)
        { pwmval=120;
          analogWrite(PWMAMP, 120);
        }
        else if (ps2.readButton(PS2_RIGHT_2) == 0)
        {
          pwmval-=10;
        delay(300);
          analogWrite(PWMAMP, pwmval);
        }
        else if (ps2.readButton(PS2_START) == 0)
        {
          pwmval+=2;
        delay(300);
          analogWrite(PWMAMP, pwmval);
        }
        else if (ps2.readButton(PS2_SELECT) == 0)
        {
          pwmval-=2;
        delay(300);
          analogWrite(PWMAMP, pwmval);
        }
        else if ((ps2.readButton(PS2_START) == 1)||(ps2.readButton(PS2_SELECT) == 1) || (ps2.readButton(PS2_LEFT_1) == 1) || (ps2.readButton( PS2_LEFT_2) == 1) ||  (ps2.readButton( PS2_RIGHT_1) == 1) || (ps2.readButton( PS2_RIGHT_2) == 1))
        {
          break;
        }
      }
    }
    else if((ps2.readButton(PS2_JOYSTICK_LEFT_LEFT) == 100)||(ps2.readButton(PS2_JOYSTICK_LEFT_RIGHT) == 100))
    { 
      while(1)
      {
      if (ps2.readButton(PS2_JOYSTICK_LEFT_LEFT) == 100)
      {
        analogWrite(PLO, 255);
        digitalWrite(DLO, HIGH);
      }
      else if (ps2.readButton(PS2_JOYSTICK_LEFT_RIGHT) == 100)
      {

        analogWrite(PLO, 255);
         digitalWrite(DLO, LOW);
        break;
      }
      else
      {
        analogWrite(PLO, 0);
         digitalWrite(DLO, HIGH);
        break;
      }
      }
    }
    else
    {

         Serial.println(pwmval);
      Serial.println("yooo");
      analogWrite(PWMA, 0);
      digitalWrite(DIRA1, HIGH);
      digitalWrite(DIRA2, HIGH);

      analogWrite(PWMB, 0);
      digitalWrite(DIRB1, HIGH);
      digitalWrite(DIRB2, HIGH);

      analogWrite(PWME, 0);

      analogWrite(PLO, 0);
      digitalWrite(DLO, HIGH);


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
  /*
  analogWrite(PWMA, 180);
  digitalWrite(DIRA1, LOW);
  digitalWrite(DIRA2, HIGH);
  analogWrite(PWMB, 180);
  digitalWrite(DIRB1, LOW);
  digitalWrite(DIRB2, HIGH);
*/
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

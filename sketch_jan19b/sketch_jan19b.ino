#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
#include <Stepper.h>

Cytron_PS2Shield ps2(10,11); // SoftwareSerial: Rx and Tx pin
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
0#define PWMAMP 2
#define DIRAMP 3
Stepper myStepper(stepsPerRevolution, 49,48,47,46);

#define DIRA2 6
#define DIRA1 5
#define PWMA 4
#define DIRB1 8
#define DIRB2 9
#define PWMB 7

//for ejection
#define DIRE 25
#define PWME 24

//STEPPER MOTOR CONNECTION

int i;
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


void setup()
{
  ps2.begin(115200); // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(115200); // Set monitor baudrate to 9600
  //for ejection
  pinMode(PWME,OUTPUT);
  pinMode(DIRE,OUTPUT);
  myStepper.setSpeed(500);

  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(DIRA1, OUTPUT);
  pinMode(DIRB1, OUTPUT);
  pinMode(DIRA2, OUTPUT);
  pinMode(DIRB2, OUTPUT);

  pinMode(PWMAMP, OUTPUT);
  pinMode(DIRAMP, OUTPUT);

  //stepper motor
  pinMode(52,OUTPUT);pinMode(53,OUTPUT);
  pinMode(49,OUTPUT);
  pinMode(48,OUTPUT);
  pinMode(47,OUTPUT);
  pinMode(46,OUTPUT);
digitalWrite(53,HIGH);
digitalWrite(52,HIGH);
}

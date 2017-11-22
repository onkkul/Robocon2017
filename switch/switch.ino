#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>


Cytron_PS2Shield ps2(10,11); // SoftwareSerial: Rx and Tx pin


#define PS2_UP 0
#define PS2_DOWN 1
#define PS2_LEFT 2
#define PS2_RIGHT 3
#define PS2_TRIANGLE 4
#define PS2_CROSS 5
#define PS2_SQUARE 6
#define PS2_CIRCLE 7
#define PS2_LEFT_1 8
#define PS2_LEFT_2 9
#define PS2_RIGHT_1 10
#define PS2_RIGHT_2 11



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


void setup() {
  // put your setup code here, to run once:
 ps2.begin(115200); // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(115200); // Set monitor baudrate to 9600

pinMode(stepEn,OUTPUT);
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

void loop() {
int c=readButton(button);
Serial.println(c);
  // put your main code here, to run repeatedly:

}

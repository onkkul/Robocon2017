#define count 10
int encoderPin1 = 2;
int encoderPin2 = 3;
int pwm=8;
int dir=9;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;
int c=10;
long lastencoderValue = 0;
 
int lastMSB = 0;
int lastLSB = 0;

void setup() {
  Serial.begin (9600);
 pinMode(pwm,OUTPUT);
 pinMode(dir,OUTPUT);
 
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);
 
  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
 
  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);
  digitalWrite(pwm,250);
  digitalWrite(dir,HIGH);
    

}
 
void loop(){ 
  //Do stuff here
  
   Serial.println(digitalRead(count));

switch(count)
{
  case 0:   if(encoderValue>0 && encoderValue<2000)
            {
            digitalWrite(pwm,0);
            digitalWrite(dir,HIGH);
            }
            break;

  case 1:
  
              digitalWrite(pwm,0);
            digitalWrite(dir,HIGH);
            delay(1000);
             break;
  
  }
 /* if(encoderValue>0 && encoderValue<5500)
  {
  digitalWrite(pwm,250);
  digitalWrite(dir,HIGH);
    

    }
  if(encoderValue>5527)
  {
  digitalWrite(pwm,0);
  digitalWrite(dir,HIGH);
  delay(1000);

    }
    if(encoderValue>5527)
  {
  digitalWrite(pwm,250);
  digitalWrite(dir,LOW);
   delay(5000);
    }
    
   
 */
}
 
 
void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit
 
  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value
 
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
  {
    encoderValue ++;
  }
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
  {
    encoderValue --;
  }
  lastEncoded = encoded; //store this value for next time
}

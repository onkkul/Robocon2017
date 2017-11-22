#define pwm 6
#define ini 7

void setup() {
 
pinMode(pwm,OUTPUT);
pinMode(ini,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 analogWrite(pwm,255);
 digitalWrite(ini,HIGH);
}

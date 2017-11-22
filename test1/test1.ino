#define pwm1 A1
#define a 2
#define b 3
#define pwm2 A2
#define c 4
#define d 5
void setup()
{
  pinMode(pwm1, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(pwm2, OUTPUT);

}

void loop()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 255);
}

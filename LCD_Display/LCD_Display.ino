#include <LiquidCrystal.h>

#define EN 10
#define RW 8
#define RS 9

#define ampflow_dir 3

LiquidCrystal lcd1(RS, RW, EN ,7, 6, 5, 4);

const int analogInPin = A2;  // Analog input pin that the potentiometer is attached to
const int ampflow_pwm = 2;

int sensorValue, outputValue;       // value read from the pot

void setup()
{
  lcd1.begin(12, 2);
  Serial.begin(9600);
  lcd1.clear();
}

void loop()
{

  //digitalWrite(pw, HIGH);
   analogWrite(52,1500);

  sensorValue = analogRead(analogInPin);    // read the analog in value:
  Serial.println(sensorValue);

  outputValue = map(sensorValue, 0, 1023, 0, 255);    // map it to the range of the analog out:
  analogWrite(ampflow_pwm, outputValue); // change the analog out value:

  int rpm = map(outputValue, 0, 255, 0, 2750);

  Serial.print("sensor = ");
  Serial.println(sensorValue);
  Serial.print("output = ");
  Serial.println(outputValue);
  Serial.print("rpm = ");
  Serial.println(rpm);

  lcd1.setCursor(13, 1);
  lcd1.print("RPM");

  //  lcd1.setCursor(5, 0);

  lcd1.print(rpm);

  lcd1.setCursor(0,1);
  lcd1.print("RUTZ");
  delay(100);
  lcd1.clear();

}

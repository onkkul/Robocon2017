  
# define U1 32
# define U2 33
# define U3 34
# define U4 35
# define U5 36
# define U6 37
# define U7 38
# define U8 39

int ena=2;
int in1=3;
int in2=4;
int in3=5;
int in4=6;
int enb=7;


int inc;
int count;
void setup() {
  pinMode(U1,INPUT);
  pinMode(U2,INPUT);
  pinMode(U3,INPUT);
  pinMode(U4,INPUT);
  pinMode(U5,INPUT);
  pinMode(U6,INPUT);
  pinMode(U7,INPUT);
  pinMode(U8,INPUT);

  pinMode(ena,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(in4,OUTPUT);
   Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop()
{ /*Serial.println("\n");
  Serial.println(digitalRead(U1));
  Serial.println(digitalRead(U2));
  Serial.println(digitalRead(U3));
  Serial.println(digitalRead(U4));
  Serial.println(digitalRead(U5));
  Serial.println(digitalRead(U6));
  Serial.println(digitalRead(U7));
  Serial.println(digitalRead(U8));*/

   Serial.println("\n");
     Serial.println(count);
     Serial.println(inc);
    

  // put your main code here, to run repeatedly:
     

if(digitalRead(U1)==1 && digitalRead(U2)==1 ||digitalRead(U7)==1 && digitalRead(U8)==1)
{
    
   count++;
   delay(1000);
   }
 
if( digitalRead(U3)==0 && digitalRead(U4)==1 && digitalRead(U5)==1  && digitalRead(U6)==0 )
{
  digitalWrite(ena,255);
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(enb,255);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
  
  Serial.println("straight");
  }
  else if( digitalRead(U5)==1  && digitalRead(U6)==1)
  {
     digitalWrite(ena,255);
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(enb,10);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
  
      Serial.println("left");
    }
    else if( digitalRead(U3)==1  && digitalRead(U4)==1)
  {
      digitalWrite(ena,10);
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(enb,255);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
  
      Serial.println("right");
  }

 if(count==2)
 {
  do
  {
     digitalWrite(ena,255);
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(enb,255);
   digitalWrite(in3,LOW);
   digitalWrite(in4,HIGH);
  
     Serial.println("sahi chal raha hai tu");
  }while( digitalRead(U4)==1 && digitalRead(U5)==1 );
  }
  else if(count==3)
{
    Serial.println("abe pohach hi gaya bas");
}
  else if(count==4)
  {
    do
    {
     digitalWrite(ena,255);
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(enb,255);
   digitalWrite(in3,LOW);
   digitalWrite(in4,HIGH);
  
     Serial.println("chal na be");
  }while( digitalRead(U4)==1 && digitalRead(U5)==1 );
    
    }
     else if(count==5)
{
    Serial.println("pohochlana be");
}
  else if(count==6)
  {
    do
    {
         digitalWrite(ena,0);
        digitalWrite(enb,0);
  
     Serial.println("chal na be");
     delay(500);
    }
    while( digitalRead(U4)==1 && digitalRead(U5)==1 );
  
    }
       else if(count==7)
{
    Serial.println("pohochlana be");
}    
 }


int motorA1 =4;
int motorA2 = 5;
int motorB1 =6;
int motorB2 = 7;


int En1 =3;
int En2 = 9;
int i;
int led = 10;
char val;

void setup() {
  
pinMode(4,OUTPUT);   
pinMode(5,OUTPUT);   
pinMode(6,OUTPUT);   
pinMode(7,OUTPUT);   
pinMode(10,OUTPUT);

pinMode(3,OUTPUT);   H
pinMode(9,OUTPUT);

for (i=0;i<=5;i++)
{
  digitalWrite(10,HIGH);
  delay(1000);
  digitalWrite(10,LOW);
  delay(1000);
}
Serial.begin(9600);

 
}

void loop() {

  digitalWrite(10,HIGH);
 if(Serial.available() > 0){
    val = Serial.read();

 Serial.println(val);
 
   Stop(); 
      
          if (val == 'B'){
          forward();
          }
  
          else if (val == 'F'){
          back();
          }
  
          else if (val == 'R'){
          left();
          }
  
          else if (val == 'L'){
          right();
          }
         
          else if (val == 'S'){
          Stop();
          }
 
 }
}


void forward()
{
  digitalWrite(motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite(motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (En1,255);
  analogWrite (En2,255);
}
  
void back()
{
  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  analogWrite (En1,255);
  analogWrite (En2,255);
}
  
void left()
{
 digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite(motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (En1,255);
  analogWrite (En2,255);
}
  
void right()
{
digitalWrite(motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  analogWrite (En1,255);
  analogWrite (En2,255);
}
  

  
void Stop()
{
digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,LOW);                       
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,LOW);

  analogWrite (En1,0);
  analogWrite (En2,0);
}
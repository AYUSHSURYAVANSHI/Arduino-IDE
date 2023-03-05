int trig=10;
int echo=11;
int LED=13;
long distance;
long duration;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(20000);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10000);
  digitalWrite(trig,LOW);
 

duration = pulseIn(echo,HIGH);
distance = duration*0.034/2;
Serial.println(distance);
Serial.print("CM");
 if(distance<=10){
   digitalWrite(LED,LOW);

 }
 else{
   digitalWrite(LED, HIGH);
 }

}
void setup() {
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,INPUT);
}
void loop() {
  int eye = digitalRead(10);
  delay(2000);
  if (eye == HIGH) {
    delay(3000);
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(11,HIGH);
  } 
  
  else {
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
  }
}

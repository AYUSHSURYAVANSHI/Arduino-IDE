LM35 Temperature Sensor Code for Arduino Uno
const int lm35_pin = A1;	/* LM35 O/P pin */
const int trig = 10;
const int echo = 11;
long duration;
int distance;
void setup() {
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);	/* Read Temperature */
  temp_val = (temp_adc_val * 4.88);	/* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10);	/* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  delay(1000);

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo,HIGH);
  distance = duration * 0.034/2;
  Serial.println(distance);
 delay (100);
}

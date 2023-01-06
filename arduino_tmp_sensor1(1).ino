// Written by Emin Ayyıldız
int green_led1 = 8;
int green_led2 = 9;
int yellow_led = 10;
int orange_led = 11;
int red_led = 12;
int buzzer = 13;
int engine = 7;
const int sensorPin = A0;
float sicaklik_gerilim = 0;
float sicaklik = 0;
int rgb_red = 3;
int rgb_blue = 4;
int rgb_green = 5;

void setup()
{
  Serial.begin(9600);
  
  pinMode(green_led1, OUTPUT);
  pinMode(green_led2, OUTPUT);

  pinMode(yellow_led, OUTPUT);
  pinMode(orange_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(rgb_red, OUTPUT);
  pinMode(rgb_green, OUTPUT);
  pinMode(rgb_blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(engine, OUTPUT);
  
}

void loop()
{
  int sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value :");
  
  sicaklik_gerilim = (sensorValue / 1023.0)*5000;
  sicaklik = sicaklik_gerilim /10.0;
  Serial.println(sicaklik);
  
 if (sicaklik <=15)
  {
    digitalWrite(green_led1,LOW);
    digitalWrite(green_led2,LOW);
  	digitalWrite(yellow_led,LOW);
  	digitalWrite(orange_led,LOW);
  	digitalWrite(red_led,LOW);
  	noTone(buzzer);
  	digitalWrite(engine,LOW);
    digitalWrite(rgb_green,255);
    delay(500);
    digitalWrite(rgb_green,0);
    delay(500);
  }
  else if (sicaklik <=43)
  {
    digitalWrite(green_led1,HIGH);
    digitalWrite(green_led2,LOW);
  	digitalWrite(yellow_led,LOW);
  	digitalWrite(orange_led,LOW);
  	digitalWrite(red_led,LOW);
  	noTone(buzzer);
  	digitalWrite(engine,LOW);
    digitalWrite(rgb_green,255);
    delay(500);
    digitalWrite(rgb_green,0);
    delay(500);
    
  }
  else if (sicaklik <=76)
  {
    digitalWrite(green_led1,HIGH);
    digitalWrite(green_led2,HIGH);
  	digitalWrite(yellow_led,LOW);
  	digitalWrite(orange_led,LOW);
  	digitalWrite(red_led,LOW);
  	noTone(buzzer);
  	digitalWrite(engine,LOW);
    digitalWrite(rgb_green,255);
    delay(500);
    digitalWrite(rgb_green,0);
    delay(500);
  }
  else if (sicaklik <=109)
  {
    digitalWrite(green_led1,HIGH);
    digitalWrite(green_led2,HIGH);
  	digitalWrite(yellow_led,HIGH);
  	digitalWrite(orange_led,LOW);
  	digitalWrite(red_led,LOW);
  	noTone(buzzer);
  	digitalWrite(engine,LOW);
    digitalWrite(rgb_green,255);
    digitalWrite(rgb_red,255);
    delay(500);
    digitalWrite(rgb_green,0);
    digitalWrite(rgb_red,0);
    delay(500);
  }
 else if (sicaklik <=142)
  {
    digitalWrite(green_led1,HIGH);
    digitalWrite(green_led2,HIGH);
  	digitalWrite(yellow_led,HIGH);
  	digitalWrite(orange_led,HIGH);
  	digitalWrite(red_led,LOW);
  	tone(buzzer,440);
  	digitalWrite(engine,LOW);
    digitalWrite(rgb_green,128);
    digitalWrite(rgb_red,255);
    delay(500);
    digitalWrite(rgb_green,0);
    digitalWrite(rgb_red,0);
    delay(500);
  }
 else if (sicaklik <=180)
  { 
    Serial.println("Please atention!!! Fire Alarm");
    digitalWrite(green_led1,HIGH);
    digitalWrite(green_led2,HIGH);
  	digitalWrite(yellow_led,HIGH);
  	digitalWrite(orange_led,HIGH);
  	digitalWrite(red_led,HIGH);
    tone(buzzer, 440);
    delay(500);
    digitalWrite(green_led1,LOW);
    digitalWrite(green_led2,LOW);
  	digitalWrite(yellow_led,LOW);
  	digitalWrite(orange_led,LOW);
  	digitalWrite(red_led,LOW);
  	tone(buzzer,659);
    
  	digitalWrite(engine,HIGH);
    digitalWrite(rgb_red,255);
    delay(250);
    digitalWrite(rgb_red,0);
    digitalWrite(rgb_blue,255);
    delay(250);
    digitalWrite(rgb_blue,0);

  
  }
  

  
    
  
  
}

#include <LiquidCrystal_I2C.h>


#define LIGHT_SENSOR_PIN  33  
#define LED_PIN           13  
#define buzzer           27
#define echoPin 4 
#define trigPin 19  
long duration; 
int distance; 
  
LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
   pinMode(buzzer, OUTPUT);

  LCD.init();
  LCD.backlight();
  LCD.setCursor(1, 0);
  LCD.print("IOT SMART HOME");
  LCD.setCursor(3, 1);
  LCD.print("by akma");
  delay(5000);
  LCD.clear();

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 

  int LDRValue = analogRead(LIGHT_SENSOR_PIN);

  if (LDRValue < 600)
    digitalWrite(LED_PIN, HIGH); 
  else
    digitalWrite(LED_PIN, LOW);  
  
   if (distance< 200)
    digitalWrite(buzzer, HIGH); 
  else
    digitalWrite(buzzer, LOW);  


   LCD.setCursor(0,0);
   LCD.print("Distance: ");
   LCD.print(distance);
   LCD.println(" cm");
   LCD.setCursor(0,1);
   LCD.print("LDRValue: ");
   LCD.println(LDRValue);
   

   Serial.print("Distance: ");
   Serial.print(distance);
   Serial.println(" cm");
  
   Serial.print("LDRValue: ");
   Serial.println(LDRValue);

}




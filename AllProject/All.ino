#include <Servo.h>
Servo myservo;

#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd(0x27, 16, 2);

 
int trigPin = 13;
int echoPin = 12;
int servoPin = 9;
long duration, distance, average;
long aver[13]; 
 

double temp_amb;
double temp_obj;

void setup(){
    Serial.begin(9600);
    myservo.attach(servoPin);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myservo.write(0);
    delay(100);
    myservo.detach();

      Serial.println("Temperature Sensor MLX90614");

  lcd.init();
  lcd.backlight();


  mlx.begin();  
}


 int sensor = 0;
 void loop(){

digitalWrite(10,HIGH);
digitalWrite(trigPin,LOW);
delayMicroseconds(5);
digitalWrite(trigPin,HIGH);
delayMicroseconds(15);
digitalWrite(trigPin,LOW);
pinMode(echoPin,INPUT);

duration = pulseIn(echoPin,HIGH);
distance = duration * 0.034 / 2; 

     for (int sensor=0; sensor<=2; sensor++){ 
        
         aver[sensor] = distance;
         delay(10);
     }
    

     if (distance<=50){ 
         myservo.attach(servoPin);
         delay(1);
         myservo.write(0);
         delay(500);
         myservo.write(180);
         delay(500);
         myservo.detach();
     }
     Serial.print(distance);


      temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempC();

  lcd.setCursor(0,0);
  lcd.print("Room Temp :");
  lcd.setCursor(10,0);
  lcd.print(temp_amb);
  lcd.setCursor(15,0);
  lcd.write(1);
  lcd.setCursor(0,1);
  lcd.print("Object :");
  lcd.setCursor(10,1);
  lcd.print(temp_obj);
  lcd.setCursor(15,1);
  lcd.write(1);

  Serial.print("Room Temp = ");
  Serial.print(temp_amb);
  Serial.print("Object Temp = ");
  Serial.print(temp_obj);
 Serial.println();
delay(500);
 }

 









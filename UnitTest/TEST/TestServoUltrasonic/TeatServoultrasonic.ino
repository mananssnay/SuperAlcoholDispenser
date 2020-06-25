#include <Servo.h>
Servo myservo;
int trigPin = 13;
int echoPin = 12;
int servoPin = 6;
long duration, distance, average;
long aver[13]; 

void setup(){
    Serial.begin(9600);
    myservo.attach(servoPin);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myservo.write(0);
    delay(100);
    myservo.detach();
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
 }

 
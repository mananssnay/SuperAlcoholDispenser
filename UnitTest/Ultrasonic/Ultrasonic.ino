#define trigPin 13 
#define echoPin 12 
float duration, distance;

void setup(){
 Serial.begin(9600);
 pinMode(trigPin,OUTPUT); 
 pinMode(echoPin,INPUT); 
}

void loop() {
    digitalWrite(trigPin , LOW); //ตั้งค่าให้trigPinเป็นLOW
    delayMicroseconds(2);  //หน่วงสัญญาณให้ต่ำ
    digitalWrite(trigPin , HIGH); //trigPinเป็นHIGH
    delayMicroseconds(10); //หน่วงสัญญาณให้สูง
    digitalWrite(trigPin , LOW); //เสร็จสิ้นการกระตุ้นการส่งสัญญาณโดยทำให้มันต่ำ

    duration = pulseIn(echoPin, HIGH); 

    distance = duration * 0.034 / 2; 
                                    
    Serial.print("Distance =  ");
    if(distance >= 100 || distance <= 2) {  
        Serial.println("Out of rande");  
    }
    else {
        Serial.print(distance); 
        Serial.println("  cm");
        delay(500);
    }
    delay(500);
}
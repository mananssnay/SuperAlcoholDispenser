#define trigPin 13 //trigPin 13เชื่อมต่อกับarduino 
#define echoPin 12 //echoPin 12เชื่อมต่อกับarduino 
float duration, distance;

void setup(){
 Serial.begin(9600);
 pinMode(trigPin,OUTPUT); //ตั้งค่าtrigPinเป็นOutput
 pinMode(echoPin,INPUT);  //ตั้งค่าechoPinเป็นInput
}

void loop() {
    digitalWrite(trigPin , LOW); //ตั้งค่าให้trigPinเป็นLOW
    delayMicroseconds(2);  //หน่วงสัญญาณให้ต่ำ
    digitalWrite(trigPin , HIGH); //trigPinเป็นHIGH
    delayMicroseconds(10); //หน่วงสัญญาณให้สูง
    digitalWrite(trigPin , LOW); //เสร็จสิ้นการกระตุ้นการส่งสัญญาณโดยทำให้มันต่ำ

    duration = pulseIn(echoPin, HIGH); //วัดการตอบสนองจากHC-SR04

    distance = duration * 0.034 / 2; //กำหนดระยะทางจากระยะเวลา 
                                     //มีการส่งสัญญาณออกมาและการย้อนกลับดังนั้นระยะทางจึงหารด้วย2
                                     //ใช้343เมตร/วินาที ซึ่งเป็นความเร็วของเสียง

    Serial.print("Distance = ");   //ส่งผลไปยังมอนิเตอร์
    if(distance >= 100 || distance <= 2){  //กำหนดระยะของเซนเซอร์ไว้ที่100cm และต่ำสุด 2cm
        Serial.println("Out of rande");   //ดังนั้นการอ่านนอกจากที่กำหนดจึงเป็นค่าที่ไม่ถูกจะขึ้นคำว่า"Out of rande"
    }
    else {
        Serial.print(distance); //นอกเหนือจากคำสั่งที่กำหนดก็จะพิมพ์ค่าที่วัดระยะทางได้ออกมาเป็นcm
        Serial.println("  cm");
        delay(500);
    }
    delay(500);
}
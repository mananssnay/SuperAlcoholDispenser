#include <Servo.h> //นำเข้า library Servo เพื่อควบคุมเซอร์โว

Servo myservo; //เริ่มกำหนดตัว Servo เพื่อควบคุม


int sensor  = 0; //สร้างตัวแปรเพื่อตั้งค่าตำแหน่งของServo

void setup(){
    
     myservo.attach(9); //คำสั่งเพื่อบอกServoว่าเราได้เชื่อมต่อ arduino ที่่ขา pin9 แล้ว
                        //attach คือฟังก์ชันที่ใช้ในการกำหนดขาสัญญาณที่Servoต่อกับ arduino และกำหนดความกว้างที่พัลส์ที่ 0 องศาและ 180 องศา 
                        //พัลส์ คือ  คือสัญญาณเปิดปิดมีอยู่สองสภาวะคือ high และ low มีการทำซ้ำกันไปเรื่อยๆ ใช้ให้จังหวะเพื่อบอกเวลาหรือใช้ควบคุมความเร็วในการหมุนของมอเตอร์
}

void loop(){
    sensor = digitalRead(sensor);

    for(sensor=0; sensor<=180; sensor++){    //คำสั่งให้ตัวแปรหมุนจาก 0 องศา ไปจนถึง 180 องศา 
        myservo.write(sensor); //กำหนดตัวแปรของ servo
        delay(15);  //หน่วงเวลา 15ms เพื่อรอให้servoประมวลผลคำสั่ง
    }
    for(sensor=180; sensor>=0; sensor--){  //คำสั่งให้ตัวแปรหมุนจาก 180 องศา ไปจนถึง 0 องศา
    myservo.write(sensor);
    delay(15);
}
}
#include <Servo.h> 

Servo myservo; 


int sensor  = 0; 

void setup(){
    
     myservo.attach(9); 
                        
                        
}

void loop(){
    sensor = digitalRead(sensor);

    for(sensor=0; sensor<=180; sensor++){    
        myservo.write(sensor); 
        delay(15); 
    }
    for(sensor=180; sensor>=0; sensor--){  
    myservo.write(sensor);
    delay(15);
}
}
#if 0
// 1 - for test mode 
// 0 - for main 

#include "includefile.h"

int speed ; 

void setup(){
    Serial.begin(9600);
    motor_init();
    motor_run(1000,1000,1000,1000);
    
}
void loop(){
    if(Serial.available()!=0){
    Serial.println("enter speed");
    speed = Serial.parseInt();
    Serial.println(speed);
    Serial.flush();
    }
    motor_run(speed,1000,1000,1000);
}

#endif

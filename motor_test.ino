#if 0
// 1 - for test mode 
// 0 - for main 

#ifndef INCLUDEFILE_H
#include "includefile.h"
#endif

int speed ; 

void setup(){
    motor_init();
    rc_init();
    Serial.begin(9600);
}
void loop(){
    if(Serial.available()!=0){
    Serial.println("enter speed");
    speed = Serial.parseInt();
    Serial.println(speed);
    Serial.flush();
    }
    motor_run(speed,speed,speed,speed);
}

#endif

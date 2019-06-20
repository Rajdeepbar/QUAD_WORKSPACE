#ifndef INCLUDEFILE_H
#include "includefile.h"
#endif

struct RECIEVER {
    int yaw,pitch,roll,throttle;
}reciever;

//----------------motor speed-----------------------
int m0=1000;
int m1=1000;
int m2=1000;
int m3=1000;

#if 1

void setup(){
    Serial.begin(9600);
    motor_init();
    //mpu_init();
    rc_init();
}
void loop(){
    //mpu_get_data();
    rc_get_data();
    update_control();
    motor_run(m0,m1,m2,m3);
    Serial.print("m0:");Serial.print(m0);
    Serial.print("| m1:");Serial.print(m1);
    Serial.print("| m2:");Serial.print(m2);
    Serial.print("| m3:");Serial.print(m3);
    Serial.print("\n");
}

#endif

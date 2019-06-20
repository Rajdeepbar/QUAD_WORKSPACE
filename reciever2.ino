#ifndef INCLUDEFILE_H
#include "includefile.h"
#endif

void rc_init(){
    pinMode(yaw_pin,INPUT);
    pinMode(pitch_pin,INPUT);
    pinMode(roll_pin,INPUT);
    pinMode(throttle_pin,INPUT);
}

void rc_get_data(){
    reciever.yaw=pulseIn(yaw_pin,HIGH);
    reciever.pitch=pulseIn(pitch_pin,HIGH);
    reciever.roll=pulseIn(roll_pin,HIGH);
    reciever.throttle=pulseIn(throttle_pin,HIGH);
    reciever.yaw=map(reciever.yaw,1120,1860,-5,5);
    reciever.yaw++;
    reciever.pitch=map(reciever.pitch,1170,1825,-5,5);
    reciever.pitch++;
    reciever.roll=map(reciever.roll,1125,1895,-5,5);
    reciever.roll++;
    reciever.throttle=map(reciever.throttle,1180,1790,10,20);
    if(reciever.throttle==-9){
        reciever.throttle=10;
        reciever.yaw=0;
        reciever.pitch=0;
        reciever.roll=0;
    }
}

void rc_print_data(){
    Serial.print("Yaw:");Serial.print(reciever.yaw);
    Serial.print("| Pitch:");Serial.print(reciever.pitch);
    Serial.print("| Roll:");Serial.print(reciever.roll);
    Serial.print("| Throttle:");Serial.print(reciever.throttle);
    Serial.print("\n");
}

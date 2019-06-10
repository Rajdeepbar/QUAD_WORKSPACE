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
    reciever.yaw=pulseIn(yaw_pin,HIGH,2000);
    reciever.pitch=pulseIn(pitch_pin,HIGH,2000);
    reciever.roll=pulseIn(roll_pin,HIGH,2000);
    reciever.throttle=pulseIn(throttle_pin,HIGH,2000);
    reciever.yaw=map(reciever.yaw,1300,1700,-10,10);
    reciever.pitch=map(reciever.pitch,1300,1700,-10,10);
    reciever.roll=map(reciever.roll,1300,1700,-10,10);
    reciever.throttle=map(reciever.throttle,1300,1700,-10,10);
}

void rc_print_data(){
    Serial.print("CH1:");Serial.print(reciever.yaw);
    Serial.print("| CH2:");Serial.print(reciever.pitch);
    Serial.print("| CH3:");Serial.print(reciever.roll);
    Serial.print("| CH4:");Serial.print(reciever.throttle);
    Serial.print("\n");
}
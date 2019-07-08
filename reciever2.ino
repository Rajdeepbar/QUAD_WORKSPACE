#include "includefile.h"

void rc_init(){
    pinMode(yaw_pin,INPUT);
    pinMode(pitch_pin,INPUT);
    pinMode(roll_pin,INPUT);
    pinMode(throttle_pin,INPUT);
}

void rc_get_data(){
    rx.roll=pulseIn(roll_pin,HIGH);
    rx.pitch=pulseIn(pitch_pin,HIGH);
    rx.throttle=pulseIn(throttle_pin,HIGH);
    rx.yaw=pulseIn(yaw_pin,HIGH);
/*
    rx.roll=map(rx.roll,RX1_MIN,RX1_MAX,-5,5);
    rx.roll++;
    rx.pitch=map(rx.pitch,RX2_MIN,RX2_MAX,-5,5);
    rx.pitch++;
    rx.throttle=map(rx.throttle,RX3_MIN,RX3_MAX,1000,2000);
    rx.yaw=map(rx.yaw,RX4_MIN,RX4_MAX,-5,5);
    rx.yaw++;

    if(rx.throttle<1100){
        rx.throttle=1000;
        rx.yaw=0;
        rx.pitch=0;
        rx.roll=0;
    }
    */
}

void rc_print_data(){
    Serial.print("Yaw:");Serial.print(rx.yaw);
    Serial.print("| Pitch:");Serial.print(rx.pitch);
    Serial.print("| Roll:");Serial.print(rx.roll);
    Serial.print("| Throttle:");Serial.print(rx.throttle);
    Serial.print("\n");
}

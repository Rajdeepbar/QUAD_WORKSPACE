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

#if 0

void setup(){
    motor_init();
    mpu_init();
    rc_init();
}
void loop(){
    mpu_get_data();
    rc_get_data();
    update_control();
    motor_run(motor_FL,motor_FR,motor_BR,motor_BL);
}

#endif

/*
####### Main Code for Quadcopter #######\
Author: Rajdeep Barman
mail  : rajdeep.flamestorm@gmail.com

note - make sure that preprocessor tag is written 1 for this file and 0 for test files.
The Mpu needs to be aligned properly with the body for this code to work properly. (the tedious calculations are not done yet).
 */

#include "includefile.h"
struct RECIEVER {
    int yaw,pitch,roll,throttle;
}rx;

//----------------motor speed-----------------------
int m0=1000;
int m1=1000;
int m2=1000;
int m3=1000;

#if 1

void setup(){
    //Serial.begin(9600);
    motor_init();
   // mpu_init();
    rc_init();
}
void loop(){
  //  mpu_get_data();
    rc_get_data();
    update_control();
    motor_run(m0,m1,m2,m3);
    /*
    Serial.print("m0:");Serial.print(m0);
    Serial.print("| m1:");Serial.print(m1);
    Serial.print("| m2:");Serial.print(m2);
    Serial.print("| m3:");Serial.print(m3);
    Serial.print("\n");
    */
}

#endif

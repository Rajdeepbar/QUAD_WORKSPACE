#include "includefile.h"
void motor_init(){
    
    //create servo objects
    Servo motor0;    
    Servo motor1;    
    Servo motor2;    
    Servo motor3;

    //write pwm pulse to esc
    motor0.writeMicroseconds(m0);
    motor1.writeMicroseconds(m1);
    motor2.writeMicroseconds(m2);
    motor3.writeMicroseconds(m3);

    }

void motor_run(int s0,int s1,int s2,int s3){
    motor0.writeMicroseconds(m0);
    motor1.writeMicroseconds(m1);
    motor2.writeMicroseconds(m2);
    motor3.writeMicroseconds(m3);
}
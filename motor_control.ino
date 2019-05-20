#include "includefile.h"

//----------------motor speed-----------------------
int m0=1000;
int m1=1000;
int m2=1000;
int m3=1000;

    //create servo objects
    Servo motor0;    
    Servo motor1;    
    Servo motor2;    
    Servo motor3;

void motor_init(){

    //attach pins
    motor0.attach(motor_pin_0);
    motor1.attach(motor_pin_1);
    motor2.attach(motor_pin_2);
    motor3.attach(motor_pin_3);

    //write pwm pulse to esc
    motor0.writeMicroseconds(m0);
    motor1.writeMicroseconds(m1);
    motor2.writeMicroseconds(m2);
    motor3.writeMicroseconds(m3);
    }


void motor_run(int s0,int s1,int s2,int s3){
    motor0.writeMicroseconds(s0);
    motor1.writeMicroseconds(s1);
    motor2.writeMicroseconds(s2);
    motor3.writeMicroseconds(s3);
}
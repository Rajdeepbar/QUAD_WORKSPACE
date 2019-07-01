#include "includefile.h"

//--------------create servo objects----------------
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
    motor0.writeMicroseconds(min_speed);
    motor1.writeMicroseconds(min_speed);
    motor2.writeMicroseconds(min_speed);
    motor3.writeMicroseconds(min_speed);

    delay(5000);
    }

//motor speed FL
//motor speed FR
//motor speed BR
//motor speed FL
void motor_run(int s0,int s1,int s2,int s3){
    motor0.writeMicroseconds(s0);
    motor1.writeMicroseconds(s1);
    motor2.writeMicroseconds(s2);
    motor3.writeMicroseconds(s3);
}

void motor_stop(){
    motor0.writeMicroseconds(1000);
    motor1.writeMicroseconds(1000);
    motor2.writeMicroseconds(1000);
    motor3.writeMicroseconds(1000);
}

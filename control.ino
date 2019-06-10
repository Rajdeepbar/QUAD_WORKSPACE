#ifndef INCLUDEFILE_H
#include "includefile.h"
#endif
//--------------------------control constants-------------------------
const float yaw_constant = 1;
const float pitch_constant = 1;
const float roll_constant = 1;
const float throttle_constant = 1;

void update_control(){
    motor_FR = throttle_constant*reciever.throttle + pitch_constant*reciever.pitch + roll_constant*reciever.roll + yaw_constant*reciever.yaw;
    motor_FL = throttle_constant*reciever.throttle + pitch_constant*reciever.pitch - roll_constant*reciever.roll - yaw_constant*reciever.yaw;
    motor_BR = throttle_constant*reciever.throttle - pitch_constant*reciever.pitch + roll_constant*reciever.roll - yaw_constant*reciever.yaw;
    motor_BL = throttle_constant*reciever.throttle - pitch_constant*reciever.pitch - roll_constant*reciever.roll + yaw_constant*reciever.yaw;
}

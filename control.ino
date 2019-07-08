#include "includefile.h"
//--------------------------control constants-------------------------
const float yaw_constant = 20;
const float pitch_constant = -20;
const float roll_constant = -20;
const float throttle_constant = 100;

struct SETPOINT
{
    int Ax,Ay,Az,Gx,Gy,Gz;
}setpoint;

void update_control(){
  /*  if((rx.pitch==0)&&(rx.roll==0)&&(rx.yaw==0)){
        setpoint.Ax=0;
        setpoint.Ay=0;
        setpoint.Gx=0;
        setpoint.Gy=0;
        setpoint.Gz=0;
    }
    else{
        setpoint.Gz=rx.yaw;
        setpoint.Gx=rx.roll;
        setpoint.Gy=rx.pitch;
    }
*/

    motor_FR = throttle_constant*rx.throttle + pitch_constant*rx.pitch + roll_constant*rx.roll + yaw_constant*rx.yaw;
    motor_FL = throttle_constant*rx.throttle + pitch_constant*rx.pitch - roll_constant*rx.roll - yaw_constant*rx.yaw;
    motor_BR = throttle_constant*rx.throttle - pitch_constant*rx.pitch + roll_constant*rx.roll - yaw_constant*rx.yaw + 50;
    motor_BL = throttle_constant*rx.throttle - pitch_constant*rx.pitch - roll_constant*rx.roll + yaw_constant*rx.yaw + 60;
}

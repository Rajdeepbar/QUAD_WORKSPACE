#include "includefile.h"

//--------------------------control constants-------------------------
const float yaw_constant = 1;
const float pitch_constant = 1;
const float roll_constant = 1;
const float throttle_constant = 1;

void update_control(){
    motor_FR = throttle_constant*rx_signal.throttle + pitch_constant*rx_signal.pitch + roll_constant*rx_signal.roll + yaw_constant*rx_signal.yaw;
    motor_FL = throttle_constant*rx_signal.throttle + pitch_constant*rx_signal.pitch - roll_constant*rx_signal.roll - yaw_constant*rx_signal.yaw;
    motor_BR = throttle_constant*rx_signal.throttle - pitch_constant*rx_signal.pitch + roll_constant*rx_signal.roll - yaw_constant*rx_signal.yaw;
    motor_BL = throttle_constant*rx_signal.throttle - pitch_constant*rx_signal.pitch - roll_constant*rx_signal.roll + yaw_constant*rx_signal.yaw;
}

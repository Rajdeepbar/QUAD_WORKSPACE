#if 1
#include "includefile.h"

void setup(){
    motor_init();
    mpu_init();
    reciever_init();
}
void loop(){
    motor_run(1200,1200,1200,1200);
}

#endif

#if 1
#include "includefile.h"

void setup(){
    motor_init();
    mpu_init();
    reciever_init();
}
void loop(){
    mpu_get_data();
    update_control();
    motor_run(motor_FL,motor_FR,motor_BR,motor_BL);
}

#endif

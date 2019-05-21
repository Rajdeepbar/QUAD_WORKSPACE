#if 1
// 1 - for test mode 
// 0 - for main 

#include "includefile.h"

int speed ; 

void setup(){
    Serial.begin(9600);
    mpu_init();
    
}
void loop(){
    mpu_get_data();
    mpu_print_gyro();
}

#endif

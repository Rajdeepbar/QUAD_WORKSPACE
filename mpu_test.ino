#if 0
// 1 - for test mode 
// 0 - for main 


#include "includefile.h"

int speed ; 

void setup(){
    Serial.begin(38400);
    mpu_init();
    mpu_set_offset(400,300,2000,-20,100,120);
    
}
void loop(){
    mpu_get_data();
    mpu_print_data();
}

#endif

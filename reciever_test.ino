#if 0
// 1 - for test mode 
// 0 - for main 

#include "includefile.h"
 
void setup(){
    Serial.begin(38400);
    rc_init();   
}
void loop(){
    rc_get_data();
    rc_print_data();
}

#endif

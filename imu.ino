#include "includefile.h"

//---------------MPU6050----------------------------------------
int mpu_addr = 0x68; //with AD0 pulled down
uint16_t mpu_pwr_1 = 0x6B; //power management 1

//intiate i2c as master
void mpu_init()
{
    Wire.begin();
    Wire.beginTransmission(mpu_addr);
    Wire.write(mpu_pwr_1); 
    Wire.write(0x08); //sleep mode off + temp sensor disabled
    Wire.endTransmission(1);
}





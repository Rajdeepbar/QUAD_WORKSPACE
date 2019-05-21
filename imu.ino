#include "includefile.h"

//---------------MPU6050----------------------------------------
int mpu_addr = 0x68; //with AD0 pulled down
uint16_t mpu_pwr_1 = 0x6B; //register address of PWR_MGMT_1
uint16_t accel_start = 0x3B; //register address of ACCEL_XOUT_H
uint16_t gyro_start =0x43; //register address of GYRO_XOUT_H

int16_t Ax,Ay,Az,Gx,Gy,Gz;

void mpu_init()
{
    Wire.begin();
    Wire.beginTransmission(mpu_addr);
    Wire.write(mpu_pwr_1); 
    Wire.write(0x08); //sleep mode off + temp sensor disabled
    Wire.endTransmission(1);
}


void mpu_get_data(){
    Wire.beginTransmission(mpu_addr);
    Wire.write(accel_start);
    Wire.endTransmission(false);
    Wire.requestFrom(mpu_addr,6);
    Ax=(Wire.read()<<8)|Wire.read();
    Ay=(Wire.read()<<8)|Wire.read();
    Az=(Wire.read()<<8)|Wire.read();

    Wire.write(gyro_start);
    Wire.endTransmission(false);
    Wire.requestFrom(mpu_addr,6);
    Gx=(Wire.read()<<8)|Wire.read();
    Gy=(Wire.read()<<8)|Wire.read();
    Gz=(Wire.read()<<8)|Wire.read();
}

void mpu_print_accel(){
    Serial.print("Ax =");Serial.print(Ax);
    Serial.print("| Ay =");Serial.print(Ay);
    Serial.print("| Az =");Serial.print(Az);
    Serial.print("\n");
}

void mpu_print_gyro(){
    Serial.print("Gx =");Serial.print(Gx);
    Serial.print("| Gy =");Serial.print(Gy);
    Serial.print("| Gz =");Serial.print(Gz);
    Serial.print("\n");
}

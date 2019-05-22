#include "includefile.h"
/* #####################################################################################
    Library for single MPU6050
    Author : Rajdeep
    Based on wire Library.
   ######################################################################################

//-----------------------------MPU6050 registers----------------------------------------
int MPU_ADDR = 0x68; //with AD0 pulled down
uint16_t PWR_MGMT_1 = 0x6B;   //register address of PWR_MGMT_1
uint16_t ACCEL_XOUT_H = 0x3B; //register address of ACCEL_XOUT_H
uint16_t GYRO_XOUT_H =0x43;   //register address of GYRO_XOUT_H
uint16_t GYRO_CONFIG = 0x1B; //gyro config register address
uint16_t ACCEL_CONFIG =0x1C;  //accel config register address

//-----------------------------data for registers -----------------------------------
uint16_t pwr_mgmt_1 = 0x08;

uint16_t gyro_config = 0x00;
        /*  values for gyro_config:
            0x00 for +/- 250 degree/sec
            0x0F for +/- 500 degree/sec
            0x10 for +/- 1000 degree/sec
            0x1F for +/- 2000 degree/sec
        */

uint16_t accel_config = 0x00;
        /*  values for accel_config:
            0x00 for +/- 2g
            0x0F for +/- 4g
            0x10 for +/- 8g
            0x1F for +/- 16g
        */

//---------------------------------structures for data ---------------------------------

struct MPU_RAW_DATA{
    int16_t Ax,Ay,Az,Gx,Gy,Gz,temp;
}mpu_offset,mpu_raw_data;

struct MPU_DATA{
    float Ax,Ay,Az,Gx,Gy,Gz,temp;
}mpu_data;

struct MPU_CONSTANT{
    float accel;
    float gyro;
}mpu_constant;

//--------------function definations ---------------------------

void mpu_init()
{
    Wire.begin();
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(PWR_MGMT_1); 
    Wire.write(pwr_mgmt_1); //sleep mode off + temp sensor disabled
    Wire.endTransmission(1);
    mpu_set_constant();
}


void mpu_get_raw_data(){
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(ACCEL_XOUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_ADDR,14);
    mpu_raw_data.Ax=(Wire.read()<<8)|Wire.read();
    mpu_raw_data.Ay=(Wire.read()<<8)|Wire.read();
    mpu_raw_data.Az=(Wire.read()<<8)|Wire.read();
    mpu_raw_data.temp=(Wire.read()<<8)|Wire.read();
    mpu_raw_data.Gx=(Wire.read()<<8)|Wire.read();
    mpu_raw_data.Gy=(Wire.read()<<8)|Wire.read();
    mpu_raw_data.Gz=(Wire.read()<<8)|Wire.read();
}


void mpu_set_constant(){
    switch(accel_config){
        case 0x00 : mpu_constant.accel = 16348;
                    break;
        case 0x0F : mpu_constant.accel = 8192;
                    break;
        case 0x10 : mpu_constant.accel = 4096;
                    break;
        case 0x1F : mpu_constant.accel = 2048;
                    break;
    }

    switch (gyro_config)
    {
        case 0x00 : mpu_constant.gyro=131;
                    break;
        case 0x0F : mpu_constant.gyro=65.5;
                    break;
        case 0x10 : mpu_constant.gyro=32.8;
                    break;
        case 0x1F : mpu_constant.gyro=16.4;
                    break;
    }
}

void mpu_get_data(){
    mpu_get_raw_data();
    mpu_data.Ax = (mpu_raw_data.Ax-mpu_offset.Ax)/mpu_constant.accel;
    mpu_data.Ay = (mpu_raw_data.Ay-mpu_offset.Ay)/mpu_constant.accel;
    mpu_data.Az = (mpu_raw_data.Az-mpu_offset.Az)/mpu_constant.accel;
    mpu_data.Gx = (mpu_raw_data.Gx-mpu_offset.Gx)/mpu_constant.gyro;
    mpu_data.Gy = (mpu_raw_data.Gy-mpu_offset.Gy)/mpu_constant.gyro;
    mpu_data.Gz = (mpu_raw_data.Gz-mpu_offset.Gz)/mpu_constant.gyro;
     
}

void mpu_set_offset(int offset_Ax,int offset_Ay,int offset_Az,int offset_Gx,int offset_Gy,int offset_Gz){
    mpu_offset.Ax=offset_Ax;
    mpu_offset.Ay=offset_Ay;
    mpu_offset.Az=offset_Az;
    mpu_offset.Gx=offset_Gx;
    mpu_offset.Gy=offset_Gy;
    mpu_offset.Gz=offset_Gz;
}

void mpu_print_accel(){
    Serial.print("Ax =");Serial.print(mpu_data.Ax);
    Serial.print("| Ay =");Serial.print(mpu_data.Ay);
    Serial.print("| Az =");Serial.print(mpu_data.Az);
    Serial.print("\n");
}

void mpu_print_gyro(){
    Serial.print("Gx =");Serial.print(mpu_data.Gx);
    Serial.print("| Gy =");Serial.print(mpu_data.Gy);
    Serial.print("| Gz =");Serial.print(mpu_data.Gz);
    Serial.print("\n");
}

void mpu_print_data(){
    Serial.print("Ax =");Serial.print(mpu_data.Ax);
    Serial.print("| Ay =");Serial.print(mpu_data.Ay);
    Serial.print("| Az =");Serial.print(mpu_data.Az);
    Serial.print("Gx =");Serial.print(mpu_data.Gx);
    Serial.print("\t \t");
    Serial.print("| Gy =");Serial.print(mpu_data.Gy);
    Serial.print("| Gz =");Serial.print(mpu_data.Gz);
    Serial.print("\n");
}

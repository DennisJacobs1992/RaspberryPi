#include <iostream>
#include "MPU9250.h"

using namespace stf;

MPU9250::MPU9250(){
    //tbd
}

void MPU9250::readSensorValues(double &n){
    /*int val = (wiringPiI2CReadReg8(fd, Mpu6050Addr) << 8) +  wiringPiI2CReadReg8(fd, Mpu6050Addr+1);
    if (val >= 0x8000)
    val = -(65536 - val);
    return val;*/
}

void MPU9250::calculateSensorValue(double &n){

}
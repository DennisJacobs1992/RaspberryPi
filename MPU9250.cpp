#include <iostream>
#include "MPU9250.h"
#include <wiringPiI2C.h>

using namespace std;

MPU9250::MPU9250(){
    //tbd
}

void MPU9250::readSensorValue(int &fd, int addr,double &value){
    value = (wiringPiI2CReadReg8(fd, addr) << 8) +  wiringPiI2CReadReg8(fd, addr+1);
    if (value >= 0x8000)
    {
        value = -(65536 - value);
    }
}

void MPU9250::calculateSensorValue(double &n){

}
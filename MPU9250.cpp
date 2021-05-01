#include <iostream>
#include "MPU9250.h"
#include <wiringPiI2C.h>

using namespace std;

MPU9250::MPU9250(){
    //tbd
}

void MPU9250::readSensorValue(int &fd,double &value){
    
    char MPU9250register = 0x3B;
    char arrayIndex = 0;
    
    while(MPU9250register<73){ //While register addres did not exceed the last wanted register value, keep getting values
        value[arrayIndex] = (wiringPiI2CReadReg8(fd, MPU9250register) << 8) +  wiringPiI2CReadReg8(fd, MPU9250register+1);
        
        if (value[arrayIndex] >= 0x8000)
        {
            value[arrayIndex] = -(65536 - value[arrayIndex]);
        }

        if (MPU9250register<65){ //Depending on what data is read, transfer from raw to real value
            value[arrayIndex]/=16384;
        }else if (MPU9250register<67){
            value[arrayIndex] = (value[arrayIndex]/340) + 36.53;
        }else{
            value[arrayIndex]/=131;
        }

        MPU9250register+=2;
        arrayIndex++;
    }
}

void MPU9250::calculateSensorValue(double &n){

}
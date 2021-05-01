#include <iostream>
#include "MPU9250.h"
#include <wiringPiI2C.h>

using namespace std;

MPU9250::MPU9250(){
    //tbd
}

void MPU9250::readSensorValue(int &fd,double (&MPU9250ValueArray)[7]){
    
    int MPU9250register = 0x3B;
    int arrayIndex = 0;
    
    while(MPU9250register<73){ //While register addres did not exceed the last wanted register value, keep getting values
        MPU9250ValueArray[arrayIndex] = (wiringPiI2CReadReg8(fd, MPU9250register) << 8) +  wiringPiI2CReadReg8(fd, MPU9250register+1);
        
        if (MPU9250ValueArray[arrayIndex] >= 0x8000)
        {
            MPU9250ValueArray[arrayIndex] = -(65536 - MPU9250ValueArray[arrayIndex]);
        }

        if (MPU9250register<65){ //Depending on what data is read, transfer from raw to real value
            MPU9250ValueArray[arrayIndex]/=16384;
        }else if (MPU9250register<67){
            MPU9250ValueArray[arrayIndex] = (MPU9250ValueArray[arrayIndex]/340) + 36.53;
        }else{
            MPU9250ValueArray[arrayIndex]/=131;
        }

        MPU9250register+=2;
        arrayIndex++;
    }
}

void MPU9250::printAllSensorValues(double (&value)[7]){
        cout << "*** MPU9250 Sensor Values ***\n";
        cout << "Acceleration X: " << (MPU9250ValueArray[0]) << endl;
        cout << "Acceleration Y: " << (MPU9250ValueArray[1]) << endl;
        cout << "Acceleration Z: " << (MPU9250ValueArray[2]) << endl;
        cout << "Gyro X: " << (MPU9250ValueArray[4]) << endl;
        cout << "Gyro Y: " << (MPU9250ValueArray[5]) << endl;
        cout << "Gyro Z: " << (MPU9250ValueArray[6]) << endl;
        cout << "Temp : " << (MPU9250ValueArray[3]) << " degree celsius\n";
        cout << "*****************************\n";

}
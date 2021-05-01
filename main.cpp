#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <time.h>
#include <thread>
#include "MPU9250.h"
#include "MPU9250.cpp"
#include "ESC.h"

using namespace std;

int fd;
double MPU9250Values[7];
long int ldrValues[4];

void initBoard(){
    //Config I2C bus
    wiringPiSetup();
    fd = wiringPiI2CSetup (0x68);             //Initialize i2c system. returns
    wiringPiI2CWriteReg8 (fd, 0x6B, 0x00);    //disable sleep mode of GY-6050 sensor module (MPU-6050)
    cout << "I2C bus is initialized\n";

    /*
    //config ldr pins (0,1,2,3)
    pinMode(0, INPUT);
    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    cout << "LDR pins configured\n";
    */
}

void quadCntrl(){

}

void Sim7600X4GHatCntrl(){
    //TBD
}

int main (void)
{
    cout << "Main function executed\n";

    //initialize board
    initBoard();
    
    /*
    //auto enable threads
    thread quadCntrlT(quadCntrl);
    quadCnrtT.detac();

    thread Sim7600X4GHatCntrlT(Sim7600X4GHatCntrl);
    Sim7600X4GHatCntrlT.detach();
    */

    while(1)
    {
        cout << "While loop executed\n";
        MPU9250 MPU9250object;
        MPU9250object.readSensorValue(fd, MPU9250Values);
        cout << "Acceleration X: " << (MPU9250Values[0]/16384) << endl;
        cout << "Acceleration Y: " << (MPU9250Values[1]/16384) << endl;
        cout << "Acceleration Z: " << (MPU9250Values[2]/16384) << endl;
        cout << "Gyro X: " << (MPU9250Values[4]/131) << endl;
        cout << "Gyro Y: " << (MPU9250Values[5]/131) << endl;
        cout << "Gyro Z: " << (MPU9250Values[6]/131) << endl;
        cout << "Temp : " << (MPU9250Values[3]/131) << " degree celsius\n";
        
        /*
        // Readout and scale temperature measurementsensor values (in degree celsius)
        temp = readMPU6050(0x41);
        temp = (temp/340) + 36.53;
        // Readout and scale accelerometer measurements (full scale range +/- 2g)
        accX = readMPU6050(0x3B);
        accX = accX/16384;
        accY = readMPU6050(0x3D);
        accY = accY/16384;
        accZ = readMPU6050(0x3F);
        accZ = accZ/16384;
        // Readout and scale gyroscope measurements (full scale range +/- 250 degrees/second)
        gyroX = readMPU6050(0x43);
        gyroX = gyroX/131;
        gyroY = readMPU6050(0x45);
        gyroY = gyroY/131;
        gyroZ = readMPU6050(0x47);
        gyroZ = gyroZ/131;
        cout << "Temperature: " << temp << " degree celsius\n";
        
        cout << "Acceleration X: " << accX << "\n";
        cout << "Acceleration Y: " << accY << "\n";
        cout << "Acceleration Z: " << accZ << "\n";
        cout << "Gyro X: " << gyroX << "\n";
        cout << "Gyro Y: " << gyroY << "\n";
        cout << "Gyro Z: " << gyroZ << "\n";
        */
        break;
    }

    return 0;    
}
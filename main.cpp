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
    MPU9250 MPU9250object;
    MPU9250object.readSensorValue(fd, MPU9250Values);
    MPU9250object.printAllSensorValues(MPU9250Values);
}

void Sim7600X4GHatCntrl(){
    //TBD
}

int main (void)
{
    cout << "Main function executed\n";

    //initialize board
    initBoard();
    
    //auto enable threads
    thread quadCntrlT(quadCntrl);
    //quadCnrtT.detac();

    /*
    thread Sim7600X4GHatCntrlT(Sim7600X4GHatCntrl);
    Sim7600X4GHatCntrlT.detach();
    */

    while(1)
    {
        cout << "While loop executed\n";
        quadCntrl.join();


        break;
    }

    return 0;    
}
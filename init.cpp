#include <iostream>
#include "INIT.h"
#include <wiringPi.h>

using namespace std;

#define LDR_1 3
//#define LDR_2 15
//#define LDR_3 15
//#define LDR_4 15

INIT::INIT(){

}

void INIT::initGpio(int &fd){
    cout << "System initialization started\n";
    //Config I2C bus
    wiringPiSetup();
    fd = wiringPiI2CSetup (0x68);             //Initialize i2c system. returns
    wiringPiI2CWriteReg8 (fd, 0x6B, 0x00);    //disable sleep mode of GY-6050 sensor module (MPU-6050)

    //config ldr pins (0,1,2,3)
    pinMode(LDR_1, INPUT);
    //pinMode(1, INPUT);
    //pinMode(2, INPUT);
    //pinMode(3, INPUT);
    //cout << "LDR pins configured\n";

    cout << "System initialization ended\n";
}
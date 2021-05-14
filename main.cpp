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
#include "init.h"

using namespace std;

int fd;

double MPU9250Values[7];
long int ldrValues[4];

void quadCntrl(){
    MPU9250 MPU9250Object;
    MPU9250Object.readSensorValue(fd, MPU9250Values);
    MPU9250Object.printAllSensorValues(MPU9250Values);
}

void Sim7600X4GHatCntrl(){
    //TBD
}

int main (void)
{
    cout << "Main function executed\n";

    //initialize board
    init initObject;
    initObject.initGpio(fd);
    
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
        quadCntrlT.join();

        break;
    }

    return 0;    
}
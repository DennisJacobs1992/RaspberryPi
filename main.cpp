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
#include "init.cpp"
#include "LDR.h"
#include "LDR.cpp"

using namespace std;

int fd;

double MPU9250Values[7];
long int ldrValues[4];

void quadCntrl(){
    MPU9250 MPU9250Object;
    MPU9250Object.readSensorValue(fd, MPU9250Values);
    MPU9250Object.printAllSensorValues(MPU9250Values);
}

void solarCntrl(){
    LDR LDRObject;
    LDRObject.getLDRValues();

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
    //thread solarCntrlT(solarCntrl);
    //quadCnrtT.detac();

    /*
    thread Sim7600X4GHatCntrlT(Sim7600X4GHatCntrl);
    Sim7600X4GHatCntrlT.detach();
    */

    while(1)
    {
        cout << "While loop executed\n";
        quadCntrlT.join();
        //solarCntrlT();

        break;
    }

    return 0;    
}
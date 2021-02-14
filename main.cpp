#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <wiringPiI2C.h>

using namespace std;

void ConfigPWMGPIO(int PwmGpioPin)
{
    pinMode(PwmGpioPin,OUTPUT);
    digitalWrite(PwmGpioPin,LOW);
    softPwmCreate(PwmGpioPin,0,100);
}

int readGyroSensor(int fd, int reg)
{
    wiringPiI2CReadReg8(fd, reg);
    return wiringPiI2CReadReg8(fd, reg);
}

int main (void)
{
    //initialize
    wiringPiSetup();
    wiringPiI2CSetup(0x68);

    cout << "I am executed\n"; 

    cout << readGyroSensor();

    //configure PWM channels
    ConfigPWMGPIO(11);
    ConfigPWMGPIO(13);
    ConfigPWMGPIO(15);
    ConfigPWMGPIO(16);
 
    //while(1)
    //{
        //softPwmWrite(11, 15);
        //softPwmWrite(13, 15);
        //softPwmWrite(15, 15);
        //softPwmWrite(16, 15);
    //}
 
    return 0;    
}
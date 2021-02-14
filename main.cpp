#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <wiringPiI2C.h>

using namespace std;

int fd, accX, accY, accZ, gyroX, gyroY, gyroZ;

void ConfigPWMGPIO(int ConfigPwmGpio)
{
    pinMode(ConfigPwmGpio,OUTPUT);
    digitalWrite(ConfigPwmGpio,LOW);
    softPwmCreate(ConfigPwmGpio,0,100);
}

int readGyroSensor(int fdf, int reg)
{
    wiringPiI2CReadReg8(fdf, reg);
    return wiringPiI2CReadReg8(fdf, reg);
}

int main (void)
{
    cout << "I am executed\n"; 
    //initialize
    wiringPiSetup();
    fd = wiringPiI2CSetup (0x68);           //Initialize i2c system. returns
    wiringPiI2CWriteReg8 (fd,0x6B,0x00);    //disable sleep mode of GY-6050 sensor module (MPU-6050)
    cout << "fd value is: " << fd;
    cout << "Register read for adress 0x6B returns: " << wiringPiI2CReadReg8(fd,0x6B);

    //cout << readGyroSensor(0x68,0x68) << "\n";
    //cout << readGyroSensor(0x68,0x69) << "\n";
    //cout << readGyroSensor(0x68,0x68) << "\n";
    //cout << readGyroSensor(0x68,0x68) << "\n";

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
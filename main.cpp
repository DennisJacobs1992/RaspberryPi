#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

void ConfigPWMGPIO(int PwmGpioPin)
{
    pinMode(PwmGpioPin, OUTPUT);
    digitalWrite(PwmGpioPin, LOW);
    softPwmCreate(PwmGpioPin, 0, 100);
}

int main (void)
{
    //initialize
    wiringPiSetup();
    
    //configure PWM channels
    ConfigPWMGPIO(1);
    ConfigPWMGPIO(2);
    ConfigPWMGPIO(3);
    ConfigPWMGPIO(4);

    return 0;    
}

while(1)
{
    //softPwmWrite(1, 15);
    //softPwmWrite(2, 15);
    //softPwmWrite(3, 15);
    //softPwmWrite(4, 15);
}
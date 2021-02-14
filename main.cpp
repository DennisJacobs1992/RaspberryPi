#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

void ConfigPWMGPIO(int PwmGpioPin)
{
    pinMode(PwmGpioPin,OUTPUT);
    digitalWrite(PwmGpioPin,LOW);
    softPwmCreate(PwmGpioPin,0,100);
}

int main (void)
{
    //initialize
    wiringPiSetup();
    
    cout << "I am executed"; 

    //configure PWM channels
    ConfigPWMGPIO(5);
    ConfigPWMGPIO(6);
    ConfigPWMGPIO(7);
    ConfigPWMGPIO(8);
 
    //while(1)
    //{
        //softPwmWrite(1, 15);
        //softPwmWrite(2, 15);
        //softPwmWrite(3, 15);
        //softPwmWrite(4, 15);
    //}
 
    return 0;    
}
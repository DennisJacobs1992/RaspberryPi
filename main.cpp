#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;
wiringPiSetup();

int main (void)
{
    //initialize
    wiringPiSetup();
    
    //configure PWM channels
    ConfigPWMGPIO(GPIO1);
    ConfigPWMGPIO(GPIO2);
    ConfigPWMGPIO(GPIO3);
    ConfigPWMGPIO(GPIO4);
    
    return 0;    
}

while(1)
{
    softPwmWrite(GPIO1, 15)
}

void ConfigPWMGPIO(unsigned int PwmGpio){
    pinMode(PwmGpio, OUTPUT);
    digitalWrite(PwmGpio, LOW);
    softPwmCreate(PwmGpio, 0, 100);
}

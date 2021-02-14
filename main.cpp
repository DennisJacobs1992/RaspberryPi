#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <wiringPiI2C.h>

using namespace std;

int fd, accX, accY, accZ, gyroX, gyroY, gyroZ;
int exitWhileLoop = 1;

void ConfigPWMGPIO(int ConfigPwmGpio)
{
    pinMode(ConfigPwmGpio, OUTPUT);
    digitalWrite(ConfigPwmGpio, LOW);
    softPwmCreate(ConfigPwmGpio, 0, 100);
}

int readMPU6050(int Mpu6050Addr)
{
    int val = (wiringPiI2CReadReg8(fd, Mpu6050Addr) << 8) +  wiringPiI2CReadReg8(fd, Mpu6050Addr+1);
    if (val >= 0x8000)
    val = -(65536 - val);
    return val;
}

int main (void)
{
    cout << "Main function executed\n"; 
    
    //initialize
    wiringPiSetup();
    fd = wiringPiI2CSetup (0x68);           //Initialize i2c system. returns
    wiringPiI2CWriteReg8 (fd, 0x6B, 0x00);    //disable sleep mode of GY-6050 sensor module (MPU-6050)
    cout << "fd value is: " << fd << "\n";
    cout << "Register read for adress 0x6B returns: " << wiringPiI2CReadReg8(fd, 0x6B) << "\n";

    //configure PWM channels
    ConfigPWMGPIO(11);
    ConfigPWMGPIO(13);
    ConfigPWMGPIO(15);
    ConfigPWMGPIO(16);
 
    while(exitWhileLoop)
    {
        //get sensor values
        accX = readMPU6050(0x3B);
        accY = readMPU6050(0x3D);
        accZ = readMPU6050(0x3F);

        cout << "Acceleration X: " << accX << "\n";
        cout << "Acceleration Y: " << accY << "\n";
        cout << "Acceleration Z: " << accZ << "\n";
        cout << "To get another sample press 1, press annytging else to exit code execution\n";
        
        cin >> exitWhileLoop;

        //Set PWM pins
        //softPwmWrite(11, 15);
        //softPwmWrite(13, 15);
        //softPwmWrite(15, 15);
        //softPwmWrite(16, 15);
    }
 
    return 0;    
}
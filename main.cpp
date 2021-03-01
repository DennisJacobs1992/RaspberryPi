#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <wiringPiI2C.h>
#include <time.h>

using namespace std;

int fd;
double accX, accY, accZ, gyroX, gyroY, gyroZ, temp;
int exitWhileLoop = 1;

void ConfigPwmGpio(int ConfigPwmGpio)
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
    fd = wiringPiI2CSetup (0x68);             //Initialize i2c system. returns
    wiringPiI2CWriteReg8 (fd, 0x6B, 0x00);    //disable sleep mode of GY-6050 sensor module (MPU-6050)
    cout << "fd value is: " << fd << "\n";
    cout << "Register read for adress 0x6B returns: " << wiringPiI2CReadReg8(fd, 0x6B) << "\n";

    //configure PWM ESC channels
    //ConfigPwmGpio(11);
    //ConfigPwmGpio(13);
    //ConfigPwmGpio(15);
    //ConfigPwmGpio(16);

    //Config Solar Panel channels
    softServoSetup(15);
    softServoWrite(15,1500);


    while(exitWhileLoop == 1)
    {
        softServoWrite(15,1500);
        nanosleep(1000000000);
        softServoWrite(15,1600);
        nanosleep(1000000000);
        softServoWrite(15,1700);
        nanosleep(1000000000);
        softServoWrite(15,1800);
        nanosleep(1000000000);       
        softServoWrite(15,1900);
        nanosleep(1000000000);
        softServoWrite(15,2000);
        nanosleep(1000000000);
        softServoWrite(15,2100);
        nanosleep(1000000000);
        softServoWrite(15,2200);    
        // Readout and scale temperature measurementsensor values (in degree celsius)
        temp = readMPU6050(0x41);
        temp = (temp/340) + 36.53;

        // Readout and scale accelerometer measurements (full scale range +/- 2g)
        accX = readMPU6050(0x3B);
        accX = accX/16384;
        accY = readMPU6050(0x3D);
        accY = accY/16384;
        accZ = readMPU6050(0x3F);
        accZ = accZ/16384;

        // Readout and scale gyroscope measurements (full scale range +/- 250 degrees/second)
        gyroX = readMPU6050(0x43);
        gyroX = gyroX/131;
        gyroY = readMPU6050(0x45);
        gyroY = gyroY/131;
        gyroZ = readMPU6050(0x47);
        gyroZ = gyroZ/131;

        cout << "Temperature: " << temp << " degree celsius\n";
        
        cout << "Acceleration X: " << accX << "\n";
        cout << "Acceleration Y: " << accY << "\n";
        cout << "Acceleration Z: " << accZ << "\n";

        cout << "Gyro X: " << gyroX << "\n";
        cout << "Gyro Y: " << gyroY << "\n";
        cout << "Gyro Z: " << gyroZ << "\n";
        
        //Set PWM pins
        //softPwmWrite(11, 15);
        //softPwmWrite(13, 15);
        //softPwmWrite(15, 15);
        //softPwmWrite(16, 15);
        break;
    }
 
    return 0;    
}
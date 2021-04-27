#ifndef MPU9250_H
#define MPU9250_H

using namespace stf;

double temp

class MPU9250{
    public:
    double acc;
    double gyro;
    void readSensorValues(double &n);
    void calculateSensorValue(double &n);
};

#endif // MPU9250
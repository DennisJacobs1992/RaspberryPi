#ifndef MPU9250_H
#define MPU9250_H

using namespace std;

class MPU9250{
    public:
        MPU9250();
        void readSensorValue(int &fd, int addr, double &value);
        void calculateSensorValue(double &n);
};

#endif // MPU9250
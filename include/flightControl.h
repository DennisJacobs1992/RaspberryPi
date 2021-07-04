#ifndef FLIGHTCONTROL_H
#define FLIGHTCONTROL_H

using namespace std;

class MPU9250{
    public:
        MPU9250();
        void readSensorValue(int &fd, double (&MPU9250ValueArray)[7]);
        void printAllSensorValues(double (&MPU9250ValueArray)[7]);
};

#endif // MPU9250
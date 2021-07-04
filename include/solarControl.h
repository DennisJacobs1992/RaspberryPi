#ifndef SOLARCONTROL_H
#define SOLARCONTROL_H

using namespace std;

class LDR{
    public:
        LDR();
        void checkLDRstatus(); 
        void getLDRValues();
};

#endif // LDR

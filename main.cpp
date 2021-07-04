#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <time.h>
#include <thread>

//custom includes
#include "init.h"
#include "userInputManager.h"
#include "flightControlManager.h"
#include "solarControlManager.h"


#define EXPLANTSOLAR 0
#define COLLAPSSOLAR 1
#define SEARCHSUN 2
#define CHECKSTATUS 3

int fd;
bool quit = 0;
 
int main (void)
{
    std::cout << "#--- Main function executed\n";

    //initialize board
    init initObject;
    initObject.initGpio(fd);
    std::cout << "#--- GPIO's set\n";

    //check battery status

    //cheate instances
        //user input manager
        //configuration manager
        //battery management
        //flight control
        //solar control
    while(quit!=1)
    {
        userInputManager userInputManagerObj;
        userInputManagerObj.setcheckUserInputManagerFile();
        //get user input
        //if something changed for the configuration, do some configuration adjustments
        //if fligt control is active, perform fligt control
        //if solar control is active, perform solar control

        quit = 1;
    }

    return 0;    
}
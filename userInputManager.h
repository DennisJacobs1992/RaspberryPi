#ifndef USERINPUTMANAGER_H
#define USERINPUTMANAGER_H

#include <iostream>
#include <vector>
#include <string>

class userInputManager{
    public:
        //available user commands
        std::vector<std::string> customCommands{
            "Qquit",    // quit main program
            "QeFC",     // enable flight control
            "QdFC",     // disable flight control
        };
        
        bool checkUserInputManagerFile();
        void setcheckUserInputManagerFile();
        bool flightcontrol = 0;   
};

#endif // LDR
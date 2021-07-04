#ifndef USERINPUTMANAGER_H
#define USERINPUTMANAGER_H

#include <stdio.h>
#include "string.h"
#include <stdio.h>

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
        bool solarconfig = 0;
        bool solarconfig = 0;    
};

#endif // LDR
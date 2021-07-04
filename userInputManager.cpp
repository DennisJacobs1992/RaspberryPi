#include <iostream>
#include "userInputManager.h"

bool userInputManager::checkUserInputManagerFile(){
    return false;
}

void userInputManager::setcheckUserInputManagerFile(){
    // create interface file
    std::ofstream userInputManagerFile;
    userInputManagerFile.open("customCommands.txt");
    for(int i = 0; i < customCommands.size(); i++){
        userInputManagerFile << customCommands[i] << std::endl;
    }    
/*
    // create linux commands    
    ofstream userInputManagerFile;
    for(int i = 0; i > customCommands.size(); i++){
        userInputManagerFile.open("/bin/customCommands.c");
    }
*/
}
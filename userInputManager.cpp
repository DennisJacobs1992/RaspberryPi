#include <iostream>
#include "userInputManager.h"

userInputManager::checkUserInputManagerFile(){

}

userInputManager::setcheckUserInputManagerFile(){
    // create interface file
    ofstream userInputManagerFile;
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
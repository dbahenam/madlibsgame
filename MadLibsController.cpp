//
//  MadLibsController.cpp
//  Assignment2
//

#include "MadLibsController.hpp"
#include <fstream>
#include <ctype.h>
#include <vector>
#include <algorithm>

MadLibsController::MadLibsController() {
}

std::vector<std::string> MadLibsController::getWords() {
    return std::vector<std::string>();
}

bool isPunct(char aChar) {
  static std::string punct(".;?!:,'-");
  return std::string::npos != punct.find(aChar);
}

//Student: in this method, show the final result of your madlib (with user data) to given output
void MadLibsController::showFinishedStory(std::ostream &anOutput) {
    anOutput << "Your madlib is: \n";
    //now show the user their madlib, with their words embedded in the output...    
}

//Notice how we separated 'reading a file' from other operations?
//In this method, you read the madlib template file...
bool MadLibsController::readFile(const char *aPath) {
  return false;
}

//Find all the capitalized words madlib (file), and ask provider for word substitutes...
void MadLibsController::getSubstitutes(MadlibWordProvider &aProvider) {
    //STUDENT: iterate through the madlib file (words), and ask yhr word provider for each CAPITALIZED word...
}

bool MadLibsController::runStory(const char *aFilename, MadlibWordProvider &aProvider, std::ostream &anOutput) {
    if(readFile(aFilename)) {
        getSubstitutes(aProvider); //get replacement for each CAPITALIZED word (substitutes)
        showFinishedStory(anOutput);
        return true;
    }
    return false;
}


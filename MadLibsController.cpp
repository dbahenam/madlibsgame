//
//  MadLibsController.cpp
//  Assignment2
//

#include "MadLibsController.hpp"
#include <fstream>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <sstream>

MadLibsController::MadLibsController() {
    words = new std::vector<std::string>;
    story = new std::vector<std::string>;
}

MadLibsController::MadLibsController(const MadLibsController &aCopy) {
    *this = aCopy;
}

MadLibsController& MadLibsController::operator=(const MadLibsController &aCopy){
    for(auto word : *aCopy.words){
        words->push_back(word);
    }
    for(auto storyWord : *aCopy.story){
        story->push_back(storyWord);
    }
    return *this;
}

MadLibsController::~MadLibsController() {
    delete words;
    delete story;
}


std::vector<std::string> MadLibsController::getWords() {
    return *words;
}

bool isPunct(char aChar) {
    static std::string punct(".;?!:,'-");
    return std::string::npos != punct.find(aChar);
}

//Student: in this method, show the final result of your madlib (with user data) to given output
void MadLibsController::showFinishedStory(std::ostream &anOutput) {
    anOutput << "Your madlib is: \n";
    //now show the user their madlib, with their words embedded in the output...
    for(const auto &word : *story){
        std:: cout << word << " ";
    }
    std::cout << "\n";
}

//Notice how we separated 'reading a file' from other operations?
//In this method, you read the madlib template file...
bool MadLibsController::readFile(const char *aPath) {
    std::ifstream theFile(aPath);
    std::string word;
    if(!theFile.good()){
        return false;
    }
    while(theFile >> word) {
        story->push_back(word);
    }

    return true;
}

std::string MadLibsController::toUpper(const std::string &aWord) {
    std::string capitalizedWord;
    for(auto c : aWord){
        capitalizedWord.push_back(toupper(c));
    }
    return capitalizedWord;
}

//Find all the capitalized words madlib (file), and ask provider for word substitutes...
void MadLibsController::getSubstitutes(MadlibWordProvider &aProvider) {
    //STUDENT: iterate through the madlib file (words), and ask yhr word provider for each CAPITALIZED word...
    bool punctuationFlag = false;
    std::string substitute;
    char punctuation;
    for(auto& word : *story) {
        if (word == toUpper(word) && word.size() > 1 && word != "--") {
            substitute = word;
            if (isPunct(word[word.size() - 1])) {
                punctuation = word[word.size() - 1];
                substitute.erase(substitute.size()-1);
                punctuationFlag = true;
            }
            auto wordType = aProvider.getTypeForLabel(substitute);
            substitute = aProvider.getSubstituteWord(wordType);
            word = substitute;
            words->push_back(word);
            if(punctuationFlag){
                word.push_back(punctuation);
                punctuationFlag = false;
            }

        }
    }
}

bool MadLibsController::runStory(const char *aFilename, MadlibWordProvider &aProvider, std::ostream &anOutput) {
    if(readFile(aFilename)) {
        getSubstitutes(aProvider); //get replacement for each CAPITALIZED word (substitutes)
        showFinishedStory(anOutput);
        return true;
    }
    return false;
}
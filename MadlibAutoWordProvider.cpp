//
//  MadlibAutoWordProvider.cpp
//  Assignment2
//

#include "MadlibAutoWordProvider.hpp"
#include <time.h>

MadlibAutoWordProvider::MadlibAutoWordProvider() : MadlibWordProvider() {
    // We provide a json file that's loaded with starter words
    readJSON("words.json");
}

MadlibAutoWordProvider::MadlibAutoWordProvider(const MadlibAutoWordProvider &aCopy){
    *this = aCopy;
}
MadlibAutoWordProvider& MadlibAutoWordProvider::operator=(const MadlibAutoWordProvider &aCopy){
    for(const auto& word : aCopy.word_list){
        word_list.push_back(word);
    }
    return *this;
}


//STUDENT ask chatbot for word of given type; return that to caller...
std::string MadlibAutoWordProvider::getSubstituteWord(WordType aType) {
    //STUDENT: get bot to give you random word of given type...
    //Don't forget to handle the special case of plural nouns

    int randNum;
    WORD aWordStruct;
    while(true){
        randNum = rand() % word_list.size() + 1;
        aWordStruct = word_list[randNum];
        if(aWordStruct.pos == gLabels[aType] || aWordStruct.category == getLabelForType(aType)){
           return aWordStruct.word;
        }
        else if("pluralnoun" == gLabels[aType] && aWordStruct.pos == "noun"){
            return aWordStruct.word + "s";
        }
    }
}

bool MadlibAutoWordProvider::readJSON(const char *jsonPath) {
    std::ifstream f;
    f.open(jsonPath);
    if(!f.is_open()) {
        std::cerr << "Error opening JSON file!" << std::endl;
        return false;
    }
    std::string line, word, first_split;
    while (!f.eof()) {
        WORD curr_line;
        if (line.find("\"WORD\"") != std::string::npos) {
            first_split = line.substr(line.find(":"), line.find("\","));
            word = first_split.substr(first_split.find("\"")+1, first_split.find("\",")-3);
            curr_line.word = word;
            std::getline(f, line);
        }
        if(line.find("\"POS\"") != std::string::npos){
            first_split = line.substr(line.find(":"), line.find(","));
            word = first_split.substr(first_split.find("\"")+1, first_split.find("\",")-3);
            curr_line.pos = word;
            std::getline(f, line);
        }
        if(line.find("\"CATEGORY\"") != std::string::npos){
            first_split = line.substr(line.find(":"), line.find(","));
            if(first_split.compare(": \"\"") != 0) {
                word = first_split.substr(first_split.find("\"")+1, first_split.find_last_of("\"")-3);
                curr_line.category = word;
            }
            word_list.push_back(curr_line);
            std::getline(f, line);
        }
        else {
            std::getline(f, line);
        }
    }
    return true;
}
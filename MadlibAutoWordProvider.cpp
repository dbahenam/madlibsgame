//
//  MadlibAutoWordProvider.cpp
//  Assignment2
//

#include "MadlibAutoWordProvider.hpp"

MadlibAutoWordProvider::MadlibAutoWordProvider() : MadlibWordProvider() {
    // We provide a json file that's loaded with starter words
    readJSON("words.json");
}

//STUDENT ask chatbot for word of given type; return that to caller...
std::string MadlibAutoWordProvider::getSubstituteWord(WordType aType) {
    //STUDENT: get bot to give you random word of given type...
    //Don't forget to handle the special case of plural nouns
    return std::string();
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

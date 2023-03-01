//
//  MadLibsController.hpp
//  Assignment2
//


#ifndef MadLibsController_hpp
#define MadLibsController_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "MadlibWordProvider.hpp"
#include <memory>
class MadLibsController {
public:

    MadLibsController(); //default ctor
    MadLibsController(const MadLibsController &aCopy);
    MadLibsController& operator=(const MadLibsController &aCopy);
    ~MadLibsController();
    bool  runStory(const char *aFilename, MadlibWordProvider &aProvider, std::ostream &anOutput);
    bool  readFile(const char *aFilename);
    void  getSubstitutes(MadlibWordProvider &aProvider);
    void  showFinishedStory(std::ostream &anOutput);
    std::string toUpper(const std::string &aWord);
    std::vector<std::string> getWords();


protected:
    std::vector<std::string> *words; //collected from users...
    std::vector<std::string> *story;
};

#endif /* MadLibsController_hpp */
//
//  MadlibAutoWordProvider.hpp
//  Assignment2
//

#ifndef MadlibAutoWordProvider_hpp
#define MadlibAutoWordProvider_hpp


#include "MadlibWordProvider.hpp"

//a tiny little class, with a base class
class MadlibAutoWordProvider : public MadlibWordProvider {
public:
    MadlibAutoWordProvider(); //ctor (don't forget the rest of the OCF)

    MadlibAutoWordProvider(const MadlibAutoWordProvider &aCopy);
    MadlibAutoWordProvider& operator=(const MadlibAutoWordProvider &aCopy);
    ~MadlibAutoWordProvider()=default;

    virtual std::string getSubstituteWord(WordType aType); //provide random words for each type...
    bool readJSON(const char *jsonPath);

protected:
    struct WORD{
        std::string word;
        std::string pos;
        std::string category;
    };
    std::vector<WORD> word_list;
};



#endif /* MadlibAutoWordProvider_hpp */

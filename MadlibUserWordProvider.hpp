//
//  MadlibUserWordProvider.hpp
//  Assignment2
//

#ifndef MadlibUserWordProvider_hpp
#define MadlibUserWordProvider_hpp

#include <stdio.h>
#include "MadlibWordProvider.hpp"

class MadlibUserWordProvider : public MadlibWordProvider {
public:
    MadlibUserWordProvider(); //ctor
    virtual std::string getSubstituteWord(WordType aType);

};

#endif /* MadlibUserWordProvider_hpp */

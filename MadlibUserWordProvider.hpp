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
    MadlibUserWordProvider(const MadlibUserWordProvider &aCopy)=default;
    MadlibUserWordProvider& operator=(const MadlibUserWordProvider &aCopy)=default;
    ~MadlibUserWordProvider()=default;
    virtual std::string getSubstituteWord(WordType aType);

};

#endif /* MadlibUserWordProvider_hpp */
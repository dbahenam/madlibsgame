//
//  MadlibUserWordProvider.cpp
//  Assignment2
//

#include "MadlibUserWordProvider.hpp"
#include <iostream>

MadlibUserWordProvider::MadlibUserWordProvider() : MadlibWordProvider() {}

std::string MadlibUserWordProvider::getSubstituteWord(WordType aType) {
    //STUDENT: ask the user for console input (std::cin), and return their input...
    std::string wordType = getLabelForType(aType);
    std::string userWord;
    std::cout << "Please enter a/an " << wordType << ": ";
    std::cin >> userWord;
    std::cout << "\n";
    return userWord;
}
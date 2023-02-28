# Mad Libs Game

The Mad Libs Game is a C++ console application that allows users to play a classic game of Mad Libs, where players fill in the blanks in a story with different parts of speech such as nouns, verbs, adjectives, and adverbs.

## Overview

The Mad Libs Game consists of four classes:

- `MadLibsController.hpp/.cpp`: The controller class that manages the game logic and user input/output.
- `MadlibAutoWordProvider.hpp/.cpp`: A word provider class that automatically generates words for the blanks based on their part of speech.
- `MadlibUserWordProvider.hpp/.cpp`: A word provider class that prompts the user to enter words for the blanks.
- `MadlibWordProvider.hpp`: An abstract base class for word provider classes.

### Encapsulation

All of the classes in the Mad Libs Game encapsulate their data members and offer a limited interface to control the object. This allows for better control of the object's behavior and reduces the risk of unwanted changes to the object's internal state.

### Inheritance

The Mad Libs Game uses inheritance to provide two MadLibsWordProvider subclasses (`MadLibsUserWordProvider` and `MadLibsAutoWordProvider`). This allows for code reuse and provides a clear hierarchy of classes.

### Polymorphism

The Mad Libs Game uses polymorphism when different types of `MadLibsWordProvider` objects are asked for a substitute word. The `MadlibsController` will call the method `getSubstituteWord(WordType)`, and the given word-provider object will figure out how to respond. This allows for more flexible and dynamic behavior of the program.


## Installation

To install the Mad Libs Game, follow these steps:

1. Clone the repository or download the source code.
2. Compile the source code using a C++ compiler such as GCC or Visual Studio.
3. Run the executable file.


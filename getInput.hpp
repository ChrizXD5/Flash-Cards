#ifndef GETINPUT_HPP
#define GETINPUT_HPP

#include <string>

/**
    Gets input from the user using getline()

    @param output stores user input inside
*/
void getInput(std::string& output);

/**
    Gets input from the user and checks to see if its a valid int

    @retval false input was not valid and no valid output
    @retval true input was valid and contains an int
*/
bool getInput(int& output);

#endif


#include <iostream>

/**
    Gets input from the user using getline()

    @param output stores user input inside
*/
void getInput(std::string& output) {
    std::cout << "> ";
    std::getline(std::cin, output);
}

/**
    Gets input from the user and checks to see if its a valid int

    @retval false input was not valid and no valid output
    @retval true input was valid and contains an int
*/
bool getInput(int& output) {

    std::string userInput;
    std::cout << "> ";
    std::getline(std::cin, userInput);

    // converts string into int
    int intOutput = 0;
    while (!userInput.empty())
    {
        intOutput = intOutput * 10;
        switch (userInput[0]) {
            case '0':
                break;
            case '1':
                intOutput = intOutput + 1;
                break;
            case '2':
                intOutput = intOutput + 2;
                break;
            case '3':
                intOutput = intOutput + 3;
                break;
            case '4':
                intOutput = intOutput + 4;
                break;
            case '5':
                intOutput = intOutput + 5;
                break;
            case '6':
                intOutput = intOutput + 6;
                break;
            case '7':
                intOutput = intOutput + 7;
                break;
            case '8':
                intOutput = intOutput + 8;
                break;
            case '9':
                intOutput = intOutput + 9;
                break;

                // non numeric character is detected
            default:
                return false;
        }
        // pop the front char
        userInput.erase(userInput.begin());
    }

    // valid input
    output = intOutput;
    return true;
}

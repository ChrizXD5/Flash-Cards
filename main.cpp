#include <iostream>
#include "getInput.hpp"
#include "Quiz.hpp"
#include "clearScreen.hpp"

void printMenu()
{
    std::cout << "===================\n";
    std::cout << "1) Start quiz\n";
    std::cout << "2) Add questions\n";
    std::cout << "3) Quiz options\n";
    std::cout << "4) Exit\n";
}

int main()
{
    Quiz myQuiz;
    clearScreen();

    std::cout << "Flash Cards V0.3\n";
    while(true)
    {
        printMenu();        
        std::string userInput;
        getInput(userInput);

        clearScreen();
        if (userInput == "1")
            myQuiz.start();
        else if(userInput == "2")
            myQuiz.addQuestions();
        else if (userInput == "3")
            myQuiz.setup();
        else if (userInput == "4")
            return 0;
    }

    return 1;
}

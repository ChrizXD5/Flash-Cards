#include "Quiz.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "clearScreen.hpp"
#include "getInput.hpp"

// default constructor
Quiz::Quiz()
{
    // creates random seed based on the system clock
    srand(time(0));
}

int Quiz::uniqueRandom(std::vector<int> numbers, int max)
{
    int randNum;
    bool unique;

    while(true)
    {
        randNum = rand() % max;
        unique = true;

        for (auto num : numbers)
        {
            if (num == randNum)
            {
                unique = false;
                break;
            }
            
        }

        if (unique)
            return randNum;
    }
}

/**
    Sets up questions and answers.
*/
void Quiz::addQuestions() {
    std::string question;
    std::string answer;
    int numOfQuestions = 0;

    clearScreen();

    while (true)
    {
        std::cout << "Enter 'end' to stop entering questions.\n";
        std::cout << "Enter question " << questions.size() + 1 << ": ";
        std::getline(std::cin, question);
        if (question == "end") break;
        
        std::cout << "Enter question's " << questions.size() + 1 << " answer: ";
        std::getline(std::cin, answer);
        if (answer == "end") break;

        questions.push_back(Question(question, answer));
        ++numOfQuestions;

        clearScreen();
    }
    
    clearScreen();
    std::cout << numOfQuestions << " questions have been added\n";
}

void Quiz::setup()
{
    while (true)
    {
        clearScreen();
        std::cout << "========================================\n";
        std::cout << "1) Edit number of answers: " << numberOfAnswers << "\n";
        std::cout << "2) Randomize order: " << (random ? "ON\n" : "OFF\n");
        std::cout << "3) Exit\n";
        std::string userInput;
        getInput(userInput);

        switch(userInput[0])
        {

            case '1':
                {
                clearScreen();
                bool validInput = false;
                while (!validInput)
                {
                    int input;
                    std::cout << "Enter number of answers\n";
                    if (getInput(input))
                    {
                        numberOfAnswers = input;
                        validInput = true;
                    }
                    else
                    {
                        clearScreen();
                        std::cout << "Please enter a number!\n";
                    }
                }
                }
                break;
            case '2':
                if (random)
                    random = false;
                else
                    random = true;
                break;
            case '3':
                clearScreen();
                return;
            
        }
    }
}

void Quiz::start()
{
    if (numberOfAnswers > questions.size())
    {
        std::cout << "More questions are required in order to start!\n";
        return;
    }

    float numCorrect = 0;
    int correctAnswer;

    for (int i = 0; i < questions.size(); ++i)
    {
        std::cout << "Question " << i + 1 << ":\n" << questions[i].getQuestion() << "\n";
        

        correctAnswer = rand() % numberOfAnswers;
        // keep track of what questions have been used
        std::vector<int> uniqueNum;
        uniqueNum.push_back(i);
        // print out answers
        for (int q = 0; q < numberOfAnswers; ++q)
        {
            if (correctAnswer == q)
                std::cout << q + 1 << ") " << questions[i].getAnswer() << "\n";
            else
            {
                int randNum = uniqueRandom(uniqueNum, numberOfAnswers);
                std::cout << q + 1 << ") " << questions[randNum].getAnswer() << "\n";
                uniqueNum.push_back(randNum);
            }    
        }
        
        // gets a valid number from the user
        int userInput;
        while (true)
        {
            if (getInput(userInput))
                break;
            else
                std::cout << "Please enter a number!\n";
        }
        // checks if answer is correct + 1 due to formating
        if (userInput == correctAnswer + 1)
        {
            ++numCorrect;
        }

        clearScreen();
    }

    std::cout << "Score: " << numCorrect << "/" << questions.size() << " (" << numCorrect / questions.size() << ")\n";
}

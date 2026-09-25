#include <iostream>
#include <vector>
#include <random>
#include <ctime>

/**
    Clears the screen and resets cursor position
*/
void clearScreen()
{
    std::cout << "\033[H\033[2J\033[3J" << std::flush;
}


/**
    Gets input from the user using getline()

    @return String of the lasted entered line.
*/
std::string getInput() {
    std::string userInput;
    std::cout << "> ";
    std::getline(std::cin, userInput);

    return userInput;
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

/**
    @class Question

    contains a question string and answer string
*/
class Question {
    private: 
    // each index corresponds to the proper question and answer
    std::string question;
    std::string answer;

    public: 
    // constructor for making question
    Question(std::string q, std::string a) : question(q), answer(a) {}

    /**
        Sets the question and answer.

        @param q Question to be asked
        @param a Answer for the question
    */
    void set(const std::string &q, const std::string &a) {
        question = q;
        answer = a;
    }

    // getter functions
    std::string getQuestion() {return question;}
    std::string getAnswer() {return answer;}
};

class Quiz {
    private:
    std::vector<Question> questions;
    int numberOfAnswers = 4;
    bool random = false;

    /**
        Gets a unique random number that not 'num'.
        
        @param numbers Vector of numbers that causes a regeneration
        @param max Max desired number
        @return Random number
    */
    int uniqueRandom(std::vector<int> numbers, int max)
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

    public:
    Quiz()
    {
        srand(time(0));
    }
    
    /**
        Sets up questions and answers.
    */
    void addQuestions() {
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

    void setup()
    {
        while (true)
        {
            clearScreen();
            std::cout << "========================================\n";
            std::cout << "1) Edit number of answers: " << numberOfAnswers << "\n";
            std::cout << "2) Randomize order: " << (random ? "ON\n" : "OFF\n");
            std::cout << "3) Exit\n";
            auto userInput = getInput();

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
                    return;
                
            }
        }
    }

    // TODO: implement read file feature to import questions and answers
    void readFile();

    void start()
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
            
            // @TODO replace with getInput
            int userInput;
            std::cin >> userInput;
            if (userInput == correctAnswer + 1)
            {
                ++numCorrect;
            }
            std::cin.ignore();
        }

        std::cout << "Score: " << numCorrect << "/" << questions.size() << " (" << numCorrect / questions.size() << ")\n";
        std::cout << "Press enter to contune";
    }
};

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

    std::cout << "Flash Cards V0.2\n";
    while(true)
    {
        printMenu();        
        std::string userInput = getInput();

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

    return 0;
}

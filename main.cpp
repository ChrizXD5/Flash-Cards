#include <iostream>
#include <vector>
#include <random>
#include <ctime>

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


        std::cout << "Enter 'end' to stop entering questions.\n";

        while (true)
        {
            std::cout << "Enter question " << questions.size() + 1 << ": ";
            std::getline(std::cin, question);
            if (question == "end") break;
            
            std::cout << "Enter question's " << questions.size() + 1 << " answer: ";
            std::getline(std::cin, answer);
            if (answer == "end") break;

            questions.push_back(Question(question, answer));
            ++numOfQuestions;
        }
        
        std::cout << numOfQuestions << " questions have been added\n";
    }

    void setup()
    {
        std::string userInput;

        while (true)
        {
            std::cout << "========================================\n";
            std::cout << "1) Edit number of answers: " << numberOfAnswers << "\n";
            std::cout << "2) Randomize order: " << (random ? "ON\n" : "OFF\n");
            std::cout << "3) Exit\n";

            std::getline(std::cin, userInput);
            if (userInput == "1")
            {
                bool validInput = false;
                int input;
                while(!validInput)
                {
                    // TODO: Add better error corrections for bad input
                    std::cout << "Enter number of answers: ";
                    std::cin >> input;
                    std::cin.ignore();

                    if (input > 1 && input < 11)
                    {
                        validInput = true;
                        numberOfAnswers = input;
                    }
                }
                
            }
            else if (userInput == "2")
            {
                if (random)
                    random = false;
                else
                    random = true;
            }
            else if (userInput == "3")
            {
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
            
            int userInput;
            std::cin >> userInput;
            if (userInput == correctAnswer + 1)
            {
                ++numCorrect;
            }
            std::cin.ignore();
        }

        std::cout << "Score: " << numCorrect << "/" << questions.size() << " (" << numCorrect / questions.size() << ")\n";
    }
};

void printMenu()
{
    std::cout << "========================================\n";
    std::cout << "1) Start quiz\n";
    std::cout << "2) Add questions\n";
    std::cout << "3) Quiz options\n";
    std::cout << "4) Exit\n";
}

int main()
{
    Quiz myQuiz;
    std::string userInput;

    std::cout << "Flash Cards V0.1\n";
    while(true)
    {
        printMenu();        
        std::getline(std::cin, userInput);

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
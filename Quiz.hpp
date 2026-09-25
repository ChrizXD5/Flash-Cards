#ifndef QUIZ_HPP
#define QUIZ_HPP

#include <vector>
#include "Question.hpp"

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
    int uniqueRandom(std::vector<int> numbers, int max);

    public:
    // default constructor
    Quiz();

    /**
        Sets up questions and answers.
    */
    void addQuestions();

    // Option menu
    void setup();

    // TODO: implement read file feature to import questions and answers
    void readFile();

    void start();
};

#endif

#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <string>

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
    void set(const std::string &q, const std::string &a);

    // getter functions
    std::string getQuestion();
    std::string getAnswer();
};

#endif

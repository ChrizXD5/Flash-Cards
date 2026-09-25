#include "Question.hpp"

/**
    Sets the question and answer.

    @param q Question to be asked
    @param a Answer for the question
*/
void Question::set(const std::string &q, const std::string &a) {
    question = q;
    answer = a;
}

// getter functions
std::string Question::getQuestion() {return question;}
std::string Question::getAnswer() {return answer;}

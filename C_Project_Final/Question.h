#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
class Question {
public:
    std::string questionText;       // The text of the question.
    std::vector<std::string> answers; // A vector holding the answer choices.
    int correctAnswerIndex;         // The 0-based index of the correct answer in the answers vector.
    
    Question(std::string qText, std::vector<std::string> ans, int correctAns);
};

#endif

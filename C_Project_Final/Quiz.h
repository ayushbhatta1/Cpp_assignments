#ifndef QUIZ_H
#define QUIZ_H

#include "Question.h"
#include <vector>
#include <string>


class Quiz {
public:
    std::vector<Question> questions; // A vector to store all the Question objects in the quiz.

    
    void addQuestion(Question q);

   
    void takeQuiz();

   
    void saveToFile(std::string filename);

    void loadFromFile(std::string filename);
};

#endif

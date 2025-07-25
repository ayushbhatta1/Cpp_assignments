#include "Question.h"
Question::Question(std::string qText, std::vector<std::string> ans, int correctAns) {
    questionText = qText;
    answers = ans;
    correctAnswerIndex = correctAns;
}

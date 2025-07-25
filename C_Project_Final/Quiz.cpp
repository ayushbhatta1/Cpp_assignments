#include "Quiz.h"
#include <iostream>
#include <fstream>


void Quiz::addQuestion(Question q) {
    questions.push_back(q);
}


void Quiz::takeQuiz() {
    int score = 0;
    for (int i = 0; i < questions.size(); ++i) {
        std::cout << "Question " << i + 1 << ": " << questions[i].questionText << std::endl;
        for (int j = 0; j < questions[i].answers.size(); ++j) {
            std::cout << j + 1 << ". " << questions[i].answers[j] << std::endl;
        }
        int userAnswer;
        std::cout << "Your answer (1-" << questions[i].answers.size() << "): ";
        std::cin >> userAnswer;
        if (userAnswer - 1 == questions[i].correctAnswerIndex) {
            score++;
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect." << std::endl;
        }
    }
    std::cout << "Your final score is: " << score << "/" << questions.size() << std::endl;
}


void Quiz::saveToFile(std::string filename) {
    std::ofstream outFile(filename);
    for (const auto& q : questions) {
        outFile << q.questionText << std::endl;
        outFile << q.answers.size() << std::endl;
        for (const auto& answer : q.answers) {
            outFile << answer << std::endl;
        }
        outFile << q.correctAnswerIndex << std::endl;
    }
    outFile.close();
}

void Quiz::loadFromFile(std::string filename) {
    std::ifstream inFile(filename);
    std::string qText;
    int correctAns;
    size_t numAnswers;
    questions.clear(); // Clear existing questions before loading
    while (std::getline(inFile, qText)) {
        inFile >> numAnswers;
        inFile.ignore(); // Consume the newline character
        std::vector<std::string> answers;
        for (size_t i = 0; i < numAnswers; ++i) {
            std::string answer;
            std::getline(inFile, answer);
            answers.push_back(answer);
        }
        inFile >> correctAns;
        inFile.ignore(); // Consume the newline character
        questions.push_back(Question(qText, answers, correctAns));
    }
    inFile.close();
}

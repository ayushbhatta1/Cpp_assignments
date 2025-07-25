#include <iostream>
#include <limits> // Required for std::numeric_limits
#include "Quiz.h"

int main() {
    Quiz quiz; // The main quiz object.
    int choice;  // Variable to store the user's choice.

    while (true) {
        // Display the main menu.
        std::cout << "\nQuiz Taker Menu:" << std::endl;
        std::cout << "1. Create a new quiz" << std::endl;
        std::cout << "2. Take a quiz" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            // Logic for creating a new quiz.
            quiz.questions.clear(); // Clear any existing questions
            while (true) {
                std::string qText;
                std::cout << "Enter the question (or type 'done' to finish): ";
                std::cin.ignore();
                std::getline(std::cin, qText);
                if (qText == "done") {
                    break;
                }

                int numAnswers;
                std::cout << "How many answer choices do you want to provide? ";
                std::cin >> numAnswers;
                std::cin.ignore(); // Consume the newline

                std::vector<std::string> answers;
                for (int i = 0; i < numAnswers; ++i) {
                    std::string answer;
                    std::cout << "Enter answer choice " << i + 1 << ": ";
                    std::getline(std::cin, answer);
                    answers.push_back(answer);
                }

                int correctAns;
                std::cout << "Which answer is correct (1-" << numAnswers << ")? ";
                std::cin >> correctAns;

                // Create a new Question and add it to the quiz.
                quiz.addQuestion(Question(qText, answers, correctAns - 1));
            }
            // Save the updated quiz to a file.
            quiz.saveToFile("quiz.txt");
            std::cout << "Quiz saved to quiz.txt" << std::endl;
        } else if (choice == 2) {
            // Logic for taking a quiz.
            quiz.loadFromFile("quiz.txt");
            if (quiz.questions.empty()) {
                std::cout << "No quiz found. Please create one first." << std::endl;
            } else {
                quiz.takeQuiz();
            }
        } else if (choice == 3) {
            // Exit the application.
            break;
        } else {
            // Handle invalid input.
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}


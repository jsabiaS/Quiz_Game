#include "printResult.h"
#include "Quiz.h"

void printResult(int questions, int correct, int wrong) {
    cout << "Number of questions: " << questions << endl;
    cout << "Number correct answers: " << correct << endl;
    cout << "Number wrong answers: " << wrong << endl;
    cout << "Final score: " << Quiz::getScore() << endl;
}
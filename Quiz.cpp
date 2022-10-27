#include "Quiz.h"

int Quiz::score = 0;

Quiz::Quiz() {
    score = 0;
    question = "";
    answer = "";
}

string Quiz::getAnswer() {
    return answer;
}

string Quiz::getQuestion() {
    return question;
}

int Quiz::getScore() {
    return score;
}

void Quiz::updateScore(int val) {
    score += val;
    score = max(score, 0);
}
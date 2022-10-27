#ifndef QUIZ_H_
#define QUIZ_H_

#include <iostream>
#include <string>

#include "printResult.h"

using namespace std;

class Quiz {
    private:
        string question;
        string answer;
        static int score;
    public:
        Quiz();
        Quiz(string q, string a);
        string getQuestion();
        string getAnswer();
        static int getScore();
        static void updateScore(int val);
};

#endif
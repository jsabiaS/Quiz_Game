//Justin Sabia

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <chrono>

#include "Quiz.h"
#include "printResult.h"

using namespace std;

//Main definition
int main (int argc, char const *argv[]){
    ifstream inputfile;
    vector<Quiz> quizVector;
    string question;
    string answer;
    inputfile.open(argv[1]);

    int numCorrect = 0;
    int numWrong = 0;

    //While the program hasnt reached the end of the .txt file
    while (!inputfile.eof()){
        getline(inputfile, question);
        question.erase(0,3);
        getline(inputfile, answer);
        answer.erase(0,3);
        Quiz quiz1(question, answer);
        quizVector.push_back(quiz1);
    }

    //Initialize random number generator
    srand(unsigned(time(0)));

    //Shuffle the vector randomly 
    random_shuffle(quizVector.begin(), quizVector.end());

    //For loop to go through through the size of the vector based on how many questions are in the .txt
    for(vector<Quiz>::size_type i = 1; i != quizVector.size() - 1; ++i) {
        //variable def to be used to get the answer from the text file and to hold user input
        string inputAnswer;
        string correctAnswer = quizVector[i].getAnswer();

        //Prints the question to the user
        cout << quizVector[i].getQuestion() << endl;
        //Get line extracts characters from input and holds them into a string 
        cout << "Type in your answer: ";
        getline(cin, inputAnswer);
        
        //Temp variable holds true or fallse for the comparison
        int temp = inputAnswer.compare(correctAnswer);
        //If the user answer matches the correct answer it is true
        if (temp == 0){
            quizVector[i].updateScore(1);
            ++numCorrect;
            cout << "Correct!" << endl;
        }
        //if they do not match the users answer was wrong and it will add on to the number of wrong answers
        else {
            quizVector[i].updateScore(-1);
            ++numWrong;
            cout << "Wrong! Correct Answer: " << correctAnswer << endl;
        }
        //Output the current score to the user after each question
        cout << "Current Score: " << Quiz::getScore() << endl;
    }

    cout << printResult(quizVector.size() - 1, numCorrect, numWrong);

    return 0;
}

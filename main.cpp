#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
#include <iomanip>
#include <fstream>
#include "Quiz.h"
#include "printResult.h"

using namespace std;

vector<Quiz> parseDatabase(string fileName) {
	vector<Quiz> quizVector;
	ifstream file1;
	file1.open(fileName);
	if (file1.is_open()) {
		string line;
		while (getline(file1, line)) {
			if (line.substr(0, 2) == "Q:") {
				string question = line.substr(2);
				getline(file1, line);
				if (line.substr(0, 2) == "A:") {
					string answer = line.substr(2);
					quizVector.emplace_back(Quiz(question, answer));
				}
			}
		}
	}
	file1.close();
	//randomly shuffle the vector before returning
    srand(time(0));
	random_shuffle(quizVector.begin(), quizVector.end());
	return quizVector;
}

int main(int argc, char *argv[]) {

    vector<Quiz> quizVector = parseDatabase(argv[1]);
    int numQuestions = quizVector.size();
    int numCorrect = 0;
    int numWrong = 0;
    int userScore = 0;

    srand(time(0));

    while (numQuestions > 0) {

        Quiz quiz1;

        cout << quiz1.getQuestion() << endl;
        string answer;
        cin >> answer;

        if (answer == quiz1.getAnswer()) {
            cout << "Correct!" << endl;
            userScore++;
            numCorrect++;
        }
        else {
            cout << "Wrong! Correct answer: " << quiz1.getAnswer() << endl;
            userScore--;
            numWrong++;
        }
        cout << "Current Score: " << userScore << endl;
        numQuestions--;
        quizVector.erase(quizVector.begin());
    }

    printResult(numQuestions, numCorrect, numWrong);
    return 0;
}
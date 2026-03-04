#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <vector>

using namespace std;

// СТРУКТУРА ЗА ВЪПРОС


struct Question {
    string text;
    vector<string> options;
    int correctIndex;
    string category;
    int points;
};

// СТРУКТУРА ЗА РЕЗУЛТАТ


struct TestResult {
    string username = "";
    int totalPoints = 0;
    int maxPoints = 0;
    double percentage = 0.0;
    int grade = 2;
    vector<int> categoryCorrect;
    vector<int> categoryTotal;
};

// ДЕКЛАРАЦИИ НА ФУНКЦИИ


vector<Question> getAllQuestions();
vector<string> getCategoryNames();
void saveResult(TestResult result);
vector<TestResult> loadAllResults();

#endif
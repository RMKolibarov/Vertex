#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <vector>

struct Question {
    std::string text;
    std::vector<std::string> options;
    int correctIndex = 0;
    std::string category;
    int points = 0;
};

struct TestResult {
    std::string username = "";
    int totalPoints = 0;
    int maxPoints = 0;
    double percentage = 0.0;
    int grade = 2;
    std::vector<int> categoryCorrect;
    std::vector<int> categoryTotal;
};

std::vector<Question> getAllQuestions();
std::vector<std::string> getCategoryNames();
void saveResult(TestResult result);
std::vector<TestResult>  loadAllResults();

#endif
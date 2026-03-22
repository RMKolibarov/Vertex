#ifndef TEST_H
#define TEST_H

#include "questions.h"
#include <string>
#include <vector>

using namespace std;

// Основи:2, Дискриминанта:3, Брой корени:3,
// Намиране на корени:3, Формула на Виет:3,
// Непълни уравнения:3, Текстови задачи:3 = 20

const int QUESTIONS_PER_CATEGORY[] = { 2, 3, 3, 3, 3, 3, 3 };
const int TOTAL_TEST_QUESTIONS = 20;

// СКАЛА ЗА ОЦЕНЯВАНЕ
// 90-100% -> 6
// 75-89%  -> 5
// 60-74%  -> 4
// 45-59%  -> 3
//  0-44%  -> 2

int              calculateGrade(double percentage);
vector<Question> generateTest(vector<Question> bank);
TestResult       runTest(string username);

#endif
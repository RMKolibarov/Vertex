#ifndef TEST_ENGINE_H
#define TEST_ENGINE_H

#include "questions.h"
#include <string>
#include <vector>

using namespace std;

// Expressions:5, Equations:5, Inequalities:4, Functions:3, Word Problems:3 = 20
const int QUESTIONS_PER_CATEGORY[] = { 5, 5, 4, 3, 3 };
const int TOTAL_TEST_QUESTIONS = 20;

//    СКАЛА ЗА ОЦЕНЯВАНЕ
//  90-100%  ->  6 (Отличен)
//  75-89%   ->  5 (Много добър)
//  60-74%   ->  4 (Добър)
//  45-59%   ->  3 (Среден)
//   0-44%   ->  2 (Слаб)

int calculateGrade(double percentage);

// Генерира тест от 20 случайни въпроса по категории
vector<Question> generateTest(vector<Question> bank);

// Рънва теста и връща резултат
TestResult runTest(string username);

#endif
#ifndef TEST_H
#define TEST_H

#include "questions.h"
#include <string>
#include <vector>

using namespace std;

// Basics:2, Discriminant:3, Number of Roots:3,Finding Roots:3, Vieta's Formulas:3, Incomplete Equations:3, Word Problems:3 = 20

const int QUESTIONS_PER_CATEGORY[] = { 2, 3, 3, 3, 3, 3, 3 };
const int TOTAL_TEST_QUESTIONS = 20;

// GRADING SCALE
// 90-100% -> 6
// 75-89%  -> 5
// 60-74%  -> 4
// 45-59%  -> 3
//  0-44%  -> 2

int calculateGrade(double percentage);
vector<Question> generateTest(vector<Question> bank);
TestResult runTest(string username);

#endif
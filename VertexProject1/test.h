#ifndef TEST_ENGINE_H
#define TEST_ENGINE_H

#include "questions.h"
#include <string>
#include <vector>

const int QUESTIONS_PER_CATEGORY[] = { 5, 5, 4, 3, 3 };
const int TOTAL_TEST_QUESTIONS = 20;

int calculateGrade(double percentage);

std::vector<Question> generateTest(std::vector<Question> bank);

TestResult runTest(std::string username);

#endif
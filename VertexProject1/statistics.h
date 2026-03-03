#ifndef STATISTICS_H
#define STATISTICS_H

#include "questions.h"
#include <string>
#include <vector>

using namespace std;

// Показва всички резултати в таблица
void showAllResults();

// Показва средния резултат
void showAverageResult();

// Показва най-добър и най-слаб ученик
void showBestAndWorst();

// Показва статистика по категории
void showCategoryStats();

// Показва резултатите на конкретен ученик
void showStudentResults(string username);

#endif
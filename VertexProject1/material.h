#ifndef STUDY_MATERIAL_H
#define STUDY_MATERIAL_H

#include <string>

using namespace std;

// Главно меню на учебното съдържание
void showStudyMenu();

// Уроци по категории
void lessonExpressions();
void lessonEquations();
void lessonInequalities();
void lessonFunctions();
void lessonWordProblems();

// Упражнения (Practice Mode)
void practiceMode();

// Домашна работа
void homeworkMode();

// Помощна функция за пауза
void pressEnterToContinue();

#endif
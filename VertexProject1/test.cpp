#include <iostream>
#include <ctime>
#include <vector>
#include "test.h"
#include "questions.h"

using namespace std;

// ОЦЕНЯВАНЕ

int calculateGrade(double percentage) {
    if (percentage >= 90.0) return 6;
    if (percentage >= 75.0) return 5;
    if (percentage >= 60.0) return 4;
    if (percentage >= 45.0) return 3;
    return 2;
}

// ГЕНЕРИРАНЕ НА ТЕСТ

vector<Question> generateTest(vector<Question> bank) {
    vector<Question> test;
    vector<string> categories = getCategoryNames();

    srand(time(0));

    for (int c = 0; c < categories.size(); c++) {

        // Събираме всички въпроси от тази категория
        vector<Question> pool;
        for (int i = 0; i < bank.size(); i++) {
            if (bank[i].category == categories[c]) {
                pool.push_back(bank[i]);
            }
        }

        // Разбъркваме въпросите от категорията
        for (int i = pool.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            Question temp = pool[i];
            pool[i] = pool[j];
            pool[j] = temp;
        }

        // Вземаме нужния брой въпроси
        int needed = QUESTIONS_PER_CATEGORY[c];
        for (int i = 0; i < needed && i < pool.size(); i++) {
            test.push_back(pool[i]);
        }
    }

    // Финално разбъркване на целия тест
    for (int i = test.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = test[i];
        test[i] = test[j];
        test[j] = temp;
    }

    return test;
}

// БЕЗОПАСНО ЧЕТЕНЕ НА ОТГОВОР (1-4)

int safeAnswerInput() {
    int value;
    while (true) {
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  Invalid input. Enter 1-4: ";
        }
        else if (value < 1 || value > 4) {
            cout << "  Please enter 1, 2, 3 or 4: ";
        }
        else {
            return value;
        }
    }
}

// РЪНВАНЕ НА ТЕСТА

TestResult runTest(string username) {
    // Зареждаме банката и генерираме тест
    vector<Question> bank = getAllQuestions();
    vector<Question> test = generateTest(bank);
    vector<string> categories = getCategoryNames();

    // Подготвяме броячи за категориите
    vector<int> catCorrect(categories.size(), 0);
    vector<int> catTotal(categories.size(), 0);

    int totalPoints = 0;
    int maxPoints = 0;

    // Заглавие на теста
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     ALGEBRA FUNDAMENTALS TEST          " << '\n';
    cout << "     Student: " << username << '\n';
    cout << "     Questions: " << test.size() << '\n';
    cout << "========================================" << '\n';
    cout << "  Answer each question by entering" << '\n';
    cout << "  the number of your choice (1-4)." << '\n';
    cout << "========================================" << '\n';

    // Задаваме всеки въпрос
    for (int q = 0; q < test.size(); q++) {
        cout << '\n';
        cout << "  Question " << (q + 1) << "/" << test.size();
        cout << "  [" << test[q].category << "]";
        cout << "  (" << test[q].points << " pts)" << '\n';
        cout << "  " << test[q].text << '\n';
        cout << '\n';

        // Показваме опциите
        for (int i = 0; i < test[q].options.size(); i++) {
            cout << "    " << (i + 1) << ". " << test[q].options[i] << '\n';
        }

        cout << '\n';
        cout << "  Your answer: ";
        int answer = safeAnswerInput();

        // Намираме индекса на категорията
        int catIndex = -1;
        for (int i = 0; i < categories.size(); i++) {
            if (categories[i] == test[q].category) {
                catIndex = i;
                break;
            }
        }

        // Добавяме максималните точки
        maxPoints += test[q].points;
        if (catIndex != -1) {
            catTotal[catIndex]++;
        }

        // Проверяваме отговора
        if ((answer - 1) == test[q].correctIndex) {
            cout << "  ✓ Correct! +" << test[q].points << " points" << '\n';
            totalPoints += test[q].points;
            if (catIndex != -1) {
                catCorrect[catIndex]++;
            }
        }
        else {
            cout << "  ✗ Wrong! The correct answer was: "
                << test[q].options[test[q].correctIndex] << '\n';
        }
    }

    // Изчисляваме резултата
    double percentage = 0.0;
    if (maxPoints > 0) {
        percentage = (double)totalPoints / maxPoints * 100.0;
    }
    int grade = calculateGrade(percentage);

    // Показваме резултата
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "           TEST RESULTS                 " << '\n';
    cout << "========================================" << '\n';
    cout << "  Student: " << username << '\n';
    cout << "  Points: " << totalPoints << " / " << maxPoints << '\n';
    cout << "  Percentage: " << (int)percentage << "%" << '\n';
    cout << "  Grade: " << grade << " / 6" << '\n';
    cout << "========================================" << '\n';

    // Показваме резултати по категории
    cout << '\n';
    cout << "  Results by category:" << '\n';
    cout << "  ------------------------------------" << '\n';
    for (int i = 0; i < categories.size(); i++) {
        double catPct = 0.0;
        if (catTotal[i] > 0) {
            catPct = (double)catCorrect[i] / catTotal[i] * 100.0;
        }
        cout << "  " << categories[i] << ": "
            << catCorrect[i] << "/" << catTotal[i]
            << " (" << (int)catPct << "%)" << '\n';
    }
    cout << "  ------------------------------------" << '\n';

    // Създаваме резултата
    TestResult result;
    result.username = username;
    result.totalPoints = totalPoints;
    result.maxPoints = maxPoints;
    result.percentage = percentage;
    result.grade = grade;
    result.categoryCorrect = catCorrect;
    result.categoryTotal = catTotal;

    // Записваме във файл
    saveResult(result);
    cout << "  Result saved successfully!" << '\n';

    return result;
}
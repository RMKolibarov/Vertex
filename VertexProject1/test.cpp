#include "test.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ОЦЕНЯВАНЕ ПО ШЕСТОБАЛНАТА СИСТЕМА

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

    srand((unsigned int)time(0));

    for (int c = 0; c < (int)categories.size(); c++) {

        // Събираме всички въпроси от тази категория
        vector<Question> pool;
        for (int i = 0; i < (int)bank.size(); i++) {
            if (bank[i].category == categories[c]) {
                pool.push_back(bank[i]);
            }
        }

        // Разбъркваме въпросите (Fisher-Yates shuffle)
        for (int i = (int)pool.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            Question temp = pool[i];
            pool[i] = pool[j];
            pool[j] = temp;
        }

        // Вземаме нужния брой въпроси
        int needed = QUESTIONS_PER_CATEGORY[c];
        for (int i = 0; i < needed && i < (int)pool.size(); i++) {
            test.push_back(pool[i]);
        }
    }

    // Финално разбъркване на целия тест
    for (int i = (int)test.size() - 1; i > 0; i--) {
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
            cout << "  Невалиден вход. Въведи 1-4: ";
        }
        else if (value < 1 || value > 4) {
            cout << "  Моля въведи 1, 2, 3 или 4: ";
        }
        else {
            return value;
        }
    }
}

// ПРОВЕЖДАНЕ НА ТЕСТА

TestResult runTest(string username) {
    vector<Question> bank = getAllQuestions();
    vector<Question> test = generateTest(bank);
    vector<string>   categories = getCategoryNames();

    vector<int> catCorrect((int)categories.size(), 0);
    vector<int> catTotal((int)categories.size(), 0);

    int totalPoints = 0;
    int maxPoints = 0;

    // Заглавие на теста
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     ТЕСТ: КВАДРАТНИ УРАВНЕНИЯ          " << '\n';
    cout << "     Ученик: " << username << '\n';
    cout << "     Въпроси: " << test.size() << '\n';
    cout << "========================================" << '\n';
    cout << "  Отговори на всеки въпрос като" << '\n';
    cout << "  въведеш число от 1 до 4." << '\n';
    cout << "========================================" << '\n';

    // Задаваме всеки въпрос
    for (int q = 0; q < (int)test.size(); q++) {

        cout << '\n';
        cout << "  Въпрос " << (q + 1) << "/" << test.size();
        cout << "  [" << test[q].category << "]";
        cout << "  (" << test[q].points << " т.)" << '\n';
        cout << "  " << test[q].text << '\n';
        cout << '\n';

        for (int i = 0; i < (int)test[q].options.size(); i++) {
            cout << "    " << (i + 1) << ". " << test[q].options[i] << '\n';
        }

        cout << '\n';
        cout << "  Твоят отговор: ";
        int answer = safeAnswerInput();

        // Намираме индекса на категорията
        int catIndex = -1;
        for (int i = 0; i < (int)categories.size(); i++) {
            if (categories[i] == test[q].category) {
                catIndex = i;
                break;
            }
        }

        maxPoints += test[q].points;
        if (catIndex != -1) {
            catTotal[catIndex]++;
        }

        // Проверяваме отговора
        if ((answer - 1) == test[q].correctIndex) {
            cout << "  Верно! +" << test[q].points << " точки" << '\n';
            totalPoints += test[q].points;
            if (catIndex != -1) {
                catCorrect[catIndex]++;
            }
        }
        else {
            cout << "  Грешно! Верният отговор е: "
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
    cout << "           РЕЗУЛТАТИ                    " << '\n';
    cout << "========================================" << '\n';
    cout << "  Ученик:   " << username << '\n';
    cout << "  Точки:    " << totalPoints << " / " << maxPoints << '\n';
    cout << "  Процент:  " << (int)percentage << "%" << '\n';
    cout << "  Оценка:   " << grade << " / 6" << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  Резултати по категории:" << '\n';
    cout << "  ----------------------------------------" << '\n';

    for (int i = 0; i < (int)categories.size(); i++) {
        double catPct = 0.0;
        if (catTotal[i] > 0) {
            catPct = (double)catCorrect[i] / catTotal[i] * 100.0;
        }
        cout << "  " << categories[i] << ": "
            << catCorrect[i] << "/" << catTotal[i]
            << " (" << (int)catPct << "%)" << '\n';
    }

    cout << "  ----------------------------------------" << '\n';

    // Създаваме и записваме резултата
    TestResult result;
    result.username = username;
    result.totalPoints = totalPoints;
    result.maxPoints = maxPoints;
    result.percentage = percentage;
    result.grade = grade;
    result.categoryCorrect = catCorrect;
    result.categoryTotal = catTotal;

    saveResult(result);
    cout << '\n';
    cout << "  Резултатът е записан успешно!" << '\n';

    return result;
}
#include "statistics.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ПОКАЗВАНЕ НА ВСИЧКИ РЕЗУЛТАТИ

void showAllResults() {
    vector<TestResult> results = loadAllResults();

    if (results.size() == 0) {
        cout << '\n';
        cout << "  Няма записани резултати." << '\n';
        return;
    }

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "         ВСИЧКИ РЕЗУЛТАТИ               " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  " << left
        << setw(14) << "Ученик"
        << setw(12) << "Точки"
        << setw(10) << "Процент"
        << setw(8) << "Оценка" << '\n';
    cout << "  ----------------------------------------" << '\n';

    for (int i = 0; i < (int)results.size(); i++) {
        string pts = to_string(results[i].totalPoints)
            + "/" + to_string(results[i].maxPoints);
        string pct = to_string((int)results[i].percentage) + "%";

        cout << "  " << left
            << setw(14) << results[i].username
            << setw(12) << pts
            << setw(10) << pct
            << setw(8) << results[i].grade << '\n';
    }

    cout << "  ----------------------------------------" << '\n';
    cout << "  Общо тестове: " << results.size() << '\n';
}

// СРЕДЕН РЕЗУЛТАТ

void showAverageResult() {
    vector<TestResult> results = loadAllResults();

    if (results.size() == 0) {
        cout << '\n';
        cout << "  Няма записани резултати." << '\n';
        return;
    }

    double totalPercentage = 0.0;
    double totalGrade = 0.0;
    int    totalPoints = 0;

    for (int i = 0; i < (int)results.size(); i++) {
        totalPercentage += results[i].percentage;
        totalGrade += results[i].grade;
        totalPoints += results[i].totalPoints;
    }

    double avgPercentage = totalPercentage / results.size();
    double avgGrade = totalGrade / results.size();
    double avgPoints = (double)totalPoints / results.size();

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "       СРЕДНА СТАТИСТИКА                " << '\n';
    cout << "========================================" << '\n';
    cout << "  Общо тестове:      " << results.size() << '\n';
    cout << "  Средни точки:      "
        << fixed << setprecision(1) << avgPoints << '\n';
    cout << "  Среден процент:    "
        << fixed << setprecision(1) << avgPercentage << "%" << '\n';
    cout << "  Средна оценка:     "
        << fixed << setprecision(2) << avgGrade << " / 6" << '\n';
    cout << "========================================" << '\n';
}

// НАЙ-ДОБЪР И НАЙ-СЛАБ УЧЕНИК

void showBestAndWorst() {
    vector<TestResult> results = loadAllResults();

    if (results.size() == 0) {
        cout << '\n';
        cout << "  Няма записани резултати." << '\n';
        return;
    }

    int bestIndex = 0;
    int worstIndex = 0;

    for (int i = 1; i < (int)results.size(); i++) {
        if (results[i].percentage > results[bestIndex].percentage) {
            bestIndex = i;
        }
        if (results[i].percentage < results[worstIndex].percentage) {
            worstIndex = i;
        }
    }

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     НАЙ-ДОБЪР И НАЙ-СЛАБ РЕЗУЛТАТ     " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  НАЙ-ДОБЪР РЕЗУЛТАТ:" << '\n';
    cout << "    Ученик:   " << results[bestIndex].username << '\n';
    cout << "    Точки:    " << results[bestIndex].totalPoints
        << "/" << results[bestIndex].maxPoints << '\n';
    cout << "    Процент:  " << (int)results[bestIndex].percentage << "%" << '\n';
    cout << "    Оценка:   " << results[bestIndex].grade << " / 6" << '\n';
    cout << '\n';
    cout << "  НАЙ-СЛАБ РЕЗУЛТАТ:" << '\n';
    cout << "    Ученик:   " << results[worstIndex].username << '\n';
    cout << "    Точки:    " << results[worstIndex].totalPoints
        << "/" << results[worstIndex].maxPoints << '\n';
    cout << "    Процент:  " << (int)results[worstIndex].percentage << "%" << '\n';
    cout << "    Оценка:   " << results[worstIndex].grade << " / 6" << '\n';
    cout << "========================================" << '\n';
}

// СТАТИСТИКА ПО КАТЕГОРИИ

void showCategoryStats() {
    vector<TestResult> results = loadAllResults();
    vector<string>     categories = getCategoryNames();

    if (results.size() == 0) {
        cout << '\n';
        cout << "  Няма записани резултати." << '\n';
        return;
    }

    vector<int> totalCorrect((int)categories.size(), 0);
    vector<int> totalQuestions((int)categories.size(), 0);

    for (int i = 0; i < (int)results.size(); i++) {
        for (int c = 0; c < (int)categories.size(); c++) {
            if (c < (int)results[i].categoryCorrect.size()) {
                totalCorrect[c] += results[i].categoryCorrect[c];
                totalQuestions[c] += results[i].categoryTotal[c];
            }
        }
    }

    vector<double> catPercentage((int)categories.size(), 0.0);
    int bestCat = 0;
    int worstCat = 0;

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     СТАТИСТИКА ПО КАТЕГОРИИ            " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  " << left
        << setw(24) << "Категория"
        << setw(12) << "Верни"
        << setw(10) << "Успех" << '\n';
    cout << "  ----------------------------------------" << '\n';

    for (int c = 0; c < (int)categories.size(); c++) {
        if (totalQuestions[c] > 0) {
            catPercentage[c] = (double)totalCorrect[c]
                / totalQuestions[c] * 100.0;
        }

        string correct = to_string(totalCorrect[c])
            + "/" + to_string(totalQuestions[c]);
        string pct = to_string((int)catPercentage[c]) + "%";

        cout << "  " << left
            << setw(24) << categories[c]
            << setw(12) << correct
            << setw(10) << pct << '\n';

        if (catPercentage[c] > catPercentage[bestCat])  bestCat = c;
        if (catPercentage[c] < catPercentage[worstCat]) worstCat = c;
    }

    cout << "  ----------------------------------------" << '\n';
    cout << '\n';
    cout << "  Най-лесна категория: " << categories[bestCat]
        << " (" << (int)catPercentage[bestCat] << "%)" << '\n';
    cout << "  Най-трудна категория: " << categories[worstCat]
        << " (" << (int)catPercentage[worstCat] << "%)" << '\n';
    cout << "========================================" << '\n';
}

// РЕЗУЛТАТИ НА КОНКРЕТЕН УЧЕНИК

void showStudentResults(string username) {
    vector<TestResult> results = loadAllResults();
    vector<string>     categories = getCategoryNames();
    bool found = false;
    int  testNum = 0;

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     МОИТЕ РЕЗУЛТАТИ                    " << '\n';
    cout << "     Ученик: " << username << '\n';
    cout << "========================================" << '\n';

    for (int i = 0; i < (int)results.size(); i++) {
        if (results[i].username == username) {
            testNum++;
            found = true;

            cout << '\n';
            cout << "  --- Тест #" << testNum << " ---" << '\n';
            cout << "  Точки:   " << results[i].totalPoints
                << "/" << results[i].maxPoints << '\n';
            cout << "  Процент: " << (int)results[i].percentage << "%" << '\n';
            cout << "  Оценка:  " << results[i].grade << " / 6" << '\n';
            cout << '\n';

            for (int c = 0; c < (int)categories.size(); c++) {
                if (c < (int)results[i].categoryCorrect.size()) {
                    double pct = 0.0;
                    if (results[i].categoryTotal[c] > 0) {
                        pct = (double)results[i].categoryCorrect[c]
                            / results[i].categoryTotal[c] * 100.0;
                    }
                    cout << "    " << left << setw(24) << categories[c]
                        << results[i].categoryCorrect[c] << "/"
                        << results[i].categoryTotal[c]
                        << " (" << (int)pct << "%)" << '\n';
                }
            }
        }
    }

    if (!found) {
        cout << '\n';
        cout << "  Няма записани резултати за този ученик." << '\n';
    }

    cout << "========================================" << '\n';
}
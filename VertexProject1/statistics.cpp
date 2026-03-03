#include "statistics.h"
#include <iostream>
#include <iomanip>

using namespace std;

// ПОКАЗВАНЕ НА ВСИЧКИ РЕЗУЛТАТИ

void showAllResults() {
    vector<TestResult> results = loadAllResults();

    if (results.size() == 0) {
        cout << '\n';
        cout << "  No results found yet." << '\n';
        return;
    }

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "         ALL TEST RESULTS               " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  " << left
        << setw(14) << "Student"
        << setw(10) << "Points"
        << setw(10) << "Percent"
        << setw(8) << "Grade" << '\n';
    cout << "  ----------------------------------------" << '\n';

    for (int i = 0; i < results.size(); i++) {
        cout << "  " << left
            << setw(14) << results[i].username
            << setw(10) << (to_string(results[i].totalPoints) + "/" + to_string(results[i].maxPoints))
            << setw(10) << (to_string((int)results[i].percentage) + "%")
            << setw(8) << results[i].grade << '\n';
    }

    cout << "  ----------------------------------------" << '\n';
    cout << "  Total tests taken: " << results.size() << '\n';
}

// СРЕДЕН РЕЗУЛТАТ

void showAverageResult() {
    vector<TestResult> results = loadAllResults();

    if (results.size() == 0) {
        cout << '\n';
        cout << "  No results found yet." << '\n';
        return;
    }

    double totalPercentage = 0.0;
    double totalGrade = 0.0;
    int totalPoints = 0;

    for (int i = 0; i < results.size(); i++) {
        totalPercentage += results[i].percentage;
        totalGrade += results[i].grade;
        totalPoints += results[i].totalPoints;
    }

    double avgPercentage = totalPercentage / results.size();
    double avgGrade = totalGrade / results.size();
    double avgPoints = (double)totalPoints / results.size();

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "       AVERAGE STATISTICS               " << '\n';
    cout << "========================================" << '\n';
    cout << "  Total tests taken:    " << results.size() << '\n';
    cout << "  Average points:       " << fixed << setprecision(1) << avgPoints << '\n';
    cout << "  Average percentage:   " << fixed << setprecision(1) << avgPercentage << "%" << '\n';
    cout << "  Average grade:        " << fixed << setprecision(2) << avgGrade << " / 6" << '\n';
    cout << "========================================" << '\n';
}

// НАЙ-ДОБЪР И НАЙ-СЛАБ УЧЕНИК

void showBestAndWorst() {
    vector<TestResult> results = loadAllResults();

    if (results.size() == 0) {
        cout << '\n';
        cout << "  No results found yet." << '\n';
        return;
    }

    int bestIndex = 0;
    int worstIndex = 0;

    for (int i = 1; i < results.size(); i++) {
        if (results[i].percentage > results[bestIndex].percentage) {
            bestIndex = i;
        }
        if (results[i].percentage < results[worstIndex].percentage) {
            worstIndex = i;
        }
    }

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     BEST & WORST RESULTS               " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  ★ BEST RESULT:" << '\n';
    cout << "    Percentage: " << (int)results[bestIndex].percentage << "%" << '\n';
    cout << '\n';
    cout << "  ✗ WORST RESULT:" << '\n';
    cout << "    Percentage: " << (int)results[worstIndex].percentage << "%" << '\n';
    cout << "========================================" << '\n';
}

// ============================================
//     СТАТИСТИКА ПО КАТЕГОРИИ
// ============================================

void showCategoryStats() {
    vector<TestResult> results = loadAllResults();
    vector<string> categories = getCategoryNames();

    if (results.size() == 0) {
        cout << '\n';
        cout << "  No results found yet." << '\n';
        return;
    }

    // Сумираме верните и общите за всяка категория
    vector<int> totalCorrect(categories.size(), 0);
    vector<int> totalQuestions(categories.size(), 0);

    for (int i = 0; i < results.size(); i++) {
        for (int c = 0; c < categories.size(); c++) {
            if (c < results[i].categoryCorrect.size()) {
                totalCorrect[c] += results[i].categoryCorrect[c];
                totalQuestions[c] += results[i].categoryTotal[c];
            }
        }
    }

    // Изчисляваме процентите
    vector<double> catPercentage(categories.size(), 0.0);
    int bestCat = 0;
    int worstCat = 0;

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     CATEGORY STATISTICS                " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  " << left
        << setw(18) << "Category"
        << setw(12) << "Correct"
        << setw(10) << "Success" << '\n';
    cout << "  ----------------------------------------" << '\n';

    for (int c = 0; c < categories.size(); c++) {
        if (totalQuestions[c] > 0) {
            catPercentage[c] = (double)totalCorrect[c] / totalQuestions[c] * 100.0;
        }

        cout << "  " << left
            << setw(18) << categories[c]
            << setw(12) << (to_string(totalCorrect[c]) + "/" + to_string(totalQuestions[c]))
            << setw(10) << (to_string((int)catPercentage[c]) + "%") << '\n';

        if (catPercentage[c] > catPercentage[bestCat]) {
            bestCat = c;
        }
        if (catPercentage[c] < catPercentage[worstCat]) {
            worstCat = c;
        }
    }

    cout << "  ----------------------------------------" << '\n';
    cout << '\n';
    cout << "  ★ Easiest category: " << categories[bestCat]
        << " (" << (int)catPercentage[bestCat] << "%)" << '\n';
    cout << "  ✗ Hardest category: " << categories[worstCat]
        << " (" << (int)catPercentage[worstCat] << "%)" << '\n';
    cout << "========================================" << '\n';
}

// ============================================
//     РЕЗУЛТАТИ НА КОНКРЕТЕН УЧЕНИК
// ============================================

void showStudentResults(string username) {
    vector<TestResult> results = loadAllResults();
    vector<string> categories = getCategoryNames();
    bool found = false;
    int testNum = 0;

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     RESULTS FOR: " << username << '\n';
    cout << "========================================" << '\n';

    for (int i = 0; i < results.size(); i++) {
        if (results[i].username == username) {
            testNum++;
            found = true;

            cout << '\n';
            cout << "  --- Test #" << testNum << " ---" << '\n';
            cout << "  Points:     " << results[i].totalPoints
                << "/" << results[i].maxPoints << '\n';
            cout << "  Percentage: " << (int)results[i].percentage << "%" << '\n';
            cout << "  Grade:      " << results[i].grade << " / 6" << '\n';

            // Показваме по категории
            for (int c = 0; c < categories.size(); c++) {
                if (c < results[i].categoryCorrect.size()) {
                    double pct = 0.0;
                    if (results[i].categoryTotal[c] > 0) {
                        pct = (double)results[i].categoryCorrect[c]
                            / results[i].categoryTotal[c] * 100.0;
                    }
                    cout << "    " << categories[c] << ": "
                        << results[i].categoryCorrect[c] << "/"
                        << results[i].categoryTotal[c]
                        << " (" << (int)pct << "%)" << '\n';
                }
            }
        }
    }

    if (!found) {
        cout << "  No results found for this student." << '\n';
    }

    cout << "========================================" << '\n';
}
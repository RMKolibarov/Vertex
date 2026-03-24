#include "test.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int calculateGrade(double percentage) {
    if (percentage >= 90.0) return 6;
    if (percentage >= 75.0) return 5;
    if (percentage >= 60.0) return 4;
    if (percentage >= 45.0) return 3;
    return 2;
}

vector<Question> generateTest(vector<Question> bank) {
    vector<Question> test;
    vector<string> categories = getCategoryNames();

    srand((unsigned int)time(0));

    for (int c = 0; c < (int)categories.size(); c++) {

        // Collect all questions from this category
        vector<Question> pool;
        for (int i = 0; i < (int)bank.size(); i++) {
            if (bank[i].category == categories[c]) {
                pool.push_back(bank[i]);
            }
        }

        // Shuffle the questions
        for (int i = (int)pool.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            Question temp = pool[i];
            pool[i] = pool[j];
            pool[j] = temp;
        }

        // Take the number of questions
        int needed = QUESTIONS_PER_CATEGORY[c];
        for (int i = 0; i < needed && i < (int)pool.size(); i++) {
            test.push_back(pool[i]);
        }
    }

    // Shuffle the test
    for (int i = (int)test.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = test[i];
        test[i] = test[j];
        test[j] = temp;
    }

    return test;
}

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

TestResult runTest(string username) {
    vector<Question> bank = getAllQuestions();
    vector<Question> test = generateTest(bank);
    vector<string>   categories = getCategoryNames();

    vector<int> catCorrect((int)categories.size(), 0);
    vector<int> catTotal((int)categories.size(), 0);

    int totalPoints = 0;
    int maxPoints = 0;

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     TEST: QUADRATIC EQUATIONS          " << '\n';
    cout << "     Student: " << username << '\n';
    cout << "     Questions: " << test.size() << '\n';
    cout << "========================================" << '\n';
    cout << "  Answer each question by entering" << '\n';
    cout << "  a number from 1 to 4." << '\n';
    cout << "========================================" << '\n';

    for (int q = 0; q < (int)test.size(); q++) { //q = Question

        cout << '\n';
        cout << "  Question " << (q + 1) << "/" << test.size();
        cout << "  [" << test[q].category << "]";
        cout << "  (" << test[q].points << " pts)" << '\n';
        cout << "  " << test[q].text << '\n';
        cout << '\n';

        for (int i = 0; i < (int)test[q].options.size(); i++) {
            cout << "    " << (i + 1) << ". " << test[q].options[i] << '\n';
        }

        cout << '\n';
        cout << "  Your answer: ";
        int answer = safeAnswerInput();

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

        if ((answer - 1) == test[q].correctIndex) {
            cout << "  Correct! +" << test[q].points << " points" << '\n';
            totalPoints += test[q].points;
            if (catIndex != -1) {
                catCorrect[catIndex]++;
            }
        }
        else {
            cout << "  Wrong! The correct answer is: "
                << test[q].options[test[q].correctIndex] << '\n';
        }
    }

    double percentage = 0.0;
    if (maxPoints > 0) {
        percentage = (double)totalPoints / maxPoints * 100.0;
    }
    int grade = calculateGrade(percentage);

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "           RESULTS                      " << '\n';
    cout << "========================================" << '\n';
    cout << "  Student:  " << username << '\n';
    cout << "  Points:   " << totalPoints << " / " << maxPoints << '\n';
    cout << "  Percent:  " << (int)percentage << "%" << '\n';
    cout << "  Grade:    " << grade << " / 6" << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  Results by category:" << '\n';
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
    cout << "  Result saved successfully!" << '\n';

    return result;
}
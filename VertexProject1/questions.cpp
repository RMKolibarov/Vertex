#include "questions.h"
#include "test.h"
#include <fstream>
#include <iostream>

using namespace std;

// БАНКА С ВЪПРОСИ (30+)

vector<Question> getAllQuestions() {
    vector<Question> bank;

    // CATEGORY 1: EXPRESSIONS (1 point each)


    bank.push_back({
        "Simplify: 3x + 5x",
        {"8x", "15x", "8x^2", "2x"},
        0, "Expressions", 1
        });

    bank.push_back({
        "Simplify: 7a - 3a + 2a",
        {"6a", "12a", "2a", "6a^2"},
        0, "Expressions", 1
        });

    bank.push_back({
        "Expand: 2(x + 4)",
        {"2x + 4", "2x + 8", "x + 8", "2x + 6"},
        1, "Expressions", 1
        });

    bank.push_back({
        "Simplify: 4x * 3x",
        {"12x", "12x^2", "7x^2", "7x"},
        1, "Expressions", 1
        });

    bank.push_back({
        "Simplify: 10y / 2",
        {"5", "5y", "8y", "20y"},
        1, "Expressions", 1
        });

    bank.push_back({
        "Expand: -(3x - 7)",
        {"-3x - 7", "-3x + 7", "3x + 7", "3x - 7"},
        1, "Expressions", 1
        });

    bank.push_back({
        "Simplify: 2x + 3y - x + y",
        {"x + 4y", "3x + 4y", "x + 2y", "3x + 2y"},
        0, "Expressions", 1
        });

    // CATEGORY 2: EQUATIONS (2 points each)

    bank.push_back({
        "Solve: x + 5 = 12",
        {"x = 5", "x = 7", "x = 17", "x = 6"},
        1, "Equations", 2
        });

    bank.push_back({
        "Solve: 2x = 10",
        {"x = 20", "x = 8", "x = 5", "x = 12"},
        2, "Equations", 2
        });

    bank.push_back({
        "Solve: 3x - 4 = 11",
        {"x = 3", "x = 7", "x = 5", "x = 15"},
        2, "Equations", 2
        });

    bank.push_back({
        "Solve: x / 3 = 9",
        {"x = 3", "x = 6", "x = 12", "x = 27"},
        3, "Equations", 2
        });

    bank.push_back({
        "Solve: 5x + 3 = 2x + 15",
        {"x = 6", "x = 3", "x = 4", "x = 5"},
        2, "Equations", 2
        });

    bank.push_back({
        "Solve: 4(x - 2) = 12",
        {"x = 2", "x = 4", "x = 5", "x = 3"},
        2, "Equations", 2
        });

    bank.push_back({
        "Solve: -2x + 8 = 0",
        {"x = -4", "x = 4", "x = 8", "x = -8"},
        1, "Equations", 2
        });

    // CATEGORY 3: INEQUALITIES (2 points each)


    bank.push_back({
        "Solve: x + 3 > 7",
        {"x > 10", "x > 4", "x < 4", "x > 3"},
        1, "Inequalities", 2
        });

    bank.push_back({
        "Solve: 2x < 10",
        {"x < 20", "x < 5", "x > 5", "x < 8"},
        1, "Inequalities", 2
        });

    bank.push_back({
        "Solve: 3x - 1 >= 8",
        {"x >= 3", "x >= 9", "x >= 2", "x <= 3"},
        0, "Inequalities", 2
        });

    bank.push_back({
        "Solve: -x > 5",
        {"x > 5", "x > -5", "x < -5", "x < 5"},
        2, "Inequalities", 2
        });

    bank.push_back({
        "Which is a solution to x + 2 <= 6?",
        {"x = 5", "x = 4", "x = 7", "x = 10"},
        1, "Inequalities", 2
        });

    bank.push_back({
        "Solve: 4x + 1 > 2x + 9",
        {"x > 5", "x > 4", "x > 8", "x > 2"},
        1, "Inequalities", 2
        });

    // CATEGORY 4: FUNCTIONS (3 points each)


    bank.push_back({
        "If f(x) = 2x + 1, find f(3).",
        {"5", "6", "7", "9"},
        2, "Functions", 3
        });

    bank.push_back({
        "What is the slope of y = 3x - 5?",
        {"-5", "5", "3", "-3"},
        2, "Functions", 3
        });

    bank.push_back({
        "What is the y-intercept of y = 2x + 4?",
        {"2", "4", "-4", "0"},
        1, "Functions", 3
        });

    bank.push_back({
        "If f(x) = x^2 - 1, find f(0).",
        {"0", "1", "-1", "2"},
        2, "Functions", 3
        });

    bank.push_back({
        "Which equation represents a linear function?",
        {"y = x^2", "y = 3x + 1", "y = 1/x", "y = sqrt(x)"},
        1, "Functions", 3
        });

    // CATEGORY 5: WORD PROBLEMS (3 points each)


    bank.push_back({
        "A number doubled and increased by 3 equals 17. Find it.",
        {"6", "7", "8", "10"},
        1, "Word Problems", 3
        });

    bank.push_back({
        "Tom has x apples. He buys 5 more and now has 12. How many did he have?",
        {"5", "6", "7", "17"},
        2, "Word Problems", 3
        });

    bank.push_back({
        "The perimeter of a square is 36 cm. What is the side length?",
        {"6 cm", "9 cm", "12 cm", "18 cm"},
        1, "Word Problems", 3
        });

    bank.push_back({
        "A taxi charges $3 base + $2 per km. Cost for 5 km?",
        {"$10", "$13", "$15", "$11"},
        1, "Word Problems", 3
        });

    bank.push_back({
        "Three consecutive numbers sum to 24. What is the smallest?",
        {"6", "7", "8", "9"},
        1, "Word Problems", 3
        });

    return bank;
}

// ИМЕНА НА КАТЕГОРИИТЕ

vector<string> getCategoryNames() {
    return { "Expressions", "Equations", "Inequalities", "Functions", "Word Problems" };
}

// ЗАПИС НА РЕЗУЛТАТ ВЪВ ФАЙЛ


void saveResult(TestResult result) {
    ofstream file("results.txt", ios::app);

    if (file.is_open()) {
        file << result.username << ","
            << result.totalPoints << ","
            << result.maxPoints << ","
            << result.percentage << ","
            << result.grade;

        for (int i = 0; i < result.categoryCorrect.size(); i++) {
            file << "," << result.categoryCorrect[i]
                << "," << result.categoryTotal[i];
        }

        file << endl;
        file.close();
    }
}

// ЧЕТЕНЕ НА ВСИЧКИ РЕЗУЛТАТИ ОТ ФАЙЛ


vector<TestResult> loadAllResults() {
    vector<TestResult> results;
    ifstream file("results.txt");

    if (!file.is_open()) {
        return results;
    }

    string line;
    while (getline(file, line)) {
        TestResult r;
        vector<string> parts;

        string current = "";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                parts.push_back(current);
                current = "";
            }
            else {
                current += line[i];
            }
        }
        parts.push_back(current);

        if (parts.size() >= 5) {
            r.username = parts[0];
            r.totalPoints = stoi(parts[1]);
            r.maxPoints = stoi(parts[2]);
            r.percentage = stod(parts[3]);
            r.grade = stoi(parts[4]);

            for (int i = 5; i + 1 < parts.size(); i += 2) {
                r.categoryCorrect.push_back(stoi(parts[i]));
                r.categoryTotal.push_back(stoi(parts[i + 1]));
            }

            results.push_back(r);
        }
    }

    file.close();
    return results;
}
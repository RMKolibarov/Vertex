#include "questions.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<Question> getAllQuestions() {
    vector<Question> bank;

    // CATEGORY 1: BASICS (1 point)

    bank.push_back({ "What is the standard form of a quadratic equation?",
        {"ax^2 + bx + c = 0", "ax + b = 0", "ax^3 + bx = 0", "ax^2 = 0"},
        0, "Basics", 1 });

    bank.push_back({ "How many roots can a quadratic equation have?",
        {"0, 1 or 2", "Only 1", "Only 2", "Infinitely many"},
        0, "Basics", 1 });

    bank.push_back({ "Which of the following is a quadratic equation?",
        {"x^2 + 3x - 4 = 0", "3x + 5 = 0", "x^3 - 1 = 0", "5 = 0"},
        0, "Basics", 1 });

    bank.push_back({ "What is the discriminant?",
        {"D = b^2 - 4ac", "D = b^2 + 4ac", "D = 2b - ac", "D = b - 4ac"},
        0, "Basics", 1 });

    // CATEGORY 2: DISCRIMINANT (2 points)

    bank.push_back({ "Find D for: x^2 + 5x + 6 = 0",
        {"1", "49", "11", "-1"},
        0, "Discriminant", 2 });

    bank.push_back({ "Find D for: x^2 - 4x + 4 = 0",
        {"0", "32", "-16", "8"},
        0, "Discriminant", 2 });

    bank.push_back({ "Find D for: x^2 + 2x + 5 = 0",
        {"-16", "24", "16", "-24"},
        0, "Discriminant", 2 });

    bank.push_back({ "Find D for: 2x^2 - 3x + 1 = 0",
        {"1", "-1", "17", "7"},
        0, "Discriminant", 2 });

    bank.push_back({ "Find D for: x^2 - 6x + 9 = 0",
        {"0", "72", "-72", "18"},
        0, "Discriminant", 2 });

    // CATEGORY 3: NUMBER OF ROOTS (2 points)

    bank.push_back({ "D > 0 means the equation has:",
        {"2 distinct roots", "1 root", "No roots", "Infinitely many roots"},
        0, "Number of Roots", 2 });

    bank.push_back({ "D = 0 means the equation has:",
        {"1 double root", "2 roots", "No roots", "3 roots"},
        0, "Number of Roots", 2 });

    bank.push_back({ "D < 0 means the equation has:",
        {"No real roots", "1 root", "2 roots", "Infinitely many roots"},
        0, "Number of Roots", 2 });

    bank.push_back({ "How many roots does x^2 + 1 = 0 have?",
        {"No real roots", "1 root", "2 roots", "3 roots"},
        0, "Number of Roots", 2 });

    bank.push_back({ "How many roots does x^2 - 4 = 0 have?",
        {"2 roots", "1 root", "No roots", "4 roots"},
        0, "Number of Roots", 2 });

    // CATEGORY 4: FINDING ROOTS (3 points)

    bank.push_back({ "Solve: x^2 - 5x + 6 = 0",
        {"x=2 and x=3", "x=1 and x=6", "x=-2 and x=-3", "x=5 and x=1"},
        0, "Finding Roots", 3 });

    bank.push_back({ "Solve: x^2 - 4 = 0",
        {"x=2 and x=-2", "x=4 and x=-4", "x=2", "x=1 and x=-1"},
        0, "Finding Roots", 3 });

    bank.push_back({ "Solve: x^2 + 6x + 9 = 0",
        {"x=-3", "x=3", "x=3 and x=-3", "x=-9"},
        0, "Finding Roots", 3 });

    bank.push_back({ "Solve: x^2 - 7x + 12 = 0",
        {"x=3 and x=4", "x=2 and x=6", "x=1 and x=12", "x=-3 and x=-4"},
        0, "Finding Roots", 3 });

    bank.push_back({ "Solve: 2x^2 - 8 = 0",
        {"x=2 and x=-2", "x=4 and x=-4", "x=8", "x=1 and x=-1"},
        0, "Finding Roots", 3 });

    // CATEGORY 5: VIETA'S FORMULAS (2 points)

    bank.push_back({ "Vieta's formula states that x1+x2 equals:",
        {"-b/a", "b/a", "c/a", "-c/a"},
        0, "Vieta's Formulas", 2 });

    bank.push_back({ "Vieta's formula states that x1*x2 equals:",
        {"c/a", "-c/a", "b/a", "-b/a"},
        0, "Vieta's Formulas", 2 });

    bank.push_back({ "For x^2 - 5x + 6 = 0, what is x1 + x2?",
        {"5", "-5", "6", "-6"},
        0, "Vieta's Formulas", 2 });

    bank.push_back({ "For x^2 - 5x + 6 = 0, what is x1 * x2?",
        {"6", "-6", "5", "-5"},
        0, "Vieta's Formulas", 2 });

    bank.push_back({ "For x^2 + 3x - 10 = 0, what is x1 + x2?",
        {"-3", "3", "-10", "10"},
        0, "Vieta's Formulas", 2 });

    // CATEGORY 6: INCOMPLETE EQUATIONS (2 points)

    bank.push_back({ "Which is an incomplete quadratic equation?",
        {"x^2 - 9 = 0", "x^2 + 3x + 2 = 0", "2x^2 + x - 1 = 0", "x^2 + x = 0"},
        0, "Incomplete Equations", 2 });

    bank.push_back({ "Solve: x^2 - 16 = 0",
        {"x=4 and x=-4", "x=8 and x=-8", "x=16", "x=2 and x=-2"},
        0, "Incomplete Equations", 2 });

    bank.push_back({ "Solve: x^2 = 0",
        {"x=0", "x=1", "No solution", "x=0 and x=1"},
        0, "Incomplete Equations", 2 });

    bank.push_back({ "Solve: 3x^2 - 27 = 0",
        {"x=3 and x=-3", "x=9 and x=-9", "x=27", "x=1 and x=-1"},
        0, "Incomplete Equations", 2 });

    // CATEGORY 7: WORD PROBLEMS (3 points)

    bank.push_back({ "A rectangle with perimeter 20 and area 24. Find the sides.",
        {"4 and 6", "3 and 8", "2 and 12", "5 and 5"},
        0, "Word Problems", 3 });

    bank.push_back({ "The number x is 3 more than its reciprocal. Find x.",
        {"x=3", "x=2", "x=1", "x=4"},
        0, "Word Problems", 3 });

    bank.push_back({ "The sum of squares of two consecutive numbers is 25. Find them.",
        {"3 and 4", "2 and 5", "1 and 4", "4 and 5"},
        0, "Word Problems", 3 });

    return bank;
}

vector<string> getCategoryNames() {
    return {
        "Basics",
        "Discriminant",
        "Number of Roots",
        "Finding Roots",
        "Vieta's Formulas",
        "Incomplete Equations",
        "Word Problems"
    };
}

void saveResult(TestResult result) {
    ofstream file("results.txt", ios::app);

    if (file.is_open()) {
        file << result.username << ","
            << result.totalPoints << ","
            << result.maxPoints << ","
            << result.percentage << ","
            << result.grade;

        for (int i = 0; i < (int)result.categoryCorrect.size(); i++) {
            file << "," << result.categoryCorrect[i]
                << "," << result.categoryTotal[i];
        }

        file << endl;
        file.close();
    }
}

vector<TestResult> loadAllResults() {
    vector<TestResult> results;
    ifstream file("results.txt");

    if (!file.is_open()) {
        return results;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        TestResult r;
        vector<string> parts;
        string current = "";

        for (int i = 0; i < (int)line.length(); i++) {
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

            for (int i = 5; i + 1 < (int)parts.size(); i += 2) {
                r.categoryCorrect.push_back(stoi(parts[i]));
                r.categoryTotal.push_back(stoi(parts[i + 1]));
            }

            results.push_back(r);
        }
    }

    file.close();
    return results;
}
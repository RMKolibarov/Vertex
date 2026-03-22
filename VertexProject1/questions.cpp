#include "questions.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<Question> getAllQuestions() {
    vector<Question> bank;

    // КАТЕГОРИЯ 1: ОСНОВИ НА КВ. УРАВНЕНИЯ (1 точка)

    bank.push_back({ "Кое е стандартното записване на квадратно уравнение?",
        {"ax^2 + bx + c = 0", "ax + b = 0", "ax^3 + bx = 0", "ax^2 = 0"},
        0, "Основи", 1 });

    bank.push_back({ "Колко корена може да има квадратното уравнение?",
        {"0, 1 или 2", "Само 1", "Само 2", "Безкрайно много"},
        0, "Основи", 1 });

    bank.push_back({ "Кое е квадратно уравнение?",
        {"x^2 + 3x - 4 = 0", "3x + 5 = 0", "x^3 - 1 = 0", "5 = 0"},
        0, "Основи", 1 });

    bank.push_back({ "Какво е дискриминантата?",
        {"D = b^2 - 4ac", "D = b^2 + 4ac", "D = 2b - ac", "D = b - 4ac"},
        0, "Основи", 1 });

    // КАТЕГОРИЯ 2: ДИСКРИМИНАНТА (2 точки)

    bank.push_back({ "Намери D за: x^2 + 5x + 6 = 0",
        {"1", "49", "11", "-1"},
        0, "Дискриминанта", 2 });

    bank.push_back({ "Намери D за: x^2 - 4x + 4 = 0",
        {"0", "32", "-16", "8"},
        0, "Дискриминанта", 2 });

    bank.push_back({ "Намери D за: x^2 + 2x + 5 = 0",
        {"-16", "24", "16", "-24"},
        0, "Дискриминанта", 2 });

    bank.push_back({ "Намери D за: 2x^2 - 3x + 1 = 0",
        {"1", "-1", "17", "7"},
        0, "Дискриминанта", 2 });

    bank.push_back({ "Намери D за: x^2 - 6x + 9 = 0",
        {"0", "72", "-72", "18"},
        0, "Дискриминанта", 2 });

    // КАТЕГОРИЯ 3: БРОЙ КОРЕНИ (2 точки)

    bank.push_back({ "D > 0 означава, че уравнението има:",
        {"2 различни корена", "1 корен", "Няма корени", "Безкрайно корени"},
        0, "Брой корени", 2 });

    bank.push_back({ "D = 0 означава, че уравнението има:",
        {"1 двоен корен", "2 корена", "Няма корени", "3 корена"},
        0, "Брой корени", 2 });

    bank.push_back({ "D < 0 означава, че уравнението има:",
        {"Няма реални корени", "1 корен", "2 корена", "Безкрайно корени"},
        0, "Брой корени", 2 });

    bank.push_back({ "Колко корена има x^2 + 1 = 0?",
        {"Няма реални корени", "1 корен", "2 корена", "3 корена"},
        0, "Брой корени", 2 });

    bank.push_back({ "Колко корена има x^2 - 4 = 0?",
        {"2 корена", "1 корен", "Няма корени", "4 корена"},
        0, "Брой корени", 2 });

    // КАТЕГОРИЯ 4: НАМИРАНЕ НА КОРЕНИ (3 точки)

    bank.push_back({ "Реши: x^2 - 5x + 6 = 0",
        {"x=2 и x=3", "x=1 и x=6", "x=-2 и x=-3", "x=5 и x=1"},
        0, "Намиране на корени", 3 });

    bank.push_back({ "Реши: x^2 - 4 = 0",
        {"x=2 и x=-2", "x=4 и x=-4", "x=2", "x=1 и x=-1"},
        0, "Намиране на корени", 3 });

    bank.push_back({ "Реши: x^2 + 6x + 9 = 0",
        {"x=-3", "x=3", "x=3 и x=-3", "x=-9"},
        0, "Намиране на корени", 3 });

    bank.push_back({ "Реши: x^2 - 7x + 12 = 0",
        {"x=3 и x=4", "x=2 и x=6", "x=1 и x=12", "x=-3 и x=-4"},
        0, "Намиране на корени", 3 });

    bank.push_back({ "Реши: 2x^2 - 8 = 0",
        {"x=2 и x=-2", "x=4 и x=-4", "x=8", "x=1 и x=-1"},
        0, "Намиране на корени", 3 });

    // КАТЕГОРИЯ 5: ФОРМУЛА НА ВИЕТ (2 точки)

    bank.push_back({ "Формулата на Виет гласи, че x1+x2 е равно на:",
        {"-b/a", "b/a", "c/a", "-c/a"},
        0, "Формула на Виет", 2 });

    bank.push_back({ "Формулата на Виет гласи, че x1*x2 е равно на:",
        {"c/a", "-c/a", "b/a", "-b/a"},
        0, "Формула на Виет", 2 });

    bank.push_back({ "За x^2 - 5x + 6 = 0, колко е x1 + x2?",
        {"5", "-5", "6", "-6"},
        0, "Формула на Виет", 2 });

    bank.push_back({ "За x^2 - 5x + 6 = 0, колко е x1 * x2?",
        {"6", "-6", "5", "-5"},
        0, "Формула на Виет", 2 });

    bank.push_back({ "За x^2 + 3x - 10 = 0, колко е x1 + x2?",
        {"-3", "3", "-10", "10"},
        0, "Формула на Виет", 2 });

    // КАТЕГОРИЯ 6: НЕПЪЛНИ КВ. УРАВНЕНИЯ (2 точки)

    bank.push_back({ "Кое е непълно квадратно уравнение?",
        {"x^2 - 9 = 0", "x^2 + 3x + 2 = 0", "2x^2 + x - 1 = 0", "x^2 + x = 0"},
        0, "Непълни уравнения", 2 });

    bank.push_back({ "Реши: x^2 - 16 = 0",
        {"x=4 и x=-4", "x=8 и x=-8", "x=16", "x=2 и x=-2"},
        0, "Непълни уравнения", 2 });

    bank.push_back({ "Реши: x^2 = 0",
        {"x=0", "x=1", "Няма решение", "x=0 и x=1"},
        0, "Непълни уравнения", 2 });

    bank.push_back({ "Реши: 3x^2 - 27 = 0",
        {"x=3 и x=-3", "x=9 и x=-9", "x=27", "x=1 и x=-1"},
        0, "Непълни уравнения", 2 });

    // КАТЕГОРИЯ 7: ТЕКСТОВИ ЗАДАЧИ (3 точки)

    bank.push_back({ "Правоъгълник с периметър 20 и лице 24. Намери страните.",
        {"4 и 6", "3 и 8", "2 и 12", "5 и 5"},
        0, "Текстови задачи", 3 });

    bank.push_back({ "Числото x е с 3 по-голямо от своя реципрочен. Намери x.",
        {"x=3", "x=2", "x=1", "x=4"},
        0, "Текстови задачи", 3 });

    bank.push_back({ "Сумата от квадратите на две последователни числа е 25. Намери ги.",
        {"3 и 4", "2 и 5", "1 и 4", "4 и 5"},
        0, "Текстови задачи", 3 });

    return bank;
}

// ИМЕНА НА КАТЕГОРИИТЕ

vector<string> getCategoryNames() {
    return {
        "Основи",
        "Дискриминанта",
        "Брой корени",
        "Намиране на корени",
        "Формула на Виет",
        "Непълни уравнения",
        "Текстови задачи"
    };
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

        for (int i = 0; i < (int)result.categoryCorrect.size(); i++) {
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
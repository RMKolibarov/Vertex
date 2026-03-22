#include <iostream>
#include <string>
#include <vector>
#include "questions.h"
#include "test.h"
#include "statistics.h"
#include "material.h"

using namespace std;

// СТРУКТУРИ

struct User {
    string username = "";
    string passwordHash = "";
    string role = "";
    string subject = "";
};

// ГЛОБАЛНИ ДАННИ

vector<User> users;

// ХЕШИРАНЕ

string hashPassword(string password) {
    string hashed = "";
    for (int i = 0; i < (int)password.length(); i++) {
        hashed += char(password[i] + 3);
    }
    return hashed;
}

// БЕЗОПАСНО ЧЕТЕНЕ НА ВХОД

int safeInput() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  Невалиден вход. Въведи число: ";
    }
    return value;
}

// ЗАРЕЖДАНЕ НА ПОТРЕБИТЕЛИ

void initializeUsers() {
    // Учители
    users.push_back({ "Kandarova",  hashPassword("kandarova123"),  "Teacher", "Chemistry" });
    users.push_back({ "Hristova",   hashPassword("hristova123"),   "Teacher", "Physics" });
    users.push_back({ "Irena",      hashPassword("georgieva123"),  "Teacher", "English" });
    users.push_back({ "MIvanova",   hashPassword("mivanova123"),   "Teacher", "German" });
    users.push_back({ "CIvanova",   hashPassword("civanova123"),   "Teacher", "Biology" });
    users.push_back({ "Simeonov",   hashPassword("simeonov123"),   "Teacher", "Philosophy" });
    users.push_back({ "Pavlov",     hashPassword("pavlov123"),     "Teacher", "Programming" });
    users.push_back({ "Dremsizov",  hashPassword("dremsizov123"),  "Teacher", "Physical Education" });
    users.push_back({ "APetrova",   hashPassword("petrova123"),    "Teacher", "Bulgarian" });
    users.push_back({ "VIvanova",   hashPassword("vivanova123"),   "Teacher", "History" });

    // Ученици
    users.push_back({ "Rafail",   hashPassword("pass1"), "Student", "" });
    users.push_back({ "Hristian", hashPassword("pass2"), "Student", "" });
    users.push_back({ "Nikola",   hashPassword("pass3"), "Student", "" });
    users.push_back({ "Nikolai",  hashPassword("pass4"), "Student", "" });
}

// ЛОГИН

int login() {
    string inputUsername, inputPassword;

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "              ВХОД                      " << '\n';
    cout << "========================================" << '\n';
    cout << "  Потребителско име: ";
    cin >> inputUsername;
    cout << "  Парола: ";
    cin >> inputPassword;

    string inputHash = hashPassword(inputPassword);

    for (int i = 0; i < (int)users.size(); i++) {
        if (users[i].username == inputUsername &&
            users[i].passwordHash == inputHash) {
            return i;
        }
    }

    return -1;
}

// МЕНЮ ЗА УЧЕНИК

void studentMenu(string username) {
    int choice;

    while (true) {
        cout << '\n';
        cout << "========================================" << '\n';
        cout << "     УЧЕНИЧЕСКИ ПАНЕЛ                   " << '\n';
        cout << "     Добре дошъл, " << username << "!" << '\n';
        cout << "========================================" << '\n';
        cout << "  1. Започни тест" << '\n';
        cout << "  2. Виж моите резултати" << '\n';
        cout << "  3. Учебно съдържание" << '\n';
        cout << "  4. Изход" << '\n';
        cout << "========================================" << '\n';
        cout << "  Избери опция: ";
        choice = safeInput();

        if (choice == 1) {
            runTest(username);
        }
        else if (choice == 2) {
            showStudentResults(username);
        }
        else if (choice == 3) {
            showStudyMenu();
        }
        else if (choice == 4) {
            cout << '\n';
            cout << "  Излизане..." << '\n';
            break;
        }
        else {
            cout << "  Невалиден избор. Опитай пак." << '\n';
        }
    }
}

// МЕНЮ ЗА УЧИТЕЛ

void teacherMenu(string username, string subject) {
    int choice;

    while (true) {
        cout << '\n';
        cout << "========================================" << '\n';
        cout << "     УЧИТЕЛСКИ ПАНЕЛ                    " << '\n';
        cout << "     Добре дошъл, " << username << "!" << '\n';
        cout << "     Предмет: " << subject << '\n';
        cout << "========================================" << '\n';
        cout << "  1. Всички резултати" << '\n';
        cout << "  2. Средна статистика" << '\n';
        cout << "  3. Най-добър и най-слаб ученик" << '\n';
        cout << "  4. Статистика по категории" << '\n';
        cout << "  5. Изход" << '\n';
        cout << "========================================" << '\n';
        cout << "  Избери опция: ";
        choice = safeInput();

        if (choice == 1) {
            showAllResults();
        }
        else if (choice == 2) {
            showAverageResult();
        }
        else if (choice == 3) {
            showBestAndWorst();
        }
        else if (choice == 4) {
            showCategoryStats();
        }
        else if (choice == 5) {
            cout << '\n';
            cout << "  Излизане..." << '\n';
            break;
        }
        else {
            cout << "  Невалиден избор. Опитай пак." << '\n';
        }
    }
}

// MAIN

int main() {
    initializeUsers();

    int choice;

    cout << "========================================" << '\n';
    cout << "   VERTEX E-SCHOOL                      " << '\n';
    cout << "   Предмет: Математика                  " << '\n';
    cout << "   Тема: Квадратни уравнения             " << '\n';
    cout << "========================================" << '\n';

    while (true) {
        cout << '\n';
        cout << "  1. Вход" << '\n';
        cout << "  2. Изход" << '\n';
        cout << "  Избери опция: ";
        choice = safeInput();

        if (choice == 1) {
            int userIndex = login();

            if (userIndex != -1) {
                cout << '\n';
                cout << "  Успешен вход!" << '\n';

                if (users[userIndex].role == "Teacher") {
                    teacherMenu(users[userIndex].username,
                        users[userIndex].subject);
                }
                else {
                    studentMenu(users[userIndex].username);
                }
            }
            else {
                cout << '\n';
                cout << "  Грешно потребителско име или парола!" << '\n';
            }
        }
        else if (choice == 2) {
            cout << '\n';
            cout << "  Довиждане от Vertex E-School!" << '\n';
            break;
        }
        else {
            cout << "  Невалиден избор." << '\n';
        }
    }

    return 0;
}
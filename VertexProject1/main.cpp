#include <iostream>
#include <string>
#include <vector>
#include "questions.h"
#include "test.h"
#include "material.h"

using namespace std;

// СТРУКТУРИ

struct User {
    string username;
    string passwordHash;
    string role;
    string subject;
};

// ГЛОБАЛНИ ДАННИ (ПОТРЕБИТЕЛИ)

vector<User> users;

// ХЕШИРАНЕ

string hashPassword(string password) {
    string hashed = "";
    for (int i = 0; i < password.length(); i++) {
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
        cout << "  Invalid input. Enter a number: ";
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
    users.push_back({ "Rafail",    hashPassword("pass1"), "Student", "" });
    users.push_back({ "Hristian",  hashPassword("pass2"), "Student", "" });
    users.push_back({ "Nikola",    hashPassword("pass3"), "Student", "" });
    users.push_back({ "Nikolai",   hashPassword("pass4"), "Student", "" });
}

// ЛОГИН

int login() {
    string inputUsername, inputPassword;

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "              LOGIN                     " << '\n';
    cout << "========================================" << '\n';
    cout << "  Username: ";
    cin >> inputUsername;
    cout << "  Password: ";
    cin >> inputPassword;

    string inputHash = hashPassword(inputPassword);

    for (int i = 0; i < users.size(); i++) {
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
        cout << "     STUDENT DASHBOARD                  " << '\n';
        cout << "     Welcome, " << username << "!" << '\n';
        cout << "========================================" << '\n';
        cout << "  1. Start Test" << '\n';
        cout << "  2. View My Results" << '\n';
        cout << "  3. View Study Material" << '\n';
        cout << "  4. Logout" << '\n';
        cout << "========================================" << '\n';
        cout << "  Choose an option: ";
        choice = safeInput();

        if (choice == 1) {
            cout << '\n';
            cout << "  [TEST] Starting test..." << '\n';
            cout << "  (Person 2 & 3 will add this)" << '\n';
        }
        else if (choice == 2) {
            cout << '\n';
            cout << "  [RESULTS] Your results:" << '\n';
            cout << "  (Person 4 will add this)" << '\n';
        }
        else if (choice == 3) {
            cout << '\n';
            cout << "  [STUDY] Study material:" << '\n';
            cout << "  (Will be added later)" << '\n';
        }
        else if (choice == 4) {
            cout << '\n';
            cout << "  Logging out..." << '\n';
            break;
        }
        else {
            cout << "  Invalid choice. Try again." << '\n';
        }
    }
}

// МЕНЮ ЗА УЧИТЕЛ

void teacherMenu(string username, string subject) {
    int choice;

    while (true) {
        cout << '\n';
        cout << "========================================" << '\n';
        cout << "     TEACHER DASHBOARD                  " << '\n';
        cout << "     Welcome, " << username << "!" << '\n';
        cout << "     Subject: " << subject << '\n';
        cout << "========================================" << '\n';
        cout << "  1. View All Results" << '\n';
        cout << "  2. View Statistics" << '\n';
        cout << "  3. View Best & Worst Students" << '\n';
        cout << "  4. View Category Statistics" << '\n';
        cout << "  5. Logout" << '\n';
        cout << "========================================" << '\n';
        cout << "  Choose an option: ";
        choice = safeInput();

        if (choice == 1) {
            cout << '\n';
            cout << "  [ALL RESULTS] for " << subject << '\n';
            cout << "  (Person 4 will add this)" << '\n';
        }
        else if (choice == 2) {
            cout << '\n';
            cout << "  [STATISTICS] Average grade for " << subject << '\n';
            cout << "  (Person 4 will add this)" << '\n';
        }
        else if (choice == 3) {
            cout << '\n';
            cout << "  [BEST & WORST] in " << subject << '\n';
            cout << "  (Person 4 will add this)" << '\n';
        }
        else if (choice == 4) {
            cout << '\n';
            cout << "  [CATEGORY STATS] for " << subject << '\n';
            cout << "  (Person 4 will add this)" << '\n';
        }
        else if (choice == 5) {
            cout << '\n';
            cout << "  Logging out..." << '\n';
            break;
        }
        else {
            cout << "  Invalid choice. Try again." << '\n';
        }
    }
}

// MAIN PAGE

int main() {
    initializeUsers();

    int choice;

    cout << "========================================" << '\n';
    cout << "   VERTEX E-SCHOOL                      " << '\n';
    cout << "   Subject: Mathematics                 " << '\n';
    cout << "   Topic: Algebra Fundamentals           " << '\n';
    cout << "========================================" << '\n';

    while (true) {
        cout << '\n';
        cout << "  1. Login" << '\n';
        cout << "  2. Exit" << '\n';
        cout << "  Choose an option: ";
        choice = safeInput();

        if (choice == 1) {
            int userIndex = login();

            if (userIndex != -1) {
                cout << '\n';
                cout << "  Login successful!" << '\n';

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
                cout << "  Invalid username or password!" << '\n';
            }
        }
        else if (choice == 2) {
            cout << '\n';
            cout << "  Goodbye from Vertex E-School!" << '\n';
            break;
        }
        else {
            cout << "  Invalid choice." << '\n';
        }
    }

    return 0;
}
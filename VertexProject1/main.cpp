#include <iostream>
#include <string>
#include <vector>
#include "questions.h"
#include "test.h"
#include "statistics.h"
#include "material.h"

using namespace std;

struct User {
    string username = "";
    string passwordHash = "";
    string role = "";
    string subject = "";
};

vector<User> users;

string hashPassword(string password) {
    string hashed = "";
    for (int i = 0; i < (int)password.length(); i++) {
        hashed += char(password[i] + 3);
    }
    return hashed;
}

int safeInput() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  Invalid input. Enter a number: ";
    }
    return value;
}

void initializeUsers() {
    users.push_back({ "OYakimchuk",  hashPassword("123"),  "Teacher", "Math" });
    users.push_back({ "IGeorgieva",      hashPassword("ig123"),  "Teacher", "English" });
    users.push_back({ "VPavlov",     hashPassword("p123"),     "Teacher", "Programming" });
    users.push_back({ "Rafail",   hashPassword("pass1"), "Student", "" });
    users.push_back({ "Hristian", hashPassword("pass2"), "Student", "" });
    users.push_back({ "Nikola",   hashPassword("pass3"), "Student", "" });
    users.push_back({ "Nikolai",  hashPassword("pass4"), "Student", "" });
}

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
    for (int i = 0; i < (int)users.size(); i++) {
        if (users[i].username == inputUsername &&
            users[i].passwordHash == inputHash) {
            return i;
        }
    }
    return -1;
}

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
        cout << "  3. Study Material" << '\n';
        cout << "  4. Logout" << '\n';
        cout << "========================================" << '\n';
        cout << "  Choose an option: ";
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
            cout << "  Logging out..." << '\n';
            break;
        }
        else {
            cout << "  Invalid choice. Try again." << '\n';
        }
    }
}

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
        cout << "  2. View Average Statistics" << '\n';
        cout << "  3. View Best & Worst Students" << '\n';
        cout << "  4. View Category Statistics" << '\n';
        cout << "  5. Logout" << '\n';
        cout << "========================================" << '\n';
        cout << "  Choose an option: ";
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
            cout << "  Logging out..." << '\n';
            break;
        }
        else {
            cout << "  Invalid choice. Try again." << '\n';
        }
    }
}

int main() {
    initializeUsers();
    int choice;
    cout << "========================================" << '\n';
    cout << "   VERTEX E-SCHOOL                      " << '\n';
    cout << "   Subject: Mathematics                 " << '\n';
    cout << "   Topic: Quadratic Equations           " << '\n';
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
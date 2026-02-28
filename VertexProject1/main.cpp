#include <iostream>
#include <string>
#include <vector>

using namespace std;

//СТРУКТУРИ

struct User {
    string username;
    string passwordHash;
    string role;
    string subject;
};

//ГЛОБАЛНИ ДАННИ

vector<User> users;

//ХЕШИРАНЕ

string hashPassword(string password) {
    string hashed = "";
    for (int i = 0; i < password.length(); i++) {
        hashed += char(password[i] + 3);
    }
    return hashed;
}

//ЗАРЕЖДАНЕ НА ПОТРЕБИТЕЛИ

void initializeUsers() {
    // Учители
    User t1;
    t1.username = "Kandarova";
    t1.passwordHash = hashPassword("kandarova123");
    t1.role = "Teacher";
    t1.subject = "Chemistry";
    users.push_back(t1);

    User t2;
    t2.username = "Hristova";
    t2.passwordHash = hashPassword("hristova123");
    t2.role = "Teacher";
    t2.subject = "Physics";
    users.push_back(t2);

    User t3;
    t3.username = "Irena";
    t3.passwordHash = hashPassword("georgieva123");
    t3.role = "Teacher";
    t3.subject = "English";
    users.push_back(t3);

    User t4;
    t4.username = "MIvanova";
    t4.passwordHash = hashPassword("mivanova123");
    t4.role = "Teacher";
    t4.subject = "German";
    users.push_back(t4);

    User t5;
    t5.username = "CIvanova";
    t5.passwordHash = hashPassword("civanova123");
    t5.role = "Teacher";
    t5.subject = "Biology";
    users.push_back(t5);

    User t6;
    t6.username = "Simeonov";
    t6.passwordHash = hashPassword("simeonov123");
    t6.role = "Teacher";
    t6.subject = "Philosophy";
    users.push_back(t6);

    User t8;
    t8.username = "Pavlov";
    t8.passwordHash = hashPassword("pavlov123");
    t8.role = "Teacher";
    t8.subject = "Programming";
    users.push_back(t8);

    User t9;
    t9.username = "Dremsizov";
    t9.passwordHash = hashPassword("dremsizov123");
    t9.role = "Teacher";
    t9.subject = "Physical Education";
    users.push_back(t9);

    User t10;
    t10.username = "APetrova";
    t10.passwordHash = hashPassword("petrova123");
    t10.role = "Teacher";
    t10.subject = "Bulgarian";
    users.push_back(t10);

    User t11;
    t11.username = "VIvanova";
    t11.passwordHash = hashPassword("vivanova123");
    t11.role = "Teacher";
    t11.subject = "Geography";
    t11.subject = "History";
    users.push_back(t11);

    // Ученици
    User s1;
    s1.username = "Rafail";
    s1.passwordHash = hashPassword("pass1");
    s1.role = "Student";
    users.push_back(s1);

    User s2;
    s2.username = "Hristian";
    s2.passwordHash = hashPassword("pass2");
    s2.role = "Student";
    users.push_back(s2);

    User s3;
    s3.username = "Nikola";
    s3.passwordHash = hashPassword("pass3");
    s3.role = "Student";
    users.push_back(s3);

    User s4;
    s4.username = "Nikolai";
    s4.passwordHash = hashPassword("pass4");
    s4.role = "Student";
    users.push_back(s4);

}

//ЛОГИН

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

//МЕНЮ ЗА УЧЕНИК

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
        cin >> choice;

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

//МЕНЮ ЗА УЧИТЕЛ

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
        cin >> choice;

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

//MAIN PAGE

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
        cin >> choice;

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
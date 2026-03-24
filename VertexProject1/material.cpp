#include "material.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void pressEnterToContinue() {
    cout << '\n';
    cout << "  Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void lessonBasics() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 1: BASICS                      " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  A quadratic equation is an equation" << '\n';
    cout << "  of the form:" << '\n';
    cout << '\n';
    cout << "  ================================" << '\n';
    cout << "       ax^2 + bx + c = 0" << '\n';
    cout << "  ================================" << '\n';
    cout << '\n';
    cout << "  where:" << '\n';
    cout << "    a - coefficient of x^2 (a != 0)" << '\n';
    cout << "    b - coefficient of x" << '\n';
    cout << "    c - constant term" << '\n';
    cout << '\n';
    cout << "  EXAMPLES:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  x^2 + 5x + 6 = 0" << '\n';
    cout << "    a=1, b=5, c=6" << '\n';
    cout << '\n';
    cout << "  2x^2 - 3x + 1 = 0" << '\n';
    cout << "    a=2, b=-3, c=1" << '\n';
    cout << '\n';
    cout << "  x^2 - 4 = 0" << '\n';
    cout << "    a=1, b=0, c=-4" << '\n';
    cout << '\n';
    cout << "  TYPES OF QUADRATIC EQUATIONS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  1. Complete: ax^2 + bx + c = 0" << '\n';
    cout << "     (b != 0 and c != 0)" << '\n';
    cout << '\n';
    cout << "  2. Incomplete type 1: ax^2 + c = 0" << '\n';
    cout << "     (b = 0)" << '\n';
    cout << "     Example: x^2 - 9 = 0" << '\n';
    cout << '\n';
    cout << "  3. Incomplete type 2: ax^2 + bx = 0" << '\n';
    cout << "     (c = 0)" << '\n';
    cout << "     Example: x^2 + 3x = 0" << '\n';
    pressEnterToContinue();
}

void lessonDiscriminant() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 2: DISCRIMINANT                " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  The discriminant determines the" << '\n';
    cout << "  number of roots of the equation." << '\n';
    cout << '\n';
    cout << "  FORMULA:" << '\n';
    cout << "  ================================" << '\n';
    cout << "       D = b^2 - 4ac" << '\n';
    cout << "  ================================" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 1: x^2 + 5x + 6 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=1, b=5, c=6" << '\n';
    cout << "    D = 5^2 - 4*1*6" << '\n';
    cout << "    D = 25 - 24 = 1  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 2: x^2 - 4x + 4 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=1, b=-4, c=4" << '\n';
    cout << "    D = (-4)^2 - 4*1*4" << '\n';
    cout << "    D = 16 - 16 = 0  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 3: x^2 + 2x + 5 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=1, b=2, c=5" << '\n';
    cout << "    D = 2^2 - 4*1*5" << '\n';
    cout << "    D = 4 - 20 = -16  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 4: 2x^2 - 3x + 1 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=2, b=-3, c=1" << '\n';
    cout << "    D = (-3)^2 - 4*2*1" << '\n';
    cout << "    D = 9 - 8 = 1  ✓" << '\n';
    pressEnterToContinue();
}

void lessonRoots() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 3: NUMBER OF ROOTS             " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  The number of roots depends on D:" << '\n';
    cout << '\n';
    cout << "  ================================" << '\n';
    cout << "  D > 0  ->  2 distinct roots" << '\n';
    cout << "  D = 0  ->  1 double root" << '\n';
    cout << "  D < 0  ->  no real roots" << '\n';
    cout << "  ================================" << '\n';
    cout << '\n';
    cout << "  EXAMPLES:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  x^2 + 5x + 6 = 0" << '\n';
    cout << "    D = 1 > 0" << '\n';
    cout << "    -> 2 distinct roots  ✓" << '\n';
    cout << '\n';
    cout << "  x^2 - 4x + 4 = 0" << '\n';
    cout << "    D = 0" << '\n';
    cout << "    -> 1 double root  ✓" << '\n';
    cout << '\n';
    cout << "  x^2 + 2x + 5 = 0" << '\n';
    cout << "    D = -16 < 0" << '\n';
    cout << "    -> no real roots  ✓" << '\n';
    cout << '\n';
    cout << "  x^2 + 1 = 0" << '\n';
    cout << "    D = -4 < 0" << '\n';
    cout << "    -> no real roots  ✓" << '\n';
    cout << '\n';
    cout << "  x^2 - 4 = 0" << '\n';
    cout << "    D = 16 > 0" << '\n';
    cout << "    -> 2 distinct roots  ✓" << '\n';
    pressEnterToContinue();
}

void lessonSolving() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 4: FINDING THE ROOTS           " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  FORMULA:" << '\n';
    cout << "  ================================" << '\n';
    cout << "    x1,2 = (-b +/- sqrt(D)) / 2a" << '\n';
    cout << "  ================================" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 1: x^2 - 5x + 6 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=1, b=-5, c=6" << '\n';
    cout << "    D = 25 - 24 = 1" << '\n';
    cout << "    x1 = (5 + 1) / 2 = 3" << '\n';
    cout << "    x2 = (5 - 1) / 2 = 2" << '\n';
    cout << "    x1=3, x2=2  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 2: x^2 - 4 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=1, b=0, c=-4" << '\n';
    cout << "    D = 0 + 16 = 16" << '\n';
    cout << "    x1 = (0 + 4) / 2 = 2" << '\n';
    cout << "    x2 = (0 - 4) / 2 = -2" << '\n';
    cout << "    x1=2, x2=-2  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 3: x^2 + 6x + 9 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=1, b=6, c=9" << '\n';
    cout << "    D = 36 - 36 = 0" << '\n';
    cout << "    x = -6 / 2 = -3" << '\n';
    cout << "    x = -3 (double root)  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 4: x^2 - 7x + 12 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=1, b=-7, c=12" << '\n';
    cout << "    D = 49 - 48 = 1" << '\n';
    cout << "    x1 = (7 + 1) / 2 = 4" << '\n';
    cout << "    x2 = (7 - 1) / 2 = 3" << '\n';
    cout << "    x1=4, x2=3  ✓" << '\n';
    pressEnterToContinue();
}

void lessonVieta() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 5: VIETA'S FORMULAS            " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  Vieta's formulas connect the roots" << '\n';
    cout << "  with the coefficients of the equation." << '\n';
    cout << '\n';
    cout << "  ================================" << '\n';
    cout << "    x1 + x2 = -b/a" << '\n';
    cout << "    x1 * x2 =  c/a" << '\n';
    cout << "  ================================" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 1: x^2 - 5x + 6 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=1, b=-5, c=6" << '\n';
    cout << "    x1 + x2 = -(-5)/1 = 5" << '\n';
    cout << "    x1 * x2 = 6/1 = 6" << '\n';
    cout << "    Check: 2+3=5 ✓, 2*3=6 ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 2: x^2 + 3x - 10 = 0" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    a=1, b=3, c=-10" << '\n';
    cout << "    x1 + x2 = -3" << '\n';
    cout << "    x1 * x2 = -10" << '\n';
    cout << "    Roots: x1=2, x2=-5" << '\n';
    cout << "    Check: 2+(-5)=-3 ✓" << '\n';
    cout << "           2*(-5)=-10 ✓" << '\n';
    pressEnterToContinue();
}

void lessonIncomplete() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 6: INCOMPLETE EQUATIONS        " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  TYPE 1: ax^2 + c = 0 (b=0)" << '\n';
    cout << "  ================================" << '\n';
    cout << "  Example: x^2 - 16 = 0" << '\n';
    cout << "    x^2 = 16" << '\n';
    cout << "    x1=4, x2=-4  ✓" << '\n';
    cout << '\n';
    cout << "  Example: 3x^2 - 27 = 0" << '\n';
    cout << "    3x^2 = 27" << '\n';
    cout << "    x^2 = 9" << '\n';
    cout << "    x1=3, x2=-3  ✓" << '\n';
    cout << '\n';
    cout << "  Example: x^2 = 0" << '\n';
    cout << "    x = 0 (single root)  ✓" << '\n';
    cout << '\n';
    cout << "  TYPE 2: ax^2 + bx = 0 (c=0)" << '\n';
    cout << "  ================================" << '\n';
    cout << "  Example: x^2 + 3x = 0" << '\n';
    cout << "    x(x + 3) = 0" << '\n';
    cout << "    x1=0, x2=-3  ✓" << '\n';
    cout << '\n';
    cout << "  Example: 2x^2 - 8x = 0" << '\n';
    cout << "    2x(x - 4) = 0" << '\n';
    cout << "    x1=0, x2=4  ✓" << '\n';
    pressEnterToContinue();
}

void lessonWordProblems() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 7: WORD PROBLEMS               " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  Steps to solve:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  1. Read carefully" << '\n';
    cout << "  2. Define the unknown x" << '\n';
    cout << "  3. Write the equation" << '\n';
    cout << "  4. Solve the equation" << '\n';
    cout << "  5. Check the answer" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 1:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  'A rectangle with perimeter 20" << '\n';
    cout << "   and area 24. Find the sides.'" << '\n';
    cout << '\n';
    cout << "    Let the sides be x and y." << '\n';
    cout << "    2(x + y) = 20  =>  x + y = 10" << '\n';
    cout << "    x * y = 24" << '\n';
    cout << "    By Vieta: x and y are roots of:" << '\n';
    cout << "    t^2 - 10t + 24 = 0" << '\n';
    cout << "    D = 100 - 96 = 4" << '\n';
    cout << "    t1 = (10+2)/2 = 6" << '\n';
    cout << "    t2 = (10-2)/2 = 4" << '\n';
    cout << "    The sides are 4 and 6  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 2:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  'The sum of the squares of two" << '\n';
    cout << "   consecutive numbers is 25.'" << '\n';
    cout << '\n';
    cout << "    Let the numbers be x and x+1." << '\n';
    cout << "    x^2 + (x+1)^2 = 25" << '\n';
    cout << "    x^2 + x^2 + 2x + 1 = 25" << '\n';
    cout << "    2x^2 + 2x - 24 = 0" << '\n';
    cout << "    x^2 + x - 12 = 0" << '\n';
    cout << "    D = 1 + 48 = 49" << '\n';
    cout << "    x1 = (-1+7)/2 = 3" << '\n';
    cout << "    x2 = (-1-7)/2 = -4" << '\n';
    cout << "    The numbers are 3 and 4  ✓" << '\n';
    pressEnterToContinue();
}

void practiceMode() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     PRACTICE EXERCISES                  " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  Solve the problems, then check!" << '\n';
    cout << '\n';
    cout << "  DISCRIMINANT:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  1. Find D: x^2 + 4x + 3 = 0" << '\n';
    cout << "  2. Find D: x^2 - 6x + 9 = 0" << '\n';
    cout << "  3. Find D: x^2 + x + 1 = 0" << '\n';
    cout << '\n';
    cout << "  NUMBER OF ROOTS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  4. How many roots: x^2 - 9 = 0?" << '\n';
    cout << "  5. How many roots: x^2 + 4 = 0?" << '\n';
    cout << "  6. How many roots: x^2 - 2x + 1 = 0?" << '\n';
    cout << '\n';
    cout << "  FINDING ROOTS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  7. Solve: x^2 - 9 = 0" << '\n';
    cout << "  8. Solve: x^2 + 4x + 3 = 0" << '\n';
    cout << "  9. Solve: x^2 - 2x - 8 = 0" << '\n';
    cout << '\n';
    cout << "  VIETA'S FORMULAS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  10. For x^2 - 7x + 12 = 0" << '\n';
    cout << "      find x1+x2 and x1*x2" << '\n';
    cout << "  11. For x^2 + 5x - 6 = 0" << '\n';
    cout << "      find x1+x2 and x1*x2" << '\n';
    cout << '\n';
    cout << "  INCOMPLETE EQUATIONS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  12. Solve: x^2 - 25 = 0" << '\n';
    cout << "  13. Solve: x^2 + 4x = 0" << '\n';
    cout << "  14. Solve: 4x^2 - 36 = 0" << '\n';

    pressEnterToContinue();

    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     ANSWERS                             " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  DISCRIMINANT:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  1. D = 16 - 12 = 4" << '\n';
    cout << "  2. D = 36 - 36 = 0" << '\n';
    cout << "  3. D = 1 - 4 = -3" << '\n';
    cout << '\n';
    cout << "  NUMBER OF ROOTS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  4. D=36>0 -> 2 roots" << '\n';
    cout << "  5. D=-16<0 -> no roots" << '\n';
    cout << "  6. D=0 -> 1 double root" << '\n';
    cout << '\n';
    cout << "  FINDING ROOTS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  7. x1=3, x2=-3" << '\n';
    cout << "  8. D=4, x1=-1, x2=-3" << '\n';
    cout << "  9. D=36, x1=4, x2=-2" << '\n';
    cout << '\n';
    cout << "  VIETA'S FORMULAS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  10. x1+x2=7, x1*x2=12" << '\n';
    cout << "  11. x1+x2=-5, x1*x2=-6" << '\n';
    cout << '\n';
    cout << "  INCOMPLETE EQUATIONS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  12. x1=5, x2=-5" << '\n';
    cout << "  13. x1=0, x2=-4" << '\n';
    cout << "  14. x^2=9, x1=3, x2=-3" << '\n';

    pressEnterToContinue();
}

void homeworkMode() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     HOMEWORK ASSIGNMENT                 " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  Solve all problems and submit to" << '\n';
    cout << "  your teacher." << '\n';
    cout << '\n';
    cout << "  PART A: Discriminant (6 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  1. Find D: 2x^2 + 5x + 2 = 0" << '\n';
    cout << "  2. Find D: x^2 - 8x + 16 = 0" << '\n';
    cout << "  3. Find D: 3x^2 + x + 1 = 0" << '\n';
    cout << '\n';
    cout << "  PART B: Number of roots (6 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  4. How many roots: x^2 + 6x + 9 = 0?" << '\n';
    cout << "  5. How many roots: 2x^2 + 3x + 5 = 0?" << '\n';
    cout << "  6. How many roots: x^2 - 5x + 4 = 0?" << '\n';
    cout << '\n';
    cout << "  PART C: Finding roots (9 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  7. Solve: x^2 - 8x + 15 = 0" << '\n';
    cout << "  8. Solve: 2x^2 - 5x + 2 = 0" << '\n';
    cout << "  9. Solve: x^2 + 4x - 12 = 0" << '\n';
    cout << '\n';
    cout << "  PART D: Vieta's formulas (6 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  10. For x^2 - 9x + 20 = 0" << '\n';
    cout << "      find x1+x2 and x1*x2" << '\n';
    cout << "  11. Verify that x1=4, x2=5" << '\n';
    cout << "      are roots of the above equation" << '\n';
    cout << '\n';
    cout << "  PART E: Incomplete equations (6 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  12. Solve: x^2 - 49 = 0" << '\n';
    cout << "  13. Solve: 2x^2 + 6x = 0" << '\n';
    cout << "  14. Solve: 5x^2 - 20 = 0" << '\n';
    cout << '\n';
    cout << "  PART F: Word problem (7 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  15. A rectangle with perimeter 26 cm" << '\n';
    cout << "      and area 40 sq.cm." << '\n';
    cout << "      Find the lengths of the sides." << '\n';
    cout << '\n';
    cout << "  ================================" << '\n';
    cout << "  TOTAL: 40 points" << '\n';
    cout << "  ================================" << '\n';

    pressEnterToContinue();
}

void showStudyMenu() {
    int choice;

    while (true) {
        cout << '\n';
        cout << "========================================" << '\n';
        cout << "     STUDY MATERIAL                     " << '\n';
        cout << "     Quadratic Equations               " << '\n';
        cout << "========================================" << '\n';
        cout << '\n';
        cout << "  LESSONS:" << '\n';
        cout << "  1. Basics of quadratic equations" << '\n';
        cout << "  2. Discriminant" << '\n';
        cout << "  3. Number of roots" << '\n';
        cout << "  4. Finding the roots" << '\n';
        cout << "  5. Vieta's formulas" << '\n';
        cout << "  6. Incomplete quadratic equations" << '\n';
        cout << "  7. Word problems" << '\n';
        cout << '\n';
        cout << "  ACTIVITIES:" << '\n';
        cout << "  8. Practice exercises" << '\n';
        cout << "  9. Homework assignment" << '\n';
        cout << '\n';
        cout << "  0. Back" << '\n';
        cout << "========================================" << '\n';
        cout << "  Choose an option: ";

        int value;
        while (!(cin >> value)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  Invalid input. Enter a number: ";
        }
        choice = value;

        if (choice == 1) {
            lessonBasics();
        }
        else if (choice == 2) {
            lessonDiscriminant();
        }
        else if (choice == 3) {
            lessonRoots();
        }
        else if (choice == 4) {
            lessonSolving();
        }
        else if (choice == 5) {
            lessonVieta();
        }
        else if (choice == 6) {
            lessonIncomplete();
        }
        else if (choice == 7) {
            lessonWordProblems();
        }
        else if (choice == 8) {
            practiceMode();
        }
        else if (choice == 9) {
            homeworkMode();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "  Invalid choice. Try again." << '\n';
        }
    }
}
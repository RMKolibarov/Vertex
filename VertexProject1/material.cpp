#include "material.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ============================================
//     ПОМОЩНА ФУНКЦИЯ ЗА ПАУЗА
// ============================================

void pressEnterToContinue() {
    cout << '\n';
    cout << "  Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// ============================================
//     УРОК 1: EXPRESSIONS
// ============================================

void lessonExpressions() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 1: ALGEBRAIC EXPRESSIONS       " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  What is an algebraic expression?" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  An algebraic expression is a" << '\n';
    cout << "  combination of numbers, variables" << '\n';
    cout << "  and operations (+, -, *, /)." << '\n';
    cout << '\n';
    cout << "  Examples:" << '\n';
    cout << "    3x + 5" << '\n';
    cout << "    2a - 7b + 4" << '\n';
    cout << "    4x^2 + 2x - 1" << '\n';
    cout << '\n';
    cout << "  KEY RULES:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << '\n';
    cout << "  1. Combining Like Terms:" << '\n';
    cout << "     Like terms have the same" << '\n';
    cout << "     variable and exponent." << '\n';
    cout << '\n';
    cout << "     Example: 3x + 5x = 8x" << '\n';
    cout << "     Example: 7a - 2a = 5a" << '\n';
    cout << "     Example: 2x + 3y (cannot combine!)" << '\n';
    cout << '\n';
    cout << "  2. Distributive Property:" << '\n';
    cout << "     a(b + c) = ab + ac" << '\n';
    cout << '\n';
    cout << "     Example: 2(x + 4) = 2x + 8" << '\n';
    cout << "     Example: 3(2a - 5) = 6a - 15" << '\n';
    cout << '\n';
    cout << "  3. Negative Signs:" << '\n';
    cout << "     -(a + b) = -a - b" << '\n';
    cout << "     -(a - b) = -a + b" << '\n';
    cout << '\n';
    cout << "     Example: -(3x - 7) = -3x + 7" << '\n';
    cout << '\n';
    cout << "  4. Multiplying Variables:" << '\n';
    cout << "     x * x = x^2" << '\n';
    cout << "     2x * 3x = 6x^2" << '\n';
    cout << "     4x * 3x = 12x^2" << '\n';

    pressEnterToContinue();
}

// ============================================
//     УРОК 2: EQUATIONS
// ============================================

void lessonEquations() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 2: LINEAR EQUATIONS             " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  What is an equation?" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  An equation states that two" << '\n';
    cout << "  expressions are equal." << '\n';
    cout << "  We solve for the unknown variable." << '\n';
    cout << '\n';
    cout << "  SOLVING STEPS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << '\n';
    cout << "  Step 1: Simplify both sides" << '\n';
    cout << "  Step 2: Move variables to one side" << '\n';
    cout << "  Step 3: Move numbers to other side" << '\n';
    cout << "  Step 4: Divide to isolate variable" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 1: Simple" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    x + 5 = 12" << '\n';
    cout << "    x = 12 - 5" << '\n';
    cout << "    x = 7  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 2: Two-step" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    3x - 4 = 11" << '\n';
    cout << "    3x = 11 + 4" << '\n';
    cout << "    3x = 15" << '\n';
    cout << "    x = 15 / 3" << '\n';
    cout << "    x = 5  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 3: Variables on both sides" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    5x + 3 = 2x + 15" << '\n';
    cout << "    5x - 2x = 15 - 3" << '\n';
    cout << "    3x = 12" << '\n';
    cout << "    x = 4  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 4: With brackets" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    4(x - 2) = 12" << '\n';
    cout << "    4x - 8 = 12" << '\n';
    cout << "    4x = 20" << '\n';
    cout << "    x = 5  ✓" << '\n';

    pressEnterToContinue();
}

// ============================================
//     УРОК 3: INEQUALITIES
// ============================================

void lessonInequalities() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 3: INEQUALITIES                 " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  What is an inequality?" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  An inequality compares two values" << '\n';
    cout << "  using: > , < , >= , <=" << '\n';
    cout << '\n';
    cout << "  Symbols:" << '\n';
    cout << "    >   greater than" << '\n';
    cout << "    <   less than" << '\n';
    cout << "    >=  greater than or equal" << '\n';
    cout << "    <=  less than or equal" << '\n';
    cout << '\n';
    cout << "  IMPORTANT RULE:" << '\n';
    cout << "  ================================" << '\n';
    cout << "  When you multiply or divide by" << '\n';
    cout << "  a NEGATIVE number, FLIP the sign!" << '\n';
    cout << "  ================================" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 1: Simple" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    x + 3 > 7" << '\n';
    cout << "    x > 7 - 3" << '\n';
    cout << "    x > 4  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 2: Division" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    2x < 10" << '\n';
    cout << "    x < 5  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 3: Flip the sign!" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    -x > 5" << '\n';
    cout << "    x < -5  ✓  (sign flipped!)" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 4: Multi-step" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    3x - 1 >= 8" << '\n';
    cout << "    3x >= 9" << '\n';
    cout << "    x >= 3  ✓" << '\n';

    pressEnterToContinue();
}

// ============================================
//     УРОК 4: FUNCTIONS
// ============================================

void lessonFunctions() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 4: LINEAR FUNCTIONS             " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  What is a function?" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  A function assigns exactly one" << '\n';
    cout << "  output to each input." << '\n';
    cout << '\n';
    cout << "  Written as: f(x) = expression" << '\n';
    cout << "  Read as: 'f of x'" << '\n';
    cout << '\n';
    cout << "  LINEAR FUNCTION FORM:" << '\n';
    cout << "  ================================" << '\n';
    cout << "       y = mx + b" << '\n';
    cout << "  ================================" << '\n';
    cout << "    m = slope (how steep)" << '\n';
    cout << "    b = y-intercept (where it" << '\n';
    cout << "        crosses the y-axis)" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 1: Evaluating" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    f(x) = 2x + 1" << '\n';
    cout << "    f(3) = 2(3) + 1 = 7  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 2: Finding slope" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    y = 3x - 5" << '\n';
    cout << "    slope (m) = 3" << '\n';
    cout << "    y-intercept (b) = -5" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 3: Is it linear?" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "    y = 3x + 1    -> YES (linear)" << '\n';
    cout << "    y = x^2       -> NO (quadratic)" << '\n';
    cout << "    y = 1/x       -> NO (hyperbola)" << '\n';

    pressEnterToContinue();
}

// ============================================
//     УРОК 5: WORD PROBLEMS
// ============================================

void lessonWordProblems() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "  LESSON 5: WORD PROBLEMS                " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  How to solve word problems:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  Step 1: Read carefully" << '\n';
    cout << "  Step 2: Define the variable (x = ?)" << '\n';
    cout << "  Step 3: Write the equation" << '\n';
    cout << "  Step 4: Solve" << '\n';
    cout << "  Step 5: Check your answer" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 1:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  'A number doubled and increased" << '\n';
    cout << "   by 3 equals 17. Find it.'" << '\n';
    cout << '\n';
    cout << "    Let x = the number" << '\n';
    cout << "    2x + 3 = 17" << '\n';
    cout << "    2x = 14" << '\n';
    cout << "    x = 7  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 2:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  'Tom has x apples. He buys 5 more" << '\n';
    cout << "   and now has 12. How many before?'" << '\n';
    cout << '\n';
    cout << "    x + 5 = 12" << '\n';
    cout << "    x = 7  ✓" << '\n';
    cout << '\n';
    cout << "  EXAMPLE 3:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  'Three consecutive numbers sum" << '\n';
    cout << "   to 24. Find the smallest.'" << '\n';
    cout << '\n';
    cout << "    x + (x+1) + (x+2) = 24" << '\n';
    cout << "    3x + 3 = 24" << '\n';
    cout << "    3x = 21" << '\n';
    cout << "    x = 7  ✓" << '\n';
    cout << "    Numbers: 7, 8, 9" << '\n';

    pressEnterToContinue();
}

// ============================================
//     PRACTICE MODE (Упражнения)
// ============================================

void practiceMode() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     PRACTICE EXERCISES                  " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  Solve these on paper, then check" << '\n';
    cout << "  your answers below." << '\n';
    cout << '\n';
    cout << "  EXPRESSIONS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  1. Simplify: 5x + 3x - 2x" << '\n';
    cout << "  2. Expand: 4(2a + 3)" << '\n';
    cout << "  3. Simplify: 3x * 5x" << '\n';
    cout << '\n';
    cout << "  EQUATIONS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  4. Solve: x + 8 = 15" << '\n';
    cout << "  5. Solve: 4x - 6 = 10" << '\n';
    cout << "  6. Solve: 2(x + 3) = 16" << '\n';
    cout << '\n';
    cout << "  INEQUALITIES:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  7. Solve: x - 4 > 6" << '\n';
    cout << "  8. Solve: 3x <= 18" << '\n';
    cout << "  9. Solve: -2x > 8" << '\n';
    cout << '\n';
    cout << "  FUNCTIONS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  10. If f(x) = 3x - 2, find f(4)" << '\n';
    cout << "  11. What is the slope of y = 5x + 1?" << '\n';
    cout << "  12. Find y-intercept of y = -2x + 7" << '\n';
    cout << '\n';
    cout << "  WORD PROBLEMS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  13. A number tripled minus 4 equals 20." << '\n';
    cout << "      Find the number." << '\n';
    cout << "  14. A rectangle has length 2x and" << '\n';
    cout << "      width x. Perimeter is 30." << '\n';
    cout << "      Find x." << '\n';
    cout << "  15. Two numbers differ by 5 and" << '\n';
    cout << "      sum to 19. Find both." << '\n';

    pressEnterToContinue();

    // Показваме отговорите
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     ANSWERS                             " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  EXPRESSIONS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  1. 5x + 3x - 2x = 6x" << '\n';
    cout << "  2. 4(2a + 3) = 8a + 12" << '\n';
    cout << "  3. 3x * 5x = 15x^2" << '\n';
    cout << '\n';
    cout << "  EQUATIONS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  4. x + 8 = 15" << '\n';
    cout << "     x = 7" << '\n';
    cout << "  5. 4x - 6 = 10" << '\n';
    cout << "     4x = 16" << '\n';
    cout << "     x = 4" << '\n';
    cout << "  6. 2(x + 3) = 16" << '\n';
    cout << "     2x + 6 = 16" << '\n';
    cout << "     2x = 10" << '\n';
    cout << "     x = 5" << '\n';
    cout << '\n';
    cout << "  INEQUALITIES:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  7. x - 4 > 6" << '\n';
    cout << "     x > 10" << '\n';
    cout << "  8. 3x <= 18" << '\n';
    cout << "     x <= 6" << '\n';
    cout << "  9. -2x > 8" << '\n';
    cout << "     x < -4  (sign flipped!)" << '\n';
    cout << '\n';
    cout << "  FUNCTIONS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  10. f(4) = 3(4) - 2 = 10" << '\n';
    cout << "  11. slope = 5" << '\n';
    cout << "  12. y-intercept = 7" << '\n';
    cout << '\n';
    cout << "  WORD PROBLEMS:" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  13. 3x - 4 = 20" << '\n';
    cout << "      3x = 24" << '\n';
    cout << "      x = 8" << '\n';
    cout << "  14. 2(2x) + 2(x) = 30" << '\n';
    cout << "      4x + 2x = 30" << '\n';
    cout << "      6x = 30" << '\n';
    cout << "      x = 5" << '\n';
    cout << "  15. x + y = 19, x - y = 5" << '\n';
    cout << "      2x = 24" << '\n';
    cout << "      x = 12, y = 7" << '\n';

    pressEnterToContinue();
}

// ============================================
//     HOMEWORK MODE (Домашна работа)
// ============================================

void homeworkMode() {
    cout << '\n';
    cout << "========================================" << '\n';
    cout << "     HOMEWORK ASSIGNMENT                 " << '\n';
    cout << "========================================" << '\n';
    cout << '\n';
    cout << "  Complete all tasks and submit your" << '\n';
    cout << "  solutions to your teacher." << '\n';
    cout << '\n';
    cout << "  PART A: Expressions (5 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  1. Simplify: 8x - 3x + x" << '\n';
    cout << "  2. Expand: 5(3y - 2)" << '\n';
    cout << "  3. Simplify: (2x + 3) + (4x - 1)" << '\n';
    cout << "  4. Expand: -2(x - 6)" << '\n';
    cout << "  5. Simplify: 6a * 2a" << '\n';
    cout << '\n';
    cout << "  PART B: Equations (10 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  6. Solve: 3x + 7 = 22" << '\n';
    cout << "  7. Solve: 5x - 3 = 2x + 9" << '\n';
    cout << "  8. Solve: 2(x - 4) = 10" << '\n';
    cout << "  9. Solve: x/4 + 3 = 7" << '\n';
    cout << "  10. Solve: 6x - 2(x + 1) = 14" << '\n';
    cout << '\n';
    cout << "  PART C: Inequalities (10 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  11. Solve: 2x + 1 > 9" << '\n';
    cout << "  12. Solve: -3x <= 12" << '\n';
    cout << "  13. Solve: 5x - 7 >= 3x + 5" << '\n';
    cout << "  14. Solve: 4(x - 1) < 20" << '\n';
    cout << "  15. Solve: -x + 6 > 2" << '\n';
    cout << '\n';
    cout << "  PART D: Functions (10 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  16. If f(x) = 4x - 3, find f(5)" << '\n';
    cout << "  17. If g(x) = x^2 + 2, find g(3)" << '\n';
    cout << "  18. Find slope and y-intercept" << '\n';
    cout << "      of y = -2x + 8" << '\n';
    cout << "  19. Is y = 4/x a linear function?" << '\n';
    cout << "      Explain why or why not." << '\n';
    cout << "  20. Write the equation of a line" << '\n';
    cout << "      with slope 3 and y-intercept 1." << '\n';
    cout << '\n';
    cout << "  PART E: Word Problems (15 points)" << '\n';
    cout << "  --------------------------------" << '\n';
    cout << "  21. Five times a number decreased" << '\n';
    cout << "      by 8 equals 27. Find it." << '\n';
    cout << "  22. A phone plan costs $10/month" << '\n';
    cout << "      plus $0.05 per text. You spent" << '\n';
    cout << "      $16.50. How many texts?" << '\n';
    cout << "  23. The sum of two consecutive even" << '\n';
    cout << "      numbers is 54. Find both." << '\n';
    cout << "  24. A train travels at 60 km/h." << '\n';
    cout << "      How long to travel 210 km?" << '\n';
    cout << "  25. A garden is 3 meters longer" << '\n';
    cout << "      than it is wide. The perimeter" << '\n';
    cout << "      is 26 m. Find dimensions." << '\n';
    cout << '\n';
    cout << "  ================================" << '\n';
    cout << "  TOTAL: 50 points" << '\n';
    cout << "  ================================" << '\n';

    pressEnterToContinue();
}

// ============================================
//     ГЛАВНО МЕНЮ НА УЧЕБНОТО СЪДЪРЖАНИЕ
// ============================================

void showStudyMenu() {
    int choice;

    while (true) {
        cout << '\n';
        cout << "========================================" << '\n';
        cout << "     STUDY MATERIAL                     " << '\n';
        cout << "     Algebra Fundamentals               " << '\n';
        cout << "========================================" << '\n';
        cout << '\n';
        cout << "  LESSONS:" << '\n';
        cout << "  1. Algebraic Expressions" << '\n';
        cout << "  2. Linear Equations" << '\n';
        cout << "  3. Inequalities" << '\n';
        cout << "  4. Linear Functions" << '\n';
        cout << "  5. Word Problems" << '\n';
        cout << '\n';
        cout << "  ACTIVITIES:" << '\n';
        cout << "  6. Practice Exercises" << '\n';
        cout << "  7. Homework Assignment" << '\n';
        cout << '\n';
        cout << "  0. Back to Dashboard" << '\n';
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
            lessonExpressions();
        }
        else if (choice == 2) {
            lessonEquations();
        }
        else if (choice == 3) {
            lessonInequalities();
        }
        else if (choice == 4) {
            lessonFunctions();
        }
        else if (choice == 5) {
            lessonWordProblems();
        }
        else if (choice == 6) {
            practiceMode();
        }
        else if (choice == 7) {
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
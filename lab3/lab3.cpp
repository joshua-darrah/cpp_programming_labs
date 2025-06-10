#include <iostream>
#include <string>
using namespace std;

// 1. Write a global function to find the sum of the first n natural numbers.
inline int sumOfNaturalNumbers(int n) {
    return n * (n + 1) / 2;
}

// 2. Create a Calculator with Overloaded add() Functions:
class Calculator {
public:
    // 2a i. Adding two integers
    inline void add(int a, int b) {
        cout << "Sum (int + int): " << a + b << endl;
    }

    // 2a ii. Adding three integers
    inline void add(int a, int b, int c) {
        cout << "Sum (int + int + int): " << a + b + c << endl;
    }

    // 2a iii. Adding two floating-point numbers
    inline void add(float a, float b) {
        cout << "Sum (float + float): " << a + b << endl;
    }

    // 2a iv. Adding a string and an integer (concatenation)
    inline void add(string s, int n) {
        cout << "Concatenation (string + int): " << s + to_string(n) << endl;
    }

    // 2a v. Adding two strings
    inline void add(string s1, string s2) {
        cout << "Concatenation (string + string): " << s1 + s2 << endl;
    }
};


// MAIN FUNCTION
int main() {
    // Part 1a: Accept integer input and call the global function
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n > 0) {
        int result = sumOfNaturalNumbers(n);
        cout << "Sum of first " << n << " natural numbers is: " << result << endl;
    } else {
        cout << "Invalid input. Please enter a positive integer." << endl;
    }

    cout << endl;

    // Part 2b: Call each overloaded add() function and display result
    Calculator calc;

    // i. Adding two integers
    calc.add(10, 5);

    // ii. Adding three integers
    calc.add(1, 2, 3);

    // iii. Adding two floating-point numbers
    calc.add(2.5f, 4.5f);

    // iv. Adding a string and an integer
    calc.add("COE", 254);

    // v. Adding two strings
    calc.add("Hello, ", "Joshua");

    return 0;
}

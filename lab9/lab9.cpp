#include <iostream>
using namespace std;

// Class for Complex Numbers
class Complex {
private:
    float real, imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload == operator
    bool operator==(const Complex& other) {
        return (real == other.real) && (imag == other.imag);
    }

    // Friend function to overload >> operator
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Friend function to overload << operator
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

// Class for Time Conversion
class Time {
private:
    int hours, minutes;

public:
    Time() : hours(0), minutes(0) {}

    // Constructor to convert from int to Time
    Time(int totalMinutes) {
        hours = totalMinutes / 60;
        minutes = totalMinutes % 60;
    }

    // Conversion operator to int
    operator int() const {
        return hours * 60 + minutes;
    }

    void display() {
        cout << hours << " hours and " << minutes << " minutes" << endl;
    }
};

// Main Function
int main() {
    // Testing Complex class
    Complex c1, c2, sum, diff;
    cout << "Enter first complex number:" << endl;
    cin >> c1;
    cout << "Enter second complex number:" << endl;
    cin >> c2;

    sum = c1 + c2;
    diff = c1 - c2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    if (c1 == c2)
        cout << "The complex numbers are equal." << endl;
    else
        cout << "The complex numbers are not equal." << endl;

    // Testing Time class
    int totalMins = 135;
    Time t = totalMins; // Calls constructor
    cout << "\nTime from int (135 mins): ";
    t.display();

    int convertedMins = t; // Calls conversion operator
    cout << "Converted back to int: " << convertedMins << " minutes" << endl;

    return 0;
}

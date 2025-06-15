#include <iostream>
using namespace std;

class Quadrilateral {
private:
    int x, y;

public:
    // Constructor initializing x and y to 1
    Quadrilateral() {
        x = 1;
        y = 1;
        cout << "Constructor called.\n";
    }

    // Destructor
    ~Quadrilateral() {
        cout << "Destructor called for object.\n";
    }

    // Function to set values of x and y
    void set_values(int a, int b) {
        x = a;
        y = b;
    }

    // Function to calculate and return area
    int area() {
        return x * y;
    }
};

int main() {
    // Create two objects: square and rectangle
    Quadrilateral square, rectangle;

    // Set values for square (10, 10)
    square.set_values(10, 10);

    // Set values for rectangle (5, 10)
    rectangle.set_values(5, 10);

    // Display area values
    cout << "Area of square: " << square.area() << endl;
    cout << "Area of rectangle: " << rectangle.area() << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Printing Hello World
    cout << "Hello, World!" << endl;

    // Declaring Variables
    int id = 17785; 
    string greeting = "Welcome to this class!"; 
    float CWA = -56.1427; 
    string referenceNum = "5262778y"; 
    int a = 5, b = 5, c = 5; 
    bool passed = true; 
    char name[11]; 

    // Declaring Age and Year variables for Birth Year Calculations
    int age;
    int currentYear = 2025;

    // Receiving user input into the age variable
    cout << "Kindly enter your age:" << endl; 
    cin >> age;

    // Calculating user's birth year
    int birthYear = currentYear - age;
    cout << "You were born in " << birthYear << "." << endl;

    // Initializing an array
    int Marks[] = {67, 71, 54, 43, 82, 90}; 

    // Changing the third value to 75
    Marks[2] = 75; 

    // Assigning the fifth value to a new variable
    int AppliedElectricity = Marks[4]; 

    return 0;
}

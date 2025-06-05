#include <iostream>
using namespace std;

int main() {
    float height_cm, weight_kg, bmi;

    // Asking for user's height and weight
    cout << "Enter your height (in cm): ";
    cin >> height_cm;

    cout << "Enter your weight (in kg): ";
    cin >> weight_kg;

    // Converting user's height from centimeters to meters
    float height_m = height_cm / 100;

    // Calculating the BMI of the user
    bmi = weight_kg / (height_m * height_m);

    // Displaying user's BMI
    cout << "Your BMI is: " << bmi << " kg/m^2" << endl;

    // Determining user's weight status
    if (bmi < 18.5) {
        cout << "You are underweight." << endl;
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        cout << "Your weight is normal." << endl;
    } else if (bmi >= 25 && bmi <= 29.9) {
        cout << "You are overweight." << endl;
    } else if (bmi >= 30 && bmi <= 39.9) {
        cout << "You are obese." << endl;
    } else {
        cout << "You are morbidly obese." << endl;
    }

    return 0;
}

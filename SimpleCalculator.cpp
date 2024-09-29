#include <iostream>
#include <limits>

using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Error: Division by zero!");
    }
    return a / b;
}

int main() {
    double num1, num2, result;
    char operation;
    bool continue_calc = true;

    while (continue_calc) {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        try {
            switch (operation) {
                case '+':
                    result = add(num1, num2);
                    break;
                case '-':
                    result = subtract(num1, num2);
                    break;
                case '*':
                    result = multiply(num1, num2);
                    break;
                case '/':
                    result = divide(num1, num2);
                    break;
                default:
                    throw runtime_error("Error: Invalid operation!");
            }

            cout << "Result: " << result << endl;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        char choice;
        cin >> choice;
        continue_calc = (choice == 'y' || choice == 'Y');

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}
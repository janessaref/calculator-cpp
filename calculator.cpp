#include <iostream>
using namespace std;

class Calculator {
    public:
        Calculator() : result(0), num1(0), num2(0) {}
        void setNum1(double x);
        void setNum2(double y);
        double add();
        double subtract();
        double multiply();
        double divide();
        double getResult();
        double validateNum();
        void reset();
        void printCalculation(char operation);
    private:
        // Private variables to store the operands and the result of calculation
        double result;
        double num1;
        double num2;
};
// sets the first operand for the calculation
void Calculator::setNum1(double x) {
     num1 = x;
}
// sets the second operand for the calculation
void Calculator::setNum2(double y) {
     num2 = y;
}
// add the two operands and updates the result and returns it
double Calculator::add() {
    result = num1 + num2;
    return result;
}
// subtract the two operands and updates the result and returns it
double Calculator::subtract() {
    result = num1 - num2;
    return result;
}
// multiply the two operands and updates the result and returns it
double Calculator::multiply() {
    result = num1 * num2;
    return result;
}
// divides the first operand by the second, updates the result, and returns it
double Calculator::divide() {
    // if the second operand is 0, displays an error and return the last saved result
    if (num2 == 0) {
        cout << "Error! Can't divide by zero." << endl;
        return result;
    }
    result = num1 / num2;
    return result;
} 
// validates the numbers from user input to ensure it's a valid number
double Calculator::validateNum() {
    double num;
    // loop to keep prompting the user until a valid number is entered
    while (true) {
        cin >> num;
        // checks for invalid inputs, discards them and prompts user to enter a valid number otherwise, returns valid number
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid input. Please enter a valid number: ";
        }
        else {
            return num;
        }
    }
}
// outputs the result
double Calculator::getResult() {
    return result;
}
// resets the calculator variables to its intial state
void Calculator::reset() {
    num1 = 0;
    num2 = 0;
    result = 0;
    cout << "Calculator reset" << endl;
}
// displays the operation and the result to the user
void Calculator::printCalculation(char operation) {
    cout << num1 << " " << operation << " " << num2 << " " << "= " << result << endl;
}

int main() {
    // variables to store user inputs and the operation to perform
    Calculator calc;
    double x;
    double y;
    char operation;

    // prompts the user to input the first operand
    cout << "----------------------------" << endl;
    cout << "CALCULATOR" << endl;
    cout << "----------------------------" << endl;
    cout << "Enter a number: ";
    // call validateNum() to ensure the user inputs a valid number
    x = calc.validateNum();
    // sets the first number to be saved
    calc.setNum1(x);

    // loop to allow continuous calculations using the last result
    while (true) {
        // takes in the operation to use and execute
        cout << "Choose from the following operations:" << endl;
        cout << "(+ to add, - to subtract , * to multiply, / to divide, r to reset, q to quit)" << endl;
        cin >> operation;

        // handles user commands to quit to end the program and loop or reset the calculator
        if (operation == 'q') {
            cout << "Goodbye!" << endl;
            break;
        }
        else if (operation == 'r') {
            // calls the reset function to set all variables back to zero, take in the first number, validate it and save
            calc.reset();
            cout << "Enter a number: ";
            x = calc.validateNum();
            calc.setNum1(x);
            continue;
        }

        // validates the operation input and prompts the user to try again if invalid
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            cout << "Invalid operation. Please try again." << endl;
            continue;
        }

        // prompts the user to input the second operand, validates the oeprand and save
        cout << "Enter a number: ";
        y = calc.validateNum();
        calc.setNum2(y);

        // executes the chosen operation based on user input
        switch (operation) {
            case '+':
                calc.add();
                break;
            case '-':
                calc.subtract();
                break;
            case '*':
                calc.multiply();
                break;
            case '/':
                calc.divide();
                break;
        } 

        // prints the equation used to the user
        calc.printCalculation(operation);
        // sets the result as the first operand for continued calculations
        calc.setNum1(calc.getResult());
        cout << "----------------------------" << endl;
        // displays the current result
        cout << "Current Result: " << calc.getResult() << endl;
        cout << "----------------------------" << endl;

    }
    return 0;
}


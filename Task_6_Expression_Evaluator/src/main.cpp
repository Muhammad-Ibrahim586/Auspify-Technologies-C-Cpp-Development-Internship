#include "ExpressionEvaluator.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu(){
    cout << "\n ========================================\n";
    cout << "         EXPRESSION EVALUATOR\n";
    cout << " ========================================\n";
    cout << "  Supported operators: +  -  *  /\n";
    cout << "  Parentheses are supported.\n";
    cout << "  Type 'exit' to close the program.\n";
    cout << " ========================================\n";
}

int main(){
    ExpressionEvaluator evaluator;

    displayMenu();

    while (true) {
        string expression;

        cout << "\n Enter expression: ";
        getline(cin, expression);

        if (expression == "exit" || expression == "EXIT" || expression == "Exit") {

            cout << "\n Thank you for using Expression Evaluator!\n";
            break;
        }

        try {
            double result = evaluator.evaluate(expression);

            cout << " Result: " << result << endl;
        }
        catch (const exception& e) {
            cout << " Error: " << e.what() << endl;
        }
    }

    return 0;
}

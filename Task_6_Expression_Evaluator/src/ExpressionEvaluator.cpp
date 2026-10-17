#include "ExpressionEvaluator.h"

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <cctype>
#include <cmath>

using namespace std;

// Check whether a character is an operator
bool ExpressionEvaluator :: isOperator(char c) const{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Return operator precedence
int ExpressionEvaluator :: precedence(char op) const{
    if (op == '+' || op == '-') {
        return 1;
    }

    if (op == '*' || op == '/') {
        return 2;
    }

    return 0;
}

// Validate basic expression structure
bool ExpressionEvaluator::isValidExpression(const string& expression) const{
    if (expression.empty()) {
        return false;
    }

    stack<char> brackets;
    bool expectingOperand = true;

    for (char c : expression) {
        if (isspace(static_cast<unsigned char>(c))) {
            continue;
        }

        // Opening brackets
        if (c == '(' || c == '[' || c == '{') {
            if (!expectingOperand) {
                return false;
            }

            brackets.push(c);
            expectingOperand = true;
        }

        // Closing brackets
        else if (c == ')' || c == ']' || c == '}') {
            if (expectingOperand || brackets.empty()) {
                return false;
            }

            char opening = brackets.top();
            brackets.pop();

            if ((c == ')' && opening != '(') ||
                (c == ']' && opening != '[') ||
                (c == '}' && opening != '{')) {
                return false;
            }

            expectingOperand = false;
        }

        // Operators
        else if (isOperator(c)) {
            if (expectingOperand) {
                return false;
            }

            expectingOperand = true;
        }

        // Numbers
        else if (isdigit(static_cast<unsigned char>(c)) || c == '.') {
            expectingOperand = false;
        }

        // Invalid character
        else {
            return false;
        }
    }

    return !expectingOperand && brackets.empty();
}

// Convert expression into tokens
vector<string> ExpressionEvaluator :: tokenize(const string& expression) const{
    vector<string> tokens;

    for (size_t i = 0; i < expression.length(); ) {
        char c = expression[i];

        if (isspace(static_cast<unsigned char>(c))) {
            ++i;
            continue;
        }

        if (isdigit(static_cast<unsigned char>(c)) || c == '.') {

            string number;

            bool decimalPointFound = false;

            while (i < expression.length() && (isdigit(static_cast<unsigned char>(expression[i])) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    if (decimalPointFound) {
                        throw runtime_error(" Invalid number format!");
                    }

                    decimalPointFound = true;
                }

                number += expression[i];
                ++i;
            }

            tokens.push_back(number);
        }
        else if (isOperator(c) || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') {

            tokens.push_back(string(1, c));
            ++i;
        }
        else {
            throw runtime_error(" Invalid character in expression!");
        }
    }

    return tokens;
}

// Convert infix expression to postfix
vector<string> ExpressionEvaluator::infixToPostfix(const vector<string>& tokens) const{
    vector<string> output;
    stack<string> operators;

    for (const string& token : tokens) {

        // Number
        if (isdigit(static_cast<unsigned char>(token[0])) || token[0] == '.') {
            output.push_back(token);
        }

        // Opening brackets
        else if (token == "(" || token == "[" || token == "{") {
            operators.push(token);
        }

        // Closing brackets
        else if (token == ")" || token == "]" || token == "}") {
            while (!operators.empty() && operators.top() != "(" && operators.top() != "[" && operators.top() != "{") {
                output.push_back(operators.top());
                
                operators.pop();
            }

            if (operators.empty()) {
                throw runtime_error(" Mismatched brackets!");
            }

            // Remove the matching opening bracket
            operators.pop();
        }

        // Operator
        else if (isOperator(token[0])) {
            while (!operators.empty() && operators.top() != "(" && operators.top() != "[" && operators.top() != "{" && precedence(operators.top()[0]) >= precedence(token[0])) {
                output.push_back(operators.top());
                
                operators.pop();
            }

            operators.push(token);
        }
    }

    // Empty remaining operators
    while (!operators.empty()) {

        if (operators.top() == "(" || operators.top() == "[" || operators.top() == "{") {
            throw runtime_error("  Mismatched brackets!");
        }

        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

// Evaluate postfix expression
double ExpressionEvaluator :: evaluatePostfix(const vector<string>& postfix) const{
    stack<double> values;

    for (const string& token : postfix) {

        // Number
        if (isdigit(static_cast<unsigned char>(token[0])) || token[0] == '.') {
            values.push(stod(token));
            continue;
        }

        // Operator requires two operands
        if (values.size() < 2) {
            throw runtime_error(" Invalid expression!");
        }

        double right = values.top();
        values.pop();

        double left = values.top();
        values.pop();

        double result;

        switch (token[0]) {
            case '+':
                result = left + right;
                break;

            case '-':
                result = left - right;
                break;

            case '*':
                result = left * right;
                break;

            case '/':
                if (fabs(right) < 1e-12) {
                    throw runtime_error(" Division by zero is not allowed!");
                }

                result = left / right;
                break;

            default:
                throw runtime_error(" Unknown operator!");
        }

        values.push(result);
    }

    if (values.size() != 1) {
        throw runtime_error(" Invalid expression!");
    }

    return values.top();
}

// Public evaluation function
double ExpressionEvaluator :: evaluate(const string& expression) const{
    if (!isValidExpression(expression)) {
        throw runtime_error(" Invalid expression format!");
    }

    vector<string> tokens = tokenize(expression);

    vector<string> postfix = infixToPostfix(tokens);

    return evaluatePostfix(postfix);
}

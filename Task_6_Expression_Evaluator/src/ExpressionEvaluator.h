#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include <string>
#include <vector>

class ExpressionEvaluator{
    private:
        bool isOperator(char c) const;
        int precedence(char op) const;
        bool isValidExpression(const std::string& expression) const;

        std::vector<std::string> tokenize(const std::string& expression) const;

        std::vector<std::string> infixToPostfix(const std::vector<std::string>& tokens) const;

        double evaluatePostfix(const std::vector<std::string>& postfix) const;

    public:
        double evaluate(const std::string& expression) const;
};

#endif

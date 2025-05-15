#include "RPN.hpp"

bool isOperator(char c)
{
    std::string operators = "-*/+";
    if (operators.find(c) != std::string::npos)
        return true;
    return false;
}

void printStack(std::stack<std::string> stk)
{
    while (!stk.empty())
    {
        std::cout << stk.top() << std::endl;
        stk.pop();
    }
}

void revert(std::stack<std::string> &stk)
{
    std::stack<std::string> result;
    while(!stk.empty())
    {
        result.push(stk.top());
        stk.pop();
    }
    stk = result;
}

void    fillStack(std::stack<std::string> &stk, const std::string &input)
{
    std::istringstream iss(input);
    std::string word;
    while (iss >> word)
        stk.push(word);
}

bool    checkValidValue(std::string str)
{
    if (str.length() != 1 || !(isOperator(str[0]) || isdigit(str[0])))
        return false;
    return true;
}

bool    checkValidInput(std::stack<std::string> &stk)
{
    std::stack<std::string> finalStack;
    if (stk.size() < 3)
        throw StackNotFilledEnoughException();
    while (!stk.empty())
    {
        if (!checkValidValue(stk.top()))
            throw InvalidValueException();
        finalStack.push(stk.top());
        stk.pop();
    }
    stk = finalStack;
    return true;
}

double add(std::stack<double> &stk)
{
    double a = stk.top();
    stk.pop();
    double b = stk.top();
    stk.pop();
    return (b + a);
}

double substract(std::stack<double> &stk)
{
    double a = stk.top();
    stk.pop();
    double b = stk.top();
    stk.pop();
    return (b - a);
}

double multiply(std::stack<double> &stk)
{
    double a = stk.top();
    stk.pop();
    double b = stk.top();
    stk.pop();
    return (b * a);
}

double divide(std::stack<double> &stk)
{
    double a = stk.top();
    stk.pop();
    double b = stk.top();
    stk.pop();
    if (a == 0)
        throw DivisionByZeroException();
    return (b / a);
}

void calculate(std::stack<double> &stk, char operand)
{
    if (stk.size() < 2)
        throw RPNFailException();
    switch (operand)
    {
    case '+':
        stk.push(add(stk));
        break;
    case '-' :
        stk.push(substract(stk));
        break;
    case '*' :
        stk.push(multiply(stk));
        break;
    case '/' :
        stk.push(divide(stk));
        break;
    }
}

void operateRPN(std::stack<std::string> &stk)
{   
    try
    {
        std::stack<double> result;
        while (!stk.empty())
        {
            if (isdigit(stk.top()[0]))
                result.push(strtod(stk.top().c_str(), NULL));
            else
                calculate(result, stk.top()[0]);
            stk.pop();
        }
        if (result.size() != 1)
            throw RPNFailException();
        std::cout << "result : " << result.top() <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return ;
    }
}

void initRPNCalculator(const std::string &input)
{
    try
    {
        std::stack<std::string> stk;
        fillStack(stk, input);
        checkValidInput(stk);
        operateRPN(stk);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
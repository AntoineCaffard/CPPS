#pragma once

#include <stack>
#include <iostream>
#include <algorithm>
#include <sstream>

void    initRPNCalculator(const std::string &input);
void    fillStack(std::stack<std::string> &stk, const std::string &input);
bool    checkValidInput(std::stack<std::string> &stk);

class NotEnoughArgumentsException : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Error : You must have one argument");
    };
};

class RPNFailException : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Error : Invalid RPN Input");
    };
};

class DivisionByZeroException : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Error : You cannot divide by zero");
    };
};

class StackNotFilledEnoughException : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Error : Stack is not filled enough");
    };
};

class InvalidValueException : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Error : Invalid value");
    };
};


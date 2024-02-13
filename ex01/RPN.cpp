#include "RPN.hpp"

std::stack<float> RPN::num;

RPN::RPN()
{
    num = std::stack<float>();
}

RPN::RPN(const RPN &New)
{
    num = New.num;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &New)
{
    num = New.num;
    return *this;
}

bool RPN::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

void RPN::parse(std::string str)
{
    int nm;
    int op;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            nm++;
        else if (isOperator(str[i]))
            op++;
        else if (str[i] == ' ')
            continue;
        else if (str[i] = '-' && (i + 1 < str.length()) && isdigit(str[i + 1]))
            throw std::invalid_argument("Numbers must be positive integers between 0 and 9");
        else if (isOperator(str[i]) && (i + 1 < str.length()) && isdigit(str[i + 1]))
            throw std::invalid_argument("Numbers and operators must be separated by a space");
        else if (isOperator(str[i]) && (i + 1 < str.length()) && isOperator(str[i + 1]))
            throw std::invalid_argument("Multiple operators must be separated by a space");
        else if (isdigit(str[i]) && (i + 1 < str.length()) && isdigit(str[i + 1]))
            throw std::invalid_argument("Numbers must be positive integers between 0 and 9");
        else if (isdigit(str[i]) && (i + 1 < str.length()) && isOperator(str[i + 1]))
            throw std::invalid_argument("Numbers and operators must be separated by a space");
        else
            throw std::invalid_argument("Invalid character in string");
    }
    if (nm - op != 1)
        throw std::invalid_argument("Invalid number of operators");
}

void RPN::print(std::string str)
{
    int nm;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            continue;
        else if (isdigit(str[i]))
            nm++;
        else if (isOperator(str[i]))
            continue;
    }
}

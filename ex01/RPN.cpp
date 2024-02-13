#include "RPN.hpp"

std::stack<double> RPN::num;

RPN::RPN()
{
    num = std::stack<double>();
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
    int nm = 0;
    int op = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            nm++;
        else if (isOperator(str[i]))
            op++;
        else if (str[i] == ' ')
            continue;
        else
            throw std::invalid_argument("Invalid character in string");

        if (str[i] == '-' && (i + 1 < str.length()) && isdigit(str[i + 1]))
            throw std::invalid_argument("Numbers must be positive integers between 0 and 9");
        else if (isOperator(str[i]) && (i + 1 < str.length()) && isdigit(str[i + 1]))
            throw std::invalid_argument("Numbers and operators must be separated by a space");
        else if (isOperator(str[i]) && (i + 1 < str.length()) && isOperator(str[i + 1]))
            throw std::invalid_argument("Multiple operators must be separated by a space");
        else if (isdigit(str[i]) && (i + 1 < str.length()) && isdigit(str[i + 1]))
            throw std::invalid_argument("Numbers must be positive integers between 0 and 9");
        else if (isdigit(str[i]) && (i + 1 < str.length()) && isOperator(str[i + 1]))
            throw std::invalid_argument("Numbers and operators must be separated by a space");
    }
    if (nm - op != 1)
        throw std::invalid_argument("Invalid number of operators");
}

double RPN::calculate(double a, double b, char c)
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
    {
        if (b == 0)
            throw std::invalid_argument("Division by zero");
        return a / b;
    }
    return 0;
}

void RPN::print(std::string str)
{
    double a;
    double b;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            continue;
        else if (isdigit(str[i]))
            num.push(str[i] - '0');
        else if (isOperator(str[i]))
        {
            if (num.size() < 2)
                throw std::invalid_argument("Invalid number of operands");
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            num.push(calculate(b, a, str[i]));
        }
    }
    if (num.size() != 1)
        throw std::invalid_argument("Invalid number of operands");
    std::cout << num.top() << std::endl;
}

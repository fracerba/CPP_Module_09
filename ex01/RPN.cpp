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

void RPN::parse(std::string str)
{
    int nm;
    int op;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            num.push(str[i] - '0');
            nm++;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            op++;
        else
            throw std::invalid_argument("Invalid character in string");
    }
    if (nm - op != 1)
        throw std::invalid_argument("Invalid number of operators");
}

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <fstream>
#include <stack>

class RPN
{
    private:
        static std::stack<double> num;

        RPN();
        RPN(const RPN &New);
        ~RPN();
        RPN &operator=(const RPN &New);

    public:
        static bool isOperator(char c);
        static void parse(std::string str);
        static double calculate(double a, double b, char c);
        static void print(std::string str);
};

#endif
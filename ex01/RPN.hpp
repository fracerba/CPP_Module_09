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
        static std::stack<float> num;

        RPN();
        RPN(const RPN &New);
        ~RPN();
        RPN &operator=(const RPN &New);

    public:
        static void parse(std::string str);
        static void print();
};

#endif
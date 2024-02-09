#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <fstream>
#include <queue>

class RPN
{
    private:
        static std::queue<int> num;
        static std::queue<char> ops;

        RPN();
        RPN(const RPN &New);
        ~RPN();
        RPN &operator=(const RPN &New);

    public:
        static void parse(std::string str);
        static void print();
};

#endif
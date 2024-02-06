#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <fstream>

class RPN
{
    private:
        //container

    public:
        RPN();
        RPN(const RPN &New);
        ~RPN();
        RPN &operator=(const RPN &New);
};

#endif
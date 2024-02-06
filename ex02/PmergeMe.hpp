#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <fstream>

class PmergeMe
{
    private:
        //container

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &New);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &New);
};

#endif
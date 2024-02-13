#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <fstream>
#include <deque>
#include <vector>
#include <ctime>

class PmergeMe
{
    private:
        static std::vector<unsigned int> v;
        static std::deque<unsigned int> d;

        PmergeMe();
        PmergeMe(const PmergeMe &New);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &New);

    public:
        static void FillVector(char **nmb);
        static void PrintVector();
        static void InsertionSortVector(std::vector<unsigned int>::iterator b, std::vector<unsigned int>::iterator e);
        static void MergeInsertionSortVector();
        
        static void FillDeque(char **nmb);
        static void PrintDeque();
        static void InsertionSortDeque();
        static void MergeInsertionSortDeque();
};

#endif
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <fstream>
#include <deque>
#include <vector>
#include <ctime>
#include <iomanip>

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
        static void MergeInsertionSortVector(std::vector<unsigned int> vec, std::vector<unsigned int>::iterator b, std::vector<unsigned int>::iterator e);
        static void SortVector();
        
        static void FillDeque(char **nmb);
        static void PrintDeque();
        static void MergeInsertionSortDeque(std::deque<unsigned int> deq, std::deque<unsigned int>::iterator b, std::deque<unsigned int>::iterator e);
        static void SortDeque();
};

#endif
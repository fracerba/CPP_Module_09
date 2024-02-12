#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <fstream>
#include <deque>
#include <queue>
#include <ctime>

class PmergeMe
{
    private:
        static std::queue<unsigned int> q;
        static std::deque<unsigned int> d;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &New);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &New);

        void PrintQueue();
        void SortQueue();
        void MergeSortQueue();
        
        void PrintDeque();
        void SortDeque();
        void MergeSortDeque();
};

#endif
#include "PmergeMe.hpp"

std::queue<unsigned int> PmergeMe::q;
std::deque<unsigned int> PmergeMe::d;

PmergeMe::PmergeMe()
{
    q = std::queue<unsigned int>();
    d = std::deque<unsigned int>();
}

PmergeMe::PmergeMe(const PmergeMe &New)
{
    q = New.q;
    d = New.d;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &New)
{
    q = New.q;
    d = New.d;
    return *this;
}
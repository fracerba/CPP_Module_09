#include "PmergeMe.hpp"

std::vector<unsigned int> PmergeMe::v;
std::deque<unsigned int> PmergeMe::d;

PmergeMe::PmergeMe()
{
    v = std::vector<unsigned int>();
    d = std::deque<unsigned int>();
}

PmergeMe::PmergeMe(const PmergeMe &New)
{
    v = New.v;
    d = New.d;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &New)
{
    v = New.v;
    d = New.d;
    return *this;
}

void PmergeMe::FillVector(char **nmb)
{
    for (size_t i = 0; nmb[i]; i++)
        v.push_back(atoi(nmb[i]));
}

void PmergeMe::PrintVector()
{
    std::vector<unsigned int>::iterator it = v.begin();
    for (; it != v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::MergeInsertionSortVector(std::vector<unsigned int> vec, std::vector<unsigned int>::iterator b, std::vector<unsigned int>::iterator e)
{
    if (std::distance(b, e) <= 2)
        std::sort(b, e);
    else
    {
        std::vector<unsigned int>::iterator m = b + std::distance(b, e) / 2;
        MergeInsertionSortVector(vec, b, m);
        MergeInsertionSortVector(vec, m, e);
        std::vector<unsigned int> a(std::distance(b, e));
        std::merge(b, m, m, e, a.begin());
        std::copy(a.begin(), a.end(), b);
    }
}

void PmergeMe::SortVector()
{
   MergeInsertionSortVector(v, v.begin(), v.end());
}

void PmergeMe::FillDeque(char **nmb)
{
    for (size_t i = 0; nmb[i]; i++)
        d.push_back(atoi(nmb[i]));
}

void PmergeMe::PrintDeque()
{
    std::deque<unsigned int>::iterator it = d.begin();
    for (; it != d.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::MergeInsertionSortDeque(std::deque<unsigned int> deq, std::deque<unsigned int>::iterator b, std::deque<unsigned int>::iterator e)
{
    if (std::distance(b, e) <= 2)
        std::sort(b, e);
    else
    {
        std::deque<unsigned int>::iterator m = b + std::distance(b, e) / 2;   
        MergeInsertionSortDeque(deq, b, m);
        MergeInsertionSortDeque(deq, m, e);
        std::deque<unsigned int> a(std::distance(b, e));
        std::merge(b, m, m, e, a.begin());
        std::copy(a.begin(), a.end(), b);
    }
}

void PmergeMe::SortDeque()
{
   MergeInsertionSortDeque(d, d.begin(), d.end());
}
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
    {
        v.push_back(atoi(nmb[i]));
    }
}

void PmergeMe::PrintVector()
{
    std::vector<unsigned int>::iterator it = v.begin();
    for (; it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::SortVector()
{

}

void PmergeMe::MergeSortVector()
{

}

void PmergeMe::FillDeque(char **nmb)
{
    for (size_t i = 0; nmb[i]; i++)
    {
        d.push_back(atoi(nmb[i]));
    }
}

void PmergeMe::PrintDeque()
{
    std::deque<unsigned int>::iterator it = d.begin();
    for (; it != d.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::SortDeque()
{

}

void PmergeMe::MergeSortDeque()
{

}
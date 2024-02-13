#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
    if (argc < 3)
    {
        std::cout << "Error! Not enough arguments." << std::endl;
        return 0;
    }
    for (size_t i = 0; i < argc; i++)
    {
        for (size_t j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                std::cout << "Error! Only positive integers accepted." << std::endl;
                return 0;
            }
        }
    }
    PmergeMe::FillVector(&argv[1]);
    PmergeMe::FillDeque(&argv[1]);
    std::cout << "Before: " << std::endl;
    PmergeMe::PrintVector();
    int startq = clock();
    PmergeMe::SortVector();
    int stopq = clock();
    int startd = clock();
    PmergeMe::SortDeque();
    int stopd = clock();
    std::cout << "After: " << std::endl;
    PmergeMe::PrintVector();
    std::cout << "Time to process a range of "<< argc - 1 << " elements with std::vector<unsigned int> : ";
    std::cout << (stopq - startq) / double(CLOCKS_PER_SEC) * 1000  << "ms" << std::endl;
    std::cout << "Time to process a range of "<< argc - 1 << " elements with std::deque<unsigned int> : ";
    std::cout << (stopd - startd) / double(CLOCKS_PER_SEC) * 1000  << "ms" << std::endl;
    return 0;
}
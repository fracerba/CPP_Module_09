#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
    if (argc < 3)
    {
        std::cout << "Error! Not enough arguments." << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                std::cout << "Error! Only positive integers accepted." << std::endl;
                return 0;
            }
        }
    }
    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;
    unsigned int startv = clock();
    PmergeMe::FillVector(&argv[1]);
    PmergeMe::SortVector();
    unsigned int stopv = clock();
    unsigned int startd = clock();
    PmergeMe::FillDeque(&argv[1]);
    PmergeMe::SortDeque();
    unsigned int stopd = clock();
    std::cout << "After: ";
    PmergeMe::PrintVector();
    std::cout << "Time to process a range of "<< argc - 1 << " elements with std::vector<unsigned int> : ";
    std::cout << std::setprecision(6) << (stopv - startv) / double(CLOCKS_PER_SEC) * 1000  << "ms" << std::endl;
    std::cout << "Time to process a range of "<< argc - 1 << " elements with std::deque<unsigned int> : ";
    std::cout << std::setprecision(6) << (stopd - startd) / double(CLOCKS_PER_SEC) * 1000  << "ms" << std::endl;
    return 0;
}

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
    std::cout << "Before: " << std::endl;
    int startq = clock();

    int stopq = clock();
    std::cout << "After: " << std::endl;
    int startd = clock();

    int stopd = clock();
    return 0;
}
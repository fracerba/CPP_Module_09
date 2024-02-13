#include "RPN.hpp"

int main(int argc, char **argv) 
{
    try
    {
        if (argc == 2)
        {
            RPN::parse(argv[1]);
            RPN::print(argv[1]);
        }
        else
            throw std::invalid_argument("Error! Wrong number of arguments.");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
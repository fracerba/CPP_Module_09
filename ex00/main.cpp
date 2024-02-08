#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
    try
    {
        if (argc == 2)
        {
            BitcoinExchange::createData("data.csv");
            BitcoinExchange::checkInput(argv[1]);
        }
        else
            throw std::invalid_argument("Error! No input file given.");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
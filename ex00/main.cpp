#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
    BitcoinExchange ex;

    if (argc == 2)
    {
        ex.createData("Data.csv");
        ex.printExchange(argv[1]);
    }
    else
        std::cout << "Error! No file given." << std::endl;
    return 0;
}
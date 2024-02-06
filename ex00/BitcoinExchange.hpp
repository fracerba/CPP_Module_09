#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <fstream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &New);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &New);

        void createData(std::string name);
        bool checkImput(std::string name);
        void addExchange(std::string name, float rate);
        void printExchange(std::string name);

};

#endif
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        static std::map<std::string, float> data;

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &New);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &New);

    public:
        static void createData(std::string name);
        static void addExchange(std::string name, float rate);
        static void printExchange(std::string date, std::string value);
        static void checkInput(std::string name);
};

#endif
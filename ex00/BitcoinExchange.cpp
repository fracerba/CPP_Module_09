#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    data = std::map<std::string, float>();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &New)
{
    data = New.data;
}

BitcoinExchange::~BitcoinExchange()
{
    data.clear();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &New)
{
    data = New.data;
    return *this;
}

void BitcoinExchange::createData(std::string name)
{
    std::fstream file;
    std::string line;
    std::string key;
    std::string value;

    file.open(name, std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            key = line.substr(0, line.find(','));
            value = line.substr(line.find(',') + 1);
            data[key] = std::atof(value.c_str());
        }
        file.close();
    }
    else
    {
        throw std::invalid_argument("File not found");
    }
}
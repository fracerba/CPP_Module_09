#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::data;

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
    std::ifstream file(name.c_str());
    std::string line;
    std::string key;
    std::string value;

    if (file.is_open() && file.good())
    {
        getline(file, line);
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
        throw std::invalid_argument("Error! data.csv not found.");
    }
}

void BitcoinExchange::addExchange(std::string name, float rate)
{
    std::map<std::string, float>::iterator it;
    for (it = data.begin(); it != data.end(); it++)
    {
        if (it->first.compare(name) > 0)
        {
            it--;
            std::cout << it->second * rate << std::endl;
            return ;
        }
    }
    it--;
    std::cout << it->second * rate << std::endl;
}

void BitcoinExchange::printExchange(std::string date, std::string val)
{
    if ((date == "Date" || date == "date") && (val == "Value" || val == "value"))
        return ;
    else if (date.empty() || val.empty())
        std::cout << "Error: bad input => " << date << std::endl;
    else if (std::count(date.begin(), date.end(), '-') != 2)
        std::cout << "Error: bad input => " << date << std::endl;

    int i = date.find('-');
    int y = date.find('-', i + 1);
    std::string year = date.substr(0, i);
    std::string month = date.substr(i + 1, y - i - 1);
    std::string day = date.substr(y + 1);
    float value = std::atof(val.c_str());
    int ny = std::atoi(year.c_str());
    int nm = std::atoi(month.c_str());
    int nd = std::atoi(day.c_str());

    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
        std::cout << "Error: invalid date." << std::endl;
    else if (ny < 2009 || ny > 2024)
        std::cout << "Error: invalid year." << std::endl;
    else if (nm > 12 || nm < 1)
        std::cout << "Error: invalid month." << std::endl;
    else if (nd > 31 || nd < 1)
        std::cout << "Error: invalid day." << std::endl;
    else if (nm == 2 && nd > 29)
        std::cout << "Error: invalid day." << std::endl;
    else if (nm == 4 && nd > 30)
        std::cout << "Error: invalid day." << std::endl;
    else if (nm == 6 && nd > 30)
        std::cout << "Error: invalid day." << std::endl;
    else if (nm == 9 && nd > 30)
        std::cout << "Error: invalid day." << std::endl;
    else if (nm == 11 && nd > 30)
        std::cout << "Error: invalid day." << std::endl;
    else if (value < 0)
        std::cout << "Error: not a positive number" << std::endl;
    else if (value > 1000)
        std::cout << "Error: too large a number" << std::endl;
    else
    {
        std::cout << date << " => " << value << " = ";
        addExchange(date, value);
    }
}

void BitcoinExchange::checkInput(std::string name)
{
    std::ifstream file(name.c_str());
    std::string line;
    std::string date;
    std::string value;

    if (file.is_open() && file.good())
    {
        getline(file, line);
        if (line.empty())
        {
            file.close();
            throw std::invalid_argument("Error! Input file is empty.");
        }
        do {
            if (std::count(line.begin(), line.end(), '|') != 1)
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue ;
            }
            date = line.substr(0, line.find('|') - 1);
            value = line.substr(line.find('|') + 2);
            printExchange(date, value);
        } while (getline(file, line));
        file.close();
    }
    else
        throw std::invalid_argument("Error! Input file not found.");
}

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

void BitcoinExchange::printResult(float rate)
{
    int c = 0;

    for (float i = 10; (rate / i) > 0.1;)
    {
        i = i * 10;
        c++;
    }
    std::cout << std::setprecision(c + 6);
    std::cout << rate << std::endl;
}

void BitcoinExchange::addExchange(std::string name, float rate)
{
    std::map<std::string, float>::iterator it;
    it = data.begin();
    if (it->first.compare(name) > 0)
    {
        std::cout << "Error: invalid date." << std::endl;
        return ;
    }
    std::cout << std::setprecision(6);
    std::cout << name << " => " << rate << " = ";
    for (; it != data.end(); it++)
    {
        if (it->first.compare(name) > 0)
        {
            it--;
            printResult(it->second * rate);
            return ;
        }
    }
    it--;
    printResult(it->second * rate);
}

void BitcoinExchange::printExchange(std::string date, std::string val)
{
    bool b = false;
    bool c = false;

    if ((date == "Date" || date == "date") && (val == "Value" || val == "value"))
        return ;

    if (std::count(date.begin(), date.end(), '-') != 2)
        b = true;
    for (size_t a = 0; a < date.length(); a++)
    {
        if (date[a] == '-' && date[a + 1] == '-')
            b = true;
        else if (!isdigit(date[a]) && date[a] != '-')
            b = true;
        else if (date[a] == '-' && (a == 0 || a == date.length() - 1))
            b = true;
        if (b)
            break ;
    }
    if (b)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return ;
    }

    if (std::count(val.begin(), val.end(), '.') > 1)
        c = true;
    for (size_t a = 0; a < val.length(); a++)
    {
        if (!isdigit(val[a]) && val[a] != '.' && val[a] != '-' && val[a] != '+')
            c = true;
        else if (val[a] == '.' && (a == 0 || a == val.length() - 1))
            c = true;
        else if ((val[a] == '-' || val[a] == '+') && a != 0)
            c = true;
        if (c)
            break ;
    }
    if (c)
    {
        std::cout << "Error: bad input => " << val << std::endl;
        return ;
    }

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
    else if ((nm == 4 || nm == 6 || nm == 9 || nm == 11) && nd > 30)
        std::cout << "Error: invalid day." << std::endl;
    else if (ny % 4 != 0 && nm == 2 && nd > 28)
        std::cout << "Error: invalid day." << std::endl;
    else if (nm == 2 && nd > 29)
        std::cout << "Error: invalid day." << std::endl;
    else if (value < 0)
        std::cout << "Error: not a positive number" << std::endl;
    else if (value > 1000)
        std::cout << "Error: too large a number" << std::endl;
    else
        addExchange(date, value);
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
            if (date.empty() || value.empty())
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue ;
            }
            printExchange(date, value);
        } while (getline(file, line));
        file.close();
    }
    else
        throw std::invalid_argument("Error! Input file not found.");
}

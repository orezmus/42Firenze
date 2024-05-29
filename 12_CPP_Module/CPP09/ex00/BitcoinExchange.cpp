#include "BitcoinExchange.hpp"

BitcoinDatabase::BitcoinDatabase() {
}

BitcoinDatabase::BitcoinDatabase(const BitcoinDatabase &copy) : prices_(copy.prices_) {
}

BitcoinDatabase& BitcoinDatabase::operator=(const BitcoinDatabase &copy) {
    if (this != &copy)
        prices_ = copy.prices_;
    return (*this);
}

BitcoinDatabase::~BitcoinDatabase() {
}


bool BitcoinDatabase::readCSV(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open cvs file. " << filename << std::endl;
        return false;
    }
    
    std::string line;
    if (line != "date,exchange_rate")
    {
        std::cerr << "Error: incorrect file format." << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, ',') && std::getline(iss, valueStr))
        {
            double value;
            std::istringstream(valueStr) >> value;
            prices_[date] = value;
        }
    }
    file.close();
    return true;
}

double BitcoinDatabase::getBitcoinPrice(const std::string &data) {
    std::map<std::string, double>::const_iterator it = prices_.find(date);
    if (it != prices_.end())
        return it->second;
    return -1;
}

void BitcoinDatabase::readInput(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << filename << std::endl;
        return ;
    }

    std::string line;
	if (std::getline(file, line))
	{
		if (line != "date | value")
		{
			std::cerr << "Error: incorrect file format." << std::endl;
			return ;
		}
	}

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
        {
            if(!isValideDate(date))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (!isValideValue(valueStr))
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
    }
}
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : prices_(copy.prices_) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy)
		prices_ = copy.prices_;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
}

bool BitcoinExchange::isValideDate(const std::string &date)
{
	std::istringstream dateStream(date);
	int year, month, day;
	char dash1, dash2;

	if (!(dateStream >> year >> dash1 >> month >> dash2 >> day))
		return false;
	if (dash1 != '-' || dash2 != '-' || month < 1 || month > 12 || day < 1)
		return false;

	if (month == 2)
	{
		bool isLeap = (year % 4 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	else
	{
		if (day > 31)
			return false;
	}
	return true;
}

bool BitcoinExchange::isValideValue(const std::string &valueStr)
{
	std::istringstream	valueStream(valueStr);
	float value;

	if (!(valueStream >> value))
		return false;
	if (value < 0)
		return false;
	return true;
}

bool BitcoinExchange::readCSV(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open cvs file. " << filename << std::endl;
		return false;
	}
	
	std::string line;
	if (std::getline(file, line))
	{
		if (line != "date,exchange_rate")
		{	
			std::cerr << "Error: incorrect file format." << std::endl;
			return false;
		}
	}
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::istringstream iss(line);
		std::string date, valueStr;
		if (std::getline(iss, date, ',') && std::getline(iss, valueStr))
		{
			if (isValideDate(date) && isValideValue(valueStr))
			{
				float value;
				std::istringstream valueStream(valueStr);
				valueStream >> value;
				if (!valueStream.fail())
					prices_[date] = value;
			}
		}
	}
	file.close();
	return true;
}

float BitcoinExchange::getBitcoinPrice(const std::string &date) {
	std::map<std::string, float>::iterator it = prices_.lower_bound(date);
	
	if (it != prices_.end() && it->first == date)
		return it->second;
	if (it != prices_.begin())
	{
		--it;
		return it->second;
	}
	return -1;
}

void BitcoinExchange::readInput(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << filename << std::endl;
		return ;
	}

	std::string line;
	if (std::getline(file, line))
	{
		std::cout << line << std::endl;
		if (line != "date | value")
		{
			std::cerr << "Error: incorrect file format." << std::endl;
			return ;
		}
	}

	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::istringstream iss(line);
		std::string date, valueStr, sep;
		if (!(iss >> date >> sep >> valueStr) || sep != "|")
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
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

		float value;
		std::istringstream valueStream(valueStr);
		valueStream >> value;
		if (valueStream.fail() || value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float findPrice = getBitcoinPrice(date);
		if (findPrice == -1)
		{
			std::cerr << "Error: date not found in database." << std::endl;
			continue;
		}

		float result = value * findPrice;
		std::cout << date << " => " << value << " = "
				<<std::fixed << std::setprecision(2) << result << std::endl;
	}

	file.close();
}
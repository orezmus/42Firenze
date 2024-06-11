#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

class BitcoinExchange {
private:
	std::map<std::string, float> prices_;
	
	bool isValideDate(const std::string &date);
	bool isValideValue(const std::string &valueSTr);
	
	float getBitcoinPrice(const std::string &data);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	bool readCSV(const std::string &filename);
	
	void readInput(const std::string &filename);
};

#endif

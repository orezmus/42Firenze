#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinDatabase {
private:
	std::map<std::string, double> prices_;
public:
	BitcoinDatabase();
	BitcoinDatabase(const BitcoinDatabase &copy);
	BitcoinDatabase& operator=(const BitcoinDatabase &copy);
	~BitcoinDatabase();

	bool readCSV(const std::string &filename);
	double getBitcoinPrice(const std::string &data);
	
	void readInput(const std::string &filename);
};

#endif
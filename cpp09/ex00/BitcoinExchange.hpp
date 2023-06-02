#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>  
#include <sstream>
#include <limits.h>
class BitcoinExchange {
	private:
   		std::map<std::string, float>	_data;
		size_t  						_size;
		void 							parse_data(std::ifstream& in);
		void							find(std::string& line, float value);
	public:
		BitcoinExchange();
    	BitcoinExchange(const std::map<std::string, float>& database);
    	BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		~BitcoinExchange();
		size_t  size() const;
		void	find_values(std::ifstream& in);
};

#endif

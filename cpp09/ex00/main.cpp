#include "BitcoinExchange.hpp"

void	fill_data(std::map<std::string, float>& data, std::ifstream& indata)
{
	std::string line;
	std::string temp;
	float val;
	size_t i;
	std::pair<std::string, float> pair;
	// std::map<std::string, float>::iterator it;
	std::getline(indata, line);
	while (std::getline(indata, line))
	{
			if ((i = line.find(",")) != std::string::npos)
			{ 
				std::istringstream p(line.substr(i + 1));
				p >> val;
				data.insert(std::pair<std::string, float>(line.substr(0, i), val));
			}
	}
	// for (it = data.begin(); it != data.end(); ++it)
	// 	std::cout << "date = " << it->first << " | value = " << it->second << std::endl;
} 

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : Invalid arguments" << std::endl;
		return (1);
	}
	std::ifstream	in(av[1]);
	std::ifstream	indata("data.csv");
	//std::ifstream	data();
	if (!in.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::map<std::string, float> database;
	fill_data(database, indata);
	BitcoinExchange Data(database);
	try
	{
		Data.find_values(in);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
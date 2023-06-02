#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _size(0)
{
	//std::cout << "Default Constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::map<std::string, float>& data) : _data(data), _size(data.size())
{
	//std::cout << "Constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) 
{
	//std::cout << "Copy Constructor called" << std::endl;
	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	//std::cout << "Copy assignement constructor called" << std::endl;
	if (this != &obj)
	{
		this->_size = obj.size();
		if (obj.size() > 0)
			this->_data = obj._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "Destructor called" << std::endl;
}

size_t	BitcoinExchange::size() const {return this->_size;}

void	check_date(std::string& date)
{
	int _day = 31;
	std::istringstream s(date);
	int year, month, day;
	if (!(s >> year >> month >> day))
		throw std::runtime_error("Error: bad input => " + date);
	month *= -1;
	if (month > 12 || month < 0)
		throw std::runtime_error("Error: bad input => " + date);
	day *= -1;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		_day = 30;
	else if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 ==0))
			_day = 29;
		else 
			_day = 28;	
	}	
	else
		_day = 31;
	if (day > _day || day <= 0)
		throw std::runtime_error("Error: bad input => " + date);	
}


void	check_val(std::string& line, std::string& value)
{
	std::string to_find("0123456789.-+");
	if (std::count(value.begin(), value.end(), '.') > 1)
		throw std::runtime_error("Error: bad input => " + line);
	for (size_t i = 0; i < value.length(); i++)
	{
		if (to_find.find(value.at(i)) == std::string::npos)
			throw std::runtime_error("Error: bad input => " + line);
		if (i == value.size() - 1 && value.at(i) == '.')
			throw std::runtime_error("Error: bad input => " + line);	
		if (i != 0 && (value.at(i) == '+' || value.at(i) == '-'))
			throw std::runtime_error("Error: bad input => " + line);		
	}
}

float	thrower(std::string& line)
{
	if (line == "")
		throw std::runtime_error("");
	std::string date, sep, value;
	float val;
	std::istringstream p(line);

	if (!(p >> date >> sep >> value))
		throw std::runtime_error("Error: bad input => " + line);
	if (sep != "|")
		throw std::runtime_error("Error: bad input => " + line);
	if (date.length() != 10)
		throw std::runtime_error("Error: bad input => " + line);
	check_val(line, value);
	std::istringstream s(value);
	if(!(s >> val))
		throw std::runtime_error("Error: bad input => " + line);
	if (val > 1000)
		throw std::runtime_error("Error: too large a number.");
	if (val < 0)
		throw std::runtime_error("Error: not a positive number.");
	check_date(date);
	return (val);	
	//std::cout << year << "-" << month << "-" << day << " " << sep << " " << val << std::endl;	
}

void	BitcoinExchange::find(std::string& line, float value)
{
	std::map<std::string, float>::iterator it = this->_data.lower_bound(line);
	if (it != this->_data.begin())
		it--;
	if (it != this->_data.end())
		std::cout << it->first << " => " << value << " = " << it->second * value << std::endl;
}

void	BitcoinExchange::parse_data(std::ifstream& in)
{
	std::string line;
	size_t i = 0;
	float value = 0;
	while (std::getline(in, line))
	{
			if (i == 0 && line != "date | value")
				throw std::runtime_error("Invalid header");	
			try
			{
				if (i != 0)
				{
					value = thrower(line);
					this->find(line, value);
				}

				//std::cout << line << std::endl;
			}	
			catch (std::exception& e)
			{
				if ((e.what())[0])
					std::cerr << e.what() << std::endl;
			}
			i++;
	}
}

void	BitcoinExchange::find_values(std::ifstream& in)
{
	this->parse_data(in);
}

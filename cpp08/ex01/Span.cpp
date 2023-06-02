#include "Span.hpp"

Span::Span() : _N(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Span::Span(const size_t& N) : _N(N)
{
	std::cout << "Constructor called" << std::endl;
}

Span::Span(const Span& obj) : _N(0)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = obj;
}

Span& Span::operator=(const Span& obj)
{
	std::cout << "Copy assignement constructor called" << std::endl;
	if (this != &obj)
	{
		if (this->_N != 0)
			this->_arr.clear();
		this->_N = obj._N;
		if (obj._N != 0)
			this->_arr = obj._arr;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}


void	Span::addNumber(int N)
{
	if (this->_arr.size() == this->_N)
		throw Span::NoMoreSpace();
	this->_arr.push_back(N);	
}

size_t		Span::shortestSpan() const
{
	if (this->_N <= 1 || this->_arr.size() <= 1 )
		throw NoMoreSpace();

	std::vector<int> tarr = this->_arr;
	std::vector<int>::iterator it1, it2;
	size_t i = 0;

	std::sort(tarr.begin(), tarr.end());
	i = (size_t)std::abs(*(tarr.begin() + 1) - *(tarr.begin()));
	for (it1 = tarr.begin(); it1 < tarr.end(); it1++)
	{
		it2 = (it1 + 1);
		if (i > (size_t)std::abs(*it2 - *it1))
			i = (size_t)std::abs(*it2 - *it1);
	}
	return (i);
}

size_t		Span::longestSpan() const
{
	if (this->_N <= 1 || this->_arr.size() <= 1)
		throw NoMoreSpace();
	return std::abs(*(std::max_element(this->_arr.cbegin(), this->_arr.cend())) 
	- *(std::min_element(this->_arr.cbegin(), this->_arr.cend())));
}

const char* Span::NoMoreSpace::what() const throw() {
	return "No more space left";
}
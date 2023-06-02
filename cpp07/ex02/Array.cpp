#include "Array.hpp"

Array::Array(void) : _size(0), _arr(NULL)
{
	std::cout << "Default Constructor called" << std::endl;
}

template <typename T>
Array::Array<T>(size_t size) 
{
	std::cout << "Constructor called" << std::endl;
	this->_size = size;
	this->_arr = NULL;
	if (size != 0)
		this->_arr = new T[size];
}

template <typename T>
Array::Array<T>(const Array<T>& obj)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = obj;
}

template <typename T>
Array::Array<T>&	operator=(const Array& obj)
{
	std::cout << "Copy assignement operator Constructor called" << std::endl;
	if (this != obj)
	{
		this->_size = obj.size();
		if (this->_size != 0)
			delete [] this->_arr;
		this->_arr = NULL;	
		if (obj.size() != 0)
		{
			this->_arr = new T[obj.size()];
			for (size_t i = 0; i < obj.size(); i++)
				this->_arr[i] = obj._arr[i];
		}
	}
	return (*this);
}

T&			Array::operator[](int index) const
{
	if (index < 0 || index > this->_size)
		throw Array::OutOfBoundException();
	return (this->_arr[index]);	
}

Array::~Array()
{
	std::cout << "destructor called" << std::endl;
	if (this->_size != 0)
		delete [] this->_arr;
}

size_t Array::size(void) const {return this->_size;}

const char* Array::OutOfBoundException::what() const throw()
{
	return "Out of bound";
}

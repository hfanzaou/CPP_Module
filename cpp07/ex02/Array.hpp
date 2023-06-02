#pragma once
#include <iostream>

template <typename T>
class Array {
	private :
		T		*_arr;
		size_t	_size;
	public :
		Array<T>() : _arr(NULL), _size(0)
		{
			std::cout << "Default Constructor called" << std::endl;
		}
		Array<T>(size_t size)
		{
			std::cout << "Constructor called" << std::endl;
			this->_size = size;
			this->_arr = NULL;
			if (size != 0)
				this->_arr = new T[size];
		}

		Array<T>(const Array<T>& obj) : _arr(NULL), _size(0)
		{
			std::cout << "Copy Constructor called" << std::endl;
			*this = obj;
		}

		Array<T>&	operator=(const Array& obj)
		{
			std::cout << "Copy assignement operator Constructor called" << std::endl;
			if (this != &obj)
			{
				if (this->_size > 0)
					delete [] this->_arr;
				this->_size = obj.size();
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
		const T&			operator[](size_t index) const
		{
			if (index < 0 || index > this->_size)
				throw Array::OutOfBoundException();
			return (this->_arr[index]);
		}
		T&			operator[](size_t index)
		{
			if (index < 0 || index > this->_size)
				throw Array::OutOfBoundException();
			return (this->_arr[index]);
		}
		~Array()
		{
			std::cout << "destructor called" << std::endl;
			if (this->_size != 0)
				delete [] this->_arr;
		}
		class OutOfBoundException : public std::exception {
			public :
				const char *what() const throw()
				{
					return "Out of bound";
				}
		};
		size_t size(void) const
		{
			return this->_size;
		}
};

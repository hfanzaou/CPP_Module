#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
#include <deque>
#include <list>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() : std::stack<T, Container>()
		{
			std::cout << "Constructor called" << std::endl;
		}
    	MutantStack(const MutantStack& obj) : std::stack<T, Container>()
		{
			std::cout << "Copy constructor called" << std::endl;
			*this = obj;
		}

		MutantStack& operator=(const MutantStack& obj)
		{
			std::cout << "Copy assignement constructor called" << std::endl;
			if (this != &obj)
				this->c = obj.c;
			return (*this);
		}

		~MutantStack()
		{
			std::cout << "Destructor called" << std::endl;
		}

		typedef	typename Container::iterator iterator;
		typedef	typename Container::const_iterator const_iterator;

		iterator begin() {return (this->c.begin());}
		iterator end() {return (this->c.end());}
		const_iterator cbegin() const {return (this->c.cbegin());}
		const_iterator cend() const {return (this->c.cend());}
};

#endif

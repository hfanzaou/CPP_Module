#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <vector>


class NotFound : public std::exception {
	public :
		const char *what() const throw()
		{
			return "Not Found";
		}
};

template<typename T>
void	 easyfind(T& con, int to_find)
{
	if (std::find(con.begin(), con.end(), to_find) == con.end())
		throw NotFound();
	else
		std::cout << "Value found" << std::endl;
}

#endif
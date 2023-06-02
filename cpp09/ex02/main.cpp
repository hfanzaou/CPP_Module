#include "PmergeMe.hpp"
#include <string>

int if_digit(char *s)
{
	for (int i = 0; s[i]; i++)
	{
		if (!std::isdigit(s[i])  && !(i == 0 && s[i] == '+' && s[i + 1]))
			return (1);
	}
	return (0);
}

std::vector<int> put_vec(char**& av)
{
	// std::string nums(av[1]);
	int i = 1;
	std::vector<int> ret;
	// for (size_t i = 0; i < nums.length(); i++)
	// 	std::cout << nums.at(i) << std::endl;
	int t;
	while (av[i])
	{
		if (if_digit(av[i]) || !av[i][0])
			throw std::runtime_error("Error");
		std::istringstream p((std::string(av[i])));
		p >> t;
		ret.push_back(t);
		i++;
	}
	if (ret.size() == 1)
		throw std::runtime_error("");	
	return (ret);
}	

std::deque<int> put_deque(char**& av)
{
		// std::string nums(av[1]);
	int i = 1;
	std::deque<int> ret;
	// for (size_t i = 0; i < nums.length(); i++)
	// 	std::cout << nums.at(i) << std::endl;
	int t;
	while (av[i])
	{
		if (if_digit(av[i]) || !av[i][0])
			throw std::runtime_error("Error");
		std::istringstream p((std::string(av[i])));
		p >> t;
		ret.push_back(t);
		i++;
	}	
	return (ret);
}

int main(int ac, char **av)
{
	(void)ac;
	if (ac < 2)
		return (0);
	try {
		PmergeMe vec(put_vec((av)));
		PmergeMe deque(put_deque((av)));
		std::cout << "before : "; 
		vec.print_vec();
		vec.vec_sort();
		deque.deque_sort();
		std::cout << "after : "; 
		vec.print_vec();
		std::cout << "Time to process a range of " << vec.get_size() << " elements with std::vector<int> : ";
		std::cout << vec.get_time() << " us" << std::endl;
		std::cout << "Time to process a range of " << deque.get_size() << " elements with std::deque<int> : ";
		std::cout << deque.get_time() << " us" << std::endl;
	}
	catch (std::exception& e)
	{
		if ((e.what())[0])
			std::cerr << e.what() << std::endl;
	}
}
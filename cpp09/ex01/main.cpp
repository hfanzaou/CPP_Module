#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ac > 2)
	{
		std::cerr << "Error" << std::endl;
	}	
	std::string exp(av[1]);
	try 
	{
		calculate(exp);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}	
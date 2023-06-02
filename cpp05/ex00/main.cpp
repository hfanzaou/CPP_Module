#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b("gg", 1);
		b.increment();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("hello", 150);
		std::cout << a << std::endl;
		a.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
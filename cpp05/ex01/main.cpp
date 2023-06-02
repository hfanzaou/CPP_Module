#include "Bureaucrat.hpp"

int main()
{
	try {
		Form paper("tosign", 1, 1);
		std::cout << paper << std::endl;
		Bureaucrat b("signer", 1);
		b.signForm(paper);
		b.signForm(paper);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("hello", 150);
		a.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
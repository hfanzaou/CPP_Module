#include "Span.hpp"

int main()
{
	size_t size = 5;

	int j[5] = {12, 10, 95, 11, -9};
	Span a(size);
	try 
	{
		for (size_t i = 0; i < size; i++)
		{
			a.addNumber(j[i]);
		}
		a.addNumber(6);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "longestSpan = " << a.longestSpan() << std::endl;
		std::cout << "shortestSpan = " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
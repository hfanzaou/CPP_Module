#include "easyfind.hpp"



int main()
{
	std::vector<int> a;
	for(int i = 0; i < 10; i++)
		a.push_back(rand());
	a[4] = 42;
	try 
	{
		easyfind(a, 42);
		easyfind(a, 10);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;	
	}

}
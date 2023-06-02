#include <iostream>
#include <string.h>

int main(int ac, char **av)
{
	char a;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			a = toupper(av[i][j]);
			std::cout << a;
		}
	}
	std::cout << std::endl;
}
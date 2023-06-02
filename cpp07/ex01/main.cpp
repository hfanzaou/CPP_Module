#include "iter.hpp"

template<typename T>
void ft(T &to_print)
{
	std::cout << "Value : " << to_print << std::endl;
}

int main(void)
{
	std::string alpha = "abcdefghijklmnopqrstuvwxyz";
	std::string arr[10];
	int arr2[10];

	/////////
	std::cout << "arr with ascii digits" << std::endl;
	for (int i = 0; i < 10; i++)
		arr[i] = std::to_string(i);
	iter(arr, 10, ft);

	////////
	std::cout << "arr with int digits" << std::endl;
	for (int i = 0; i < 10; i++)
		arr2[i] = i;
	iter(arr2, 10,  ft);

	////////
	std::cout << "arr with strings" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = "";
		for(int j = 0; j < 5; j++)
			arr[i] += alpha.at(rand() % 26);	
	}
	iter(arr, 10,  ft);
}
#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	zombie = zombieHorde(5, "msmsm");
	if (!zombie)
		return (0);
	for (int i = 0; i < 5; i++){
		zombie[i].announce();
	}
	delete[] zombie;
	//system("leaks Zombie");
}
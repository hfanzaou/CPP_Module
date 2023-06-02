#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	zombie = newZombie("");
	if (!zombie)
		return (1);
	zombie->announce();
	randomChump("kilu");
	delete zombie;
}
#include "ScavTrap.hpp"

int main()
{
	ScavTrap pyke("pyke");
	ScavTrap hello("hello");
	ScavTrap sona("sona");

	pyke.attack("sona");
	sona.takeDamage(20);
	sona.beRepaired(1);
	// for(int i = 0; i < 15 ; i++)
	// {
	// 	sona.attack("pyke");
	// }

}
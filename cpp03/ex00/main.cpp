#include "ClapTrap.hpp"

int main()
{
	ClapTrap pyke("pyke");
	ClapTrap sona("sona");

	pyke.attack("sona");
	sona.takeDamage(0);
	for(int i = 0; i < 15 ; i++)
	{
		sona.attack("pyke");
	}

}
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
	FragTrap hello("");
	ClapTrap hi("hi");
	ScavTrap hei("hei");

	hello.highFivesGuys();
	hello.attack("someone");
	hello.takeDamage(20);
}
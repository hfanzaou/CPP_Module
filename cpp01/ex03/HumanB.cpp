#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}
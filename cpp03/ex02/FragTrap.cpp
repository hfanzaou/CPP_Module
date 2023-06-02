#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_Hit_Points = 100;
	_Energy_points = 100;
	_Attack_damage = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_Hit_Points = 100;
	_Energy_points = 100;
	_Attack_damage = 30;
	std::cout << _name << ": FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
		std::cout << _name << ": FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_Hit_Points = obj._Hit_Points;
		this->_Energy_points = obj._Energy_points;
		this->_Attack_damage = obj._Attack_damage;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " Highfive!!" << std::endl;
}
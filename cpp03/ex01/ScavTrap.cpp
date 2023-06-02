#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_Hit_Points = 100;
	_Energy_points = 50;
	_Attack_damage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_Hit_Points = 100;
	_Energy_points = 50;
	_Attack_damage = 20;
	std::cout << _name << ": ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
		std::cout << _name << ": ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
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

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_Energy_points && this->_Hit_Points)
	{
		_Energy_points--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_Attack_damage << " points of damage" << std::endl;
	}
}
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("NONE"), _Hit_Points(10), _Energy_points(10), _Attack_damage(0)
{
	std::cout << "Default ClapTrap constrcutor called" << std::endl; 
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _Hit_Points(10), _Energy_points(10), _Attack_damage(0)
{
	if (name == "")
		_name = "NONE";
	std::cout << _name <<": ClapTrap Constructor called" <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor called" <<std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
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

ClapTrap::~ClapTrap()
{
	std::cout<< _name << ": ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_Energy_points && this->_Hit_Points)
	{
		_Energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_Attack_damage << " points of damage" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hit_Points - amount < 0)
		this->_Hit_Points = 0;
	else	
		this->_Hit_Points -= amount;
	std::cout << "ClapTrap "<< this->_name << " takes " << amount << " points of damage" << std::endl;		
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Energy_points && this->_Hit_Points)
	{
		this->_Energy_points--;
		this->_Hit_Points += amount;
		std::cout << "ClapTrap " << this->_name << " repairs " << amount;
		std::cout << " Hit points" << std::endl;
	}
}
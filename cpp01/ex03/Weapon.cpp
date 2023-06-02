#include "Weapon.hpp"

std::string const &Weapon::getType( void )
{
	std::string const &ref = this->type;
	return (ref);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::Weapon(std::string type) : type(type)
{

}

Weapon::~Weapon()
{
	
}
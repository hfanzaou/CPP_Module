#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name) : name(name)
{
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::~Zombie( void )
{
	std::cout << this->name << std::endl;
}

const std::string Zombie::getName() const { return this->name; }

void	Zombie::setName(const std::string name) { this->name = name; }
#include "Zombie.hpp"

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

Zombie* newZombie(std::string name)
{
	if (name.empty())
	{
		std::cerr << "Empty name" << std::endl;
		return (NULL);
	}
	Zombie *zombie;
	zombie = new Zombie(name);
	return (zombie);
}

void randomChump( std::string name )
{
	if (name.empty())
	{
		std::cerr << "Empty name" << std::endl;
		return ;
	}
	Zombie *zombie;
	zombie = new Zombie(name);
	zombie->announce();
	delete zombie;
}
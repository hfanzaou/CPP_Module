#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public :
		ScavTrap();
		ScavTrap(const std::string &);
		ScavTrap(const ScavTrap &);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &);
		void guardGate();
		void	attack(const std::string &target);
};

#endif
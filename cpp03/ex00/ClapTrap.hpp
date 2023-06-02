#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
private :
	std::string _name;
	int _Hit_Points;
	int _Energy_points;
	int _Attack_damage;
public :
	ClapTrap();
	ClapTrap(const std::string &);
	ClapTrap(const ClapTrap &);
	ClapTrap& operator=(const ClapTrap &);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif

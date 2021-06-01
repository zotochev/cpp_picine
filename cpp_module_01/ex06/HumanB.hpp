#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

#include <iostream>

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon &weapon_);

private:
	std::string	name;
	Weapon		*weapon;
};


#endif

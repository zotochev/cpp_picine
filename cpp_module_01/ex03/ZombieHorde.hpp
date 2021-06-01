//
// Created by Mariam Scot on 5/18/21.
//

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(unsigned N, const std::string& type = "walker");
	~ZombieHorde();

	Zombie		*randomChump();
	void		announce();

private:
	unsigned	N;
	Zombie		**horde;
	std::string	type;
};


#endif

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent(const std::string& type = "walker");
	~ZombieEvent();
	Zombie*		newZombie(const std::string& name);
	Zombie*		randomChump();
	void		setZombieType(const std::string& type_);

private:
	std::string type;
};

#endif

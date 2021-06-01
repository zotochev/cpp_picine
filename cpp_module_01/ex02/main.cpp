#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#include <iostream>
#include <string>

int	main()
{
	Zombie		zombie_00;
	Zombie		zombie_01("Madeline Ashton", "smoker");
	ZombieEvent	event_default;
	ZombieEvent	event_screamer("screamer");
	Zombie*		zombie_10;
	Zombie*		zombie_11;
	Zombie*		zombie_20;
	Zombie*		zombie_21;
	Zombie*		zombie_22;

	std::cout << "~~~~~~~~~~~~~~~" << std::endl;
	zombie_10 = event_default.newZombie("Albert Francis");
	zombie_11 = event_default.randomChump();
	std::cout << "~~~~~~~~~~~~~~~" << std::endl;
	zombie_20 = event_screamer.newZombie("Jonathan Osterman");
	zombie_21 = event_screamer.randomChump();
	event_screamer.setZombieType("whisperer");
	zombie_22 = event_screamer.newZombie("Boston Brand");

	delete zombie_10;
	delete zombie_11;
	delete zombie_20;
	delete zombie_21;
	delete zombie_22;
	return 0;
}